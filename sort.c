/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohollar <sohollar@student.42paris.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/18 19:15:56 by sohollar          #+#    #+#             */
/*   Updated: 2026/02/28 19:27:54 by sohollar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	sort_two(t_list *list)
{
	if (list->first->indice < list->first->next->indice)
		return (0);
	else
		return (swap_a(list), 1);
}

static int	sort_three(t_list *list)
{
	int	a;
	int	b;
	int	c;

	a = list->first->indice;
	b = list->first->next->indice;
	c = list->first->next->next->indice;
	if (a < b && b < c)
		return (0);
	if (a < b && b > c && a < c)
		return (swap_a(list), rotate_a(list), 2);
	if (a > b && b < c && a < c)
		return (swap_a(list), 1);
	if (a < b && b > c && a > c)
		return (rrotate_a(list), 1);
	if (a > b && b < c && a > c)
		return (rotate_a(list), 1);
	return (swap_a(list), rrotate_a(list), 2);
}

static int	petits_cas(t_list *list)
{
	if (list->len == 0 || list->len == 1)
		return (0);
	if (list->len == 2)
		return (sort_two(list));
	else
		return (sort_three(list));
}

static int	small_ontop(t_list *list)
{
	t_node	*small;
	int		count;

	count = 0;
	small = find_indice(list, 0);
	if (small->stack_pos < list->len / 2)
	{
		while (list->first->indice != 0)
			count += rotate_a(list);
	}
	else
	{
		while (list->first->indice != 0)
			count += rrotate_a(list);
	}
	return (count);
}

int	turkish_sort(t_list *a, t_list *b)
{
	t_boite	*cheap;

	if (a->len < 4)
		return (petits_cas(a), 1);
	push_b(b, a);
	if (a->len > 3)
		push_b(b, a);
	cheap = init_boite();
	if (cheap == NULL)
		return (0);
	while (a->len > 3)
	{
		find_cheapest(a, b, cheap);
		move_cheapest_atob(a, b, cheap);
	}
	sort_three(a);
	merge_btoa(a, b);
	return (free(cheap), small_ontop(a), 1);
}
