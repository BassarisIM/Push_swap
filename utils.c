/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohollar <sohollar@student.42paris.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/25 23:03:21 by sohollar          #+#    #+#             */
/*   Updated: 2026/02/26 19:28:08 by sohollar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*find_indice(t_list *list, int indice)
{
	t_node	*cur;

	if (list == NULL || list->first == NULL)
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
	else
		return (temp);
	return (temp);
}

static int	va(int nb)
{
	if (nb >= 0)
		return (nb);
	else
		return (-nb);
}

void	fill_boite(t_list *a, t_list *b, t_node *na, t_node *nb, t_boite *boite)
{
	boite->ra = na->indice;
	boite->rra = a->len - na->indice;
	boite->rb = nb->indice;
	boite->rrb = b->len - nb->indice;
	boite->rr = min(na->indice, nb->indice);
	if (na->indice - nb->indice >= 0)
	{
		boite->rr_diffa = na->indice - nb->indice;
		boite->rr_diffb = 0;
	}
	else
	{
		boite->rr_diffa = 0;
		boite->rr_diffb = nb->indice - na->indice;
	}
	boite->rrr = min(a->len - na->indice, b->len - nb->indice);
	if ((a->len - na->indice) - (b->len - nb->indice) >= 0)
	{
		boite->rrr_diffa = (a->len - na->indice) - (b->len - nb->indice);
		boite->rrr_diffb = 0;
	}
	else
	{
		boite->rrr_diffa = 0;
		boite->rrr_diffb = (b->len - nb->indice) - (a->len - na->indice);
	}
}

void	fill_costs(t_list *a, t_list *b, t_node *na, t_node *nb, t_boite *boite)
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
	if (minof_four == a)
		boite->combi = "ra_rrb";
	if (minof_four == b)
		boite->combi = "rra_rb";
	if (minof_four == c)
		boite->combi = "rr_diff";
	else
		boite->combi = "rrr_diff";
}
