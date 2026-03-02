*This project has been created as part of the 42 curriculum by sohollar.*

## Description :
Ce projet consiste a implementer un algorithme, qui, grace a un nombre limite d'operation sur des listes de nombre, parvient a trier une premiere pile de nombre en un nombre limite d'operations, et en utilisant une deuxieme pile de stockage.

Les operations possibles sont :
pa / b : met le premier element d'une pile sur le dessus de l'autre
sa / sb : intervertit les deux premiers elements d'une pile
ra / rb : prend le premier element d'une pile et le met en dernier de cette meme pile.
rra / rrb : c'est l'inverse, prend le dernier element et le met sur le dessus de la pile.
rr : realise ra et rb en meme temps
rrr : realise rra et rrb en meme temps.

Retours specifiques :
- rien, retour au prompt, si : pas d'arguments.
- Erreur si : liste non conforme (carateres non valides (non entiers ou non separateurs), arguments vides ou uniquement consistues de separateurs, doublons, nombres sortant des limites du type "int")

## Instructions :
executer le programme ainsi :
./push_swap [ARGUMENTS]
pour entrer une liste aleatoire de nombres, on peut par exemple utiliser la commande donnant les bornes et la taille d'un tableau :
./push_swap $(shuf -i 0-1000 -n 500)

## Ressources :

### Sites web :
	https://medium.com/@ayogun/push-swap-c1f5d2d41e97
	https://fr.wikipedia.org/wiki/Algorithme_de_tri
	https://en.wikipedia.org/wiki/Mechanical_Turk
	https://fr.wikipedia.org/wiki/Tri_par_base

### IA :
Chatgpt pour m'aider a resoudre des problemes auxquels je n'ai pas trouve d'explication toute seule.

## Description de l'algorithme utilise :
J'ai choisi l'algorithme "turc", qui consiste a :
- commencer par pousser 2 elements de a vers b
- puis continuer a remplir b en choisissant les elements les moins couteux en operations pour les ranger dans b dans l'ordre decroissant, jusqu'a ce qu'il ne reste plus que 3 elements dans a
- trier les trois elements restants de a
- pousser les elements de b dans l'autre sens au bon endroit dans la pile a.
- faire pivoter a jusqu'a ce que son plus petit element se trouve en haut de la pile.

