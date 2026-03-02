/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohollar <sohollar@student.42paris.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/25 23:03:21 by sohollar          #+#    #+#             */
/*   Updated: 2026/02/28 16:07:21 by sohollar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*find_indice(t_list *list, int indice)
{
	t_node	*cur;

	if (list->first == NULL)
		return (NULL);
	cur = list->first;
	while (cur->indice != indice)
		cur = cur->next;
	return (cur);
}

static int	minof_four(int a, int b, int c, int d)
{
	int	temp;

	temp = a;
	if (b < temp)
		temp = b;
	if (c < temp)
		temp = c;
	if (d < temp)
		temp = d;
	return (temp);
}

void	fill_boite(t_vabrouter *vache, t_node *na, t_node *nb, t_boite *boite)
{
	boite->ra = na->stack_pos;
	boite->rra = (vache->a->len - na->stack_pos) % vache->a->len;
	boite->rb = nb->stack_pos;
	boite->rrb = (vache->b->len - nb->stack_pos) % vache->b->len;
	boite->rr = ft_min(na->stack_pos, nb->stack_pos);
	boite->rr_diffa = na->stack_pos - boite->rr;
	boite->rr_diffb = nb->stack_pos - boite->rr;
	boite->rrr = ft_min(boite->rra, boite->rrb);
	boite->rrr_diffa = boite->rra - boite->rrr;
	boite->rrr_diffb = boite->rrb - boite->rrr;
}

void	fill_costs(t_boite *boite)
{
	int	a;
	int	b;
	int	c;
	int	d;

	boite->ra_rrb = boite->ra + boite->rrb;
	boite->rra_rb = boite->rra + boite->rb;
	boite->rr_diff = boite->rr + boite->rr_diffa + boite->rr_diffb;
	boite->rrr_diff = boite->rrr + boite->rrr_diffa + boite->rrr_diffb;
	a = boite->ra_rrb;
	b = boite->rra_rb;
	c = boite->rr_diff;
	d = boite->rrr_diff;
	boite->cost = minof_four(a, b, c, d);
	if (boite->cost == a)
		boite->combi = "ra_rrb";
	else if (boite->cost == b)
		boite->combi = "rra_rb";
	else if (boite->cost == c)
		boite->combi = "rr_diff";
	else
		boite->combi = "rrr_diff";
}
