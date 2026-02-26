/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   final_push.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohollar <sohollar@student.42paris.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/26 17:56:34 by sohollar          #+#    #+#             */
/*   Updated: 2026/02/26 23:30:57 by sohollar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	move_cheapest_btoa(t_list *a, t_list *b, t_boite *cheap)
{
	if (ft_strncmp(cheap->combi, "ra_rrb", 6) == 0)
		return (ra_rrb(a, b, cheap) + push_a(a, b));
	else if (ft_strncmp(cheap->combi, "rra_rb", 6) == 0)
		return (rra_rb(a, b, cheap) + push_a(a, b));
	else if (ft_strncmp(cheap->combi, "rr_diff", 7) == 0)
		return (rr_diff(a, b, cheap) + push_a(a, b));
	else
		return (rrr_diff(a, b, cheap) + push_a(a, b));
}

static t_node	*target_upper(t_list *a, t_node *node_b)
{
	int		target;
	t_node	*cur;

	cur = a->first;
	if (node_b->indice > a->max || node_b->indice < a->min)
	{
		while (cur->ismin != 1)
			cur = cur->next;
		target = cur->indice;
	}
	else
	{
		target = cur->indice;
		while (cur != NULL)
		{
			if (cur->indice > node_b->indice && cur->indice < target)
				target = cur->indice;
			cur = cur->next;
		}
	}
	return (find_indice(a, target));
}

int	merge_btoa(t_list *a, t_list *b)
{
	t_boite	*boite;
	int		count;

	count = 0;
	boite = init_boite();
	if (boite == NULL)
		return (0);
	while (b->len > 0)
	{
		fill_boite(a, b, b->first, target_upper(a, b->first), boite);
		fill_costs(boite);
		boite->idx = b->first->indice;
		count += move_cheapest_btoa(a, b, boite);
	}
	return (count);
}
