/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohollar <sohollar@student.42paris.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/18 19:15:56 by sohollar          #+#    #+#             */
/*   Updated: 2026/02/25 23:15:50 by sohollar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*static int	full_pushb(t_list *a, t_list *b, int nb_ops)
{
	while (a->len > 0)
	{
		push_b(b, a);
		nb_ops++;
	}
	return (nb_ops);
}

static int	find_biggest(t_list *list)
{
	t_node	*cur;

	cur = list->first;
	while (cur->indice != (list->len) - 1)
		cur = cur->next;
	return (cur->indice);
}

static int	put_on_top(t_list *list, int i, int nb_ops)
{
	while (list->first->indice != i)
	{
		rotate_b(list);
		nb_ops++;
	}
	return (nb_ops);
}

int	sort_simple(t_list *a, t_list *b, int nb_ops)
{
	nb_ops = full_pushb(a, b, nb_ops);
	while (b->len > 0)
	{
		nb_ops = put_on_top(b, find_biggest(b), nb_ops);
		push_a(a, b);
		nb_ops++;
	}
	return (nb_ops);
}*/

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
	else
		return (swap_a(list), rrotate_a(list), 2);
}

static int	petits_cas(t_list *list)
{
	if (a->len == 0 || a->len == 1)
		return (0);
	if (a->len == 2)
		return (sort_two(a));
	else
		return (sort_three(a));
}

int	small_ontop(t_list *list)
{
	int		small;
	t_node	*small;

	small = find_indice(list, 0);
	if (small->stack_pos < a->len / 2)
	{
		while (a->first->indice != 0)
			nb_ops += rotate_a(a);
	}
	else
	{
		while (a->first->indice != 0)
			nb_ops += rrotate_a(a);
	}
	return (nb_ops);
}

int	turkish_sort(t_list *a, t_list *b, int nb_ops)
{
	t_boite	*cheap;

	if (a->len < 4)
		return (nb_ops += petits_cas(a));
	nb_ops += push_b(b, a);
	if (a->len > 3)
		nb_ops += push_b(b, a);
	cheap = init_boite(void);
	if (cheap == NULL)
		return (0);
	while (a->len > 3)
	{
		cheap = find_cheapest(a, b, cheap);
		nb_ops += move_cheapest(a, b, cheap);
	}
	nb_ops += sort_three(a);
	while (b->len != 0)
		nb_ops += merge_btoa(a, b);
	nb_ops += small_ontop(a);
	return (nb_ops);
}
