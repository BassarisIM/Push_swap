/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swaps.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohollar <sohollar@student.42paris.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/16 17:45:39 by sohollar          #+#    #+#             */
/*   Updated: 2026/02/26 22:38:59 by sohollar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	swap_ops(t_list *list)
{
	t_node	*temp;

	if (list == NULL || list->first == NULL || list->first->next == NULL)
		return ;
	temp = list->first->next;
	if (temp->next != NULL)
		temp->next->pre = list->first;
	list->first->next = temp->next;
	temp->next = list->first;
	list->first->pre = temp;
	list->first = temp;
	temp->pre = NULL;
	apply_stack_pos(list);
}

int	swap_a(t_list *list)
{
	swap_ops(list);
	ft_printf_fd(1, "sa\n");
	return (1);
}

int	swap_b(t_list *list)
{
	swap_ops(list);
	ft_printf_fd(1, "sb\n");
	return (1);
}

int	swap_anb(t_list *a, t_list *b)
{
	swap_ops(a);
	swap_ops(b);
	ft_printf_fd(1, "ss\n");
	return (1);
}
