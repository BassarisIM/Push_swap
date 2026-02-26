/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   indicage.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohollar <sohollar@student.42paris.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/17 22:56:33 by sohollar          #+#    #+#             */
/*   Updated: 2026/02/26 23:02:12 by sohollar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* int	iseven(int nb)
{
	if (nb % 2 == 0)
		return (1);
	return (0);
} */

static void	tri_n_indices(t_list *list)
{
	t_node	*base;
	t_node	*compare;
	int		ntemp;

	base = list->first;
	base->indice = 0;
	while (base->next != NULL)
	{
		compare = base->next;
		while (compare != NULL)
		{
			if (compare->nb < base->nb)
			{
				ntemp = base->nb;
				base->nb = compare->nb;
				compare->nb = ntemp;
			}
			compare = compare->next;
		}
		base = base->next;
		base->indice = base->pre->indice + 1;
	}
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

void	apply_stack_pos(t_list *list)
{
	t_node	*cur;

	if (list == NULL || list->first == NULL)
		return ;
	if (list->first->next == NULL)
	{
		cur = list->first;
		cur->stack_pos = 0;
		return ;
	}
	cur = list->first;
	cur->stack_pos = 0;
	while (cur->next != NULL)
	{
		cur = cur->next;
		cur->stack_pos = cur->pre->stack_pos + 1;
	}
}
/* void	apply_depth(t_list *list)
{
	t_node	*cur;

	if (list == NULL || list->first == NULL)
		return ;
	cur = list->first;
	while (cur != NULL)
	{
		if (cur->stack_pos == (list->len / 2) && list->len % 2 == 1)
			cur->depth = 0;
		else if (cur->stack_pos < list->len / 2)
			cur->depth = 1;
		else
			cur->depth = -1;
		cur = cur->next;
	}
} */

static void	report_indices(t_list *list, t_list *temp)
{
	t_node	*cur_list;
	t_node	*cur_temp;

	cur_list = list->first;
	while (cur_list != NULL)
	{
		cur_temp = temp->first;
		while (cur_temp->nb != cur_list->nb)
			cur_temp = cur_temp->next;
		cur_list->indice = cur_temp->indice;
		cur_list = cur_list->next;
	}
}

int	indicage(t_list *list)
{
	t_list	*temp;
	t_node	*base;
	t_node	*compare;

	if (list == NULL || list->first == NULL)
		return (0);
	temp = ft_newlist();
	if (temp == NULL)
		return (0);
	base = list->first;
	while (base != NULL)
	{
		compare = ft_newnode(&(base->nb));
		if (compare == NULL)
			return (ft_freelist(temp), 0);
		compare->nb = base->nb;
		ft_listadd_back(temp, compare);
		base = base->next;
	}
	tri_n_indices(temp);
	report_indices(list, temp);
	ft_freelist(temp);
	return (apply_minmax(list), apply_stack_pos(list), 1);
}
