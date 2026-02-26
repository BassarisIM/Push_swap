/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohollar <sohollar@student.42paris.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/12 17:16:58 by sohollar          #+#    #+#             */
/*   Updated: 2026/02/26 22:38:46 by sohollar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rotate_ops(t_list *list)
{
	t_node	*cur;

	if (list->first == NULL || list->first->next == NULL)
		return ;
	cur = list->first;
	while (cur->next != NULL)
		cur = cur->next;
	cur->next = list->first;
	list->first->pre = cur;
	list->first->next->pre = NULL;
	list->first = list->first->next;
	cur->next->next = NULL;
	apply_stack_pos(list);
}

int	rotate_a(t_list *a)
{
	rotate_ops(a);
	ft_printf_fd(1, "ra\n");
	return (1);
}

int	rotate_b(t_list *b)
{
	rotate_ops(b);
	ft_printf_fd(1, "rb\n");
	return (1);
}

int	rotate_anb(t_list *a, t_list *b)
{
	rotate_ops(a);
	rotate_ops(b);
	ft_printf_fd(1, "rr\n");
	return (1);
}
