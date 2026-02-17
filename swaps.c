/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swaps.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohollar <sohollar@student.42paris.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/16 17:45:39 by sohollar          #+#    #+#             */
/*   Updated: 2026/02/17 22:22:43 by sohollar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_ops(t_list *list)
{
	t_node	*temp;

	temp = list->first->next;
	if (temp->next != NULL)
		temp->next->pre = list->first;
	list->first->next = temp->next;
	temp->next = list->first;
	list->first->pre = temp;
	list->first = temp;
	temp->pre = NULL;
}

void	swap_a(t_list *list)
{
	if (list == NULL || list->first == NULL || list->first->next == NULL)
		;
	else
		swap_ops(list);
	ft_printf_fd(1, "sa\n");
}

void	swap_b(t_list *list)
{
	if (list == NULL || list->first == NULL || list->first->next == NULL)
		;
	else
		swap_ops(list);
	ft_printf_fd(1, "sb\n");
}

void	swap_anb(t_list *a, t_list *b)
{
	if (a == NULL || a->first == NULL || a->first->next == NULL)
		;
	else
		swap_ops(a);
	if (b == NULL || b->first == NULL || b->first->next == NULL)
		;
	else
		swap_ops(b);
	ft_printf_fd(1, "ss\n");
}
