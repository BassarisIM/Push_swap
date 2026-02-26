/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculs.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohollar <sohollar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/25 22:19:01 by sohollar          #+#    #+#             */
/*   Updated: 2026/02/25 23:15:10 by sohollar         ###   ########.fr       */
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

t_node	*target(t_list *a, t_list *b, t_node *node)
{
	t_node	*cur;
	int		temp;

	cur = b->first;
	if (node->indice > b->max || node->indice < b->min)
	{
		while (cur->ismax != 1)
			cur = cur->next;
	}
	else
	{
		temp = cur->indice;
		while (cur != NULL)
		{
			if (cur->indice > temp && cur->indice < node->indice)
				temp = cur->indice;
			cur = cur->next;
		}
	}
	return (find_indice(list, temp));
}

t_boite	*cost(t_list *a, t_list *b, t_node *node)
{
	t_node	*inf;
	t_boite	*boite;

	inf = target(a, b, node);
	boite->rr_diff = 
}

t_boite	*find_cheapest(t_list *a, t_list *b, t_boite *cheap)
{
	t_boite	*temp;
	t_node	*cur;

	cur = list->first;
	cheap = cost(cur);
	while (cur != NULL)
	{
		temp = cost(a, b, cur);
		if (temp->cost < cheap->cost)
			cheap = temp;
		cur = cur->next;
	}
}

int	move_cheapest(t_list *a, t_list *b, t_boite cheap)
{
	
}
