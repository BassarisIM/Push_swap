#!/bin/bash

BIN=./push_swap
RED="\033[31m"
GREEN="\033[32m"
NC="\033[0m"

VG="valgrind --leak-check=full --show-leak-kinds=all --error-exitcode=42"
CHECKER=./checker_linux

error_tests=(
    "1 2 a"
    "1 2 2"
    "2147483648"
    "-2147483649"
    "999999999999"
    "++1"
    "--1"
    "+-1"
)

echo " push_swap – error tests"
echo "-------------------------"

for t in "${error_tests[@]}"; do
    echo -n "Test: $BIN \"$t\" -> "
    output=$(eval $BIN \"$t\" 2>&1)
    if [[ "$output" == "Error" ]]; then
        echo -e "${GREEN}OK${NC}"
    else
        echo -e "${RED}FAIL${NC} | Output: [$output]"
    fi
done

echo
echo " empty / no-operation / sorted tests"
echo "---------------------"
#test sans espace a la fin
generate_range() {
    local start=$1
    local end=$2
    seq "$start" "$end" | xargs
}
#test avec espace a la fin
# generate_range() {
#     local start=$1
#     local end=$2
#     seq "$start" "$end" | tr '\n' ' '
# }

noop_tests=(
    ""
    "   "
    "1"
    "1 2 3"
    "1 2 3 4 5"
    "-3 -2 -1"
    "-5 -4 -3 -2 -1"
    "$(generate_range 1 100)"
    "$(generate_range 1 500)"
    "$(generate_range -100 0)"
    "$(generate_range -500 0)"
)

for t in "${noop_tests[@]}"; do
    echo -n "Test: $BIN [range size: $(wc -w <<< "$t")] -> "

    output=$("$BIN" "$t" 2>&1)
    cleaned_output=$(echo "$output" | tr -d '\n')

    if [[ -z "$cleaned_output" ]]; then
        echo -e "${GREEN}OK${NC}"
    else
        echo -e "${RED}FAIL${NC} | Output: [$output]"
    fi
done


echo
echo "🧪 int limits – valid cases"
echo "--------------------------"

valid_int_tests=(
    "-2147483648"
    "2147483647"
    "-2147483648 0 2147483647"
)

for t in "${valid_int_tests[@]}"; do
    echo -n "Test: $BIN \"$t\" -> "
    output=$(eval $BIN \"$t\" 2>&1)
    if [[ "$output" != "Error" ]]; then
        echo -e "${GREEN}OK${NC}"
    else
        echo -e "${RED}FAIL${NC} | Output: [$output]"
    fi
done

echo
echo "🧪 int limits – invalid cases"
echo "----------------------------"

invalid_int_tests=(
    "-2147483649"
    "2147483648"
    "-2147483649 0"
    "0 2147483648"
)

for t in "${invalid_int_tests[@]}"; do
    echo -n "Test: $BIN \"$t\" -> "
    output=$(eval $BIN \"$t\" 2>&1)
    if [[ "$output" == "Error" ]]; then
        echo -e "${GREEN}OK${NC}"
    else
        echo -e "${RED}FAIL${NC} | Output: [$output]"
    fi
done




#!/bin/bash

# Assure-toi que BIN et generate_range sont définis
BIN="./push_swap"
VG="valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes --error-exitcode=42"

echo "🧠 Memory leak test – push_swap"
echo "==============================="

tests=(
    "3 2 1" "2 1" "1" "" "\"\"" "\"   \"" "1 2 a" "1 2 2"
    "2147483648" "-2147483649" "-2147483649" "2147483648"
    "-2147483649 0" "0 2147483648" "-2147483648" "2147483647"
    "-2147483648 0 2147483647" "   " "1" "1 2 3" "1 2 3 4 5"
    "-3 -2 -1" "-5 -4 -3 -2 -1"
    "$(generate_range 1 100)" "$(generate_range 1 500)"
    "$(generate_range -100 0)" "$(generate_range -500 0)"
    "1 2 a" "1 2 2" "2147483648" "-2147483649" "999999999999"
    "++1" "--1" "+-1"
)

for t in "${tests[@]}"; do
    echo -e "\n🧪 Test: $BIN $t"

    # On capture la sortie complète
    # eval est utilisé pour gérer correctement les arguments vides ou complexes
    output=$(eval "$VG $BIN $t" 2>&1)
    exit_status=$?

    # Extraction des infos de fuites
    # On regarde "definitely lost" (le plus grave) et "still reachable"
    definitely=$(echo "$output" | grep "definitely lost:" | awk '{print $4}' | tr -d ',')
    reachable=$(echo "$output" | grep "still reachable:" | awk '{print $4}' | tr -d ',')
    
    definitely=${definitely:-0}
    reachable=${reachable:-0}

    if [ "$exit_status" -eq 42 ] || [ "$definitely" -gt 0 ] || [ "$reachable" -gt 0 ]; then
        echo -e "❌ FUITE OU ERREUR DÉTECTÉE"
        echo "---------------------------------------------------"
        # On affiche le rapport complet de Valgrind ici
        echo "$output"
        echo "---------------------------------------------------"
    else
        echo -e "✅ Clean (Def: ${definitely}B | Reach: ${reachable}B)"
        # On affiche juste la ligne de résumé pour confirmer
        echo "$output" | grep "ERROR SUMMARY"
    fi
done



echo
echo "🔥 Stress test (500 numbers)"
ARG=$(shuf -i 0-10000 -n 500 | tr '\n' ' ')
$VG $BIN $ARG > /dev/null
if [ $? -eq 0 ]; then
    echo "✅ No leaks (stress)"
else
    echo "❌ Leak detected (stress)"
fi



bench() {
    local SIZE=$1
    local RUNS=1000
    local RANGE=2000

    local TOTAL=0
    local MIN=9999999
    local MAX=0
    local KO=0

    echo "                                                          🚀 Bench $SIZE numbers ($RUNS runs)"
    echo "----------------------------------"

    for ((i=1; i<=RUNS; i++)); do
        ARG=$(shuf -i 0-$RANGE -n $SIZE | awk '{print $1 - 1000}' | xargs)
        OPS=$($BIN $ARG)
        COUNT=$(echo "$OPS" | wc -l)

        RESULT=$(echo "$OPS" | $CHECKER $ARG)

        if [[ "$RESULT" != "OK" ]]; then
            KO=$((KO + 1))
        fi

        TOTAL=$((TOTAL + COUNT))
        (( COUNT < MIN )) && MIN=$COUNT
        (( COUNT > MAX )) && MAX=$COUNT
    done

    AVG=$((TOTAL / RUNS))

    echo "✔ KO count : $KO"
    echo "📉 Min     : $MIN"
    echo "📊 Avg     : $AVG"
    echo "                                                                          📈 Max     : $MAX"
    echo
}

bench 100
bench 500
