/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minmax.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohollar <sohollar@student.42paris.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/27 14:12:03 by sohollar          #+#    #+#             */
/*   Updated: 2026/02/27 14:17:48 by sohollar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_min(int a, int b)
{
	if (a <= b)
		return (a);
	else
		return (b);
}

int	ft_max(int a, int b)
{
	if (a >= b)
		return (a);
	return (b);
}

static void	change_max(t_list *list, t_node *node)
{
	t_node	*cur;

	cur = list->first;
	while (cur != NULL)
	{
		cur->ismax = 0;
		cur = cur->next;
	}
	node->ismax = 1;
	list->max = node->indice;
}

static void	change_min(t_list *list, t_node *node)
{
	t_node	*cur;

	cur = list->first;
	while (cur != NULL)
	{
		cur->ismin = 0;
		cur = cur->next;
	}
	node->ismin = 1;
	list->min = node->indice;
}

void	apply_minmax(t_list *list)
{
	t_node	*cur;

	list->min = 2147483647;
	list->max = 0;
	if (list->first == NULL)
		return ;
	cur = list->first;
	while (cur != NULL)
	{
		if (cur->indice > list->max)
			change_max(list, cur);
		if (cur->indice < list->min)
			change_min(list, cur);
		cur = cur->next;
	}
}
