/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculs.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohollar <sohollar@student.42paris.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/25 22:19:01 by sohollar          #+#    #+#             */
/*   Updated: 2026/02/27 16:34:43 by sohollar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_boite	*init_boite(void)
{
	t_boite	*boite;

	boite = ft_calloc(1, sizeof(t_boite));
	if (boite == NULL)
		return (NULL);
	return (boite);
}

static t_node	*target(t_list *b, t_node *node)
{
	t_node	*cur;
	int		temp;

	cur = b->first;
	if (node->indice > b->max || node->indice < b->min)
	{
		while (cur->ismax != 1)
			cur = cur->next;
		temp = cur->indice;
	}
	else
	{
		while (cur->indice > node->indice)
			cur = cur->next;
		temp = cur->indice;
		cur = b->first;
		while (cur != NULL)
		{
			if (cur->indice < node->indice && cur->indice > temp)
				temp = cur->indice;
			cur = cur->next;
		}
	}
	return (find_indice(b, temp));
}

static void	cost(t_list *a, t_list *b, t_node *node, t_boite *boite)
{
	t_node		*inf;
	t_vabrouter	vache;

	vache.a = a;
	vache.b = b;
	inf = target(b, node);
	fill_boite(&vache, node, inf, boite);
	fill_boiter(&vache, node, inf, boite);
	fill_costs(boite);
}

void	find_cheapest(t_list *a, t_list *b, t_boite *cheap)
{
	t_boite	temp;
	t_node	*cur;

	cur = a->first;
	cost(a, b, cur, cheap);
	while (cur != NULL)
	{
		ft_memset(&temp, 0, sizeof(t_boite));
		cost(a, b, cur, &temp);
		if (temp.cost < cheap->cost)
			*cheap = temp;
		cur = cur->next;
	}
}

int	move_cheapest_atob(t_list *a, t_list *b, t_boite *cheap)
{
	if (ft_strncmp(cheap->combi, "ra_rrb", 6) == 0)
		return (ra_rrb(a, b, cheap) + push_b(b, a));
	else if (ft_strncmp(cheap->combi, "rra_rb", 6) == 0)
		return (rra_rb(a, b, cheap) + push_b(b, a));
	else if (ft_strncmp(cheap->combi, "rr_diff", 7) == 0)
		return (rr_diff(a, b, cheap) + push_b(b, a));
	else
		return (rrr_diff(a, b, cheap) + push_b(b, a));
}
