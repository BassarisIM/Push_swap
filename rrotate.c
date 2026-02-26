/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rrotate.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohollar <sohollar@student.42paris.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/12 17:01:32 by sohollar          #+#    #+#             */
/*   Updated: 2026/02/25 21:57:00 by sohollar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rrotate_ops(t_list *list)
{
	t_node	*cur;

	if (list == NULL || list->first == NULL || list->first->next == NULL)
		return ;
	cur = list->first;
	while (cur->next != NULL)
		cur = cur->next;
	cur->next = list->first;
	cur->pre->next = NULL;
	cur->pre = NULL;
	list->first->pre = cur;
	list->first = cur;
	apply_depth(list);
	apply_stack_pos(list);
}

int	rrotate_a(t_list *a)
{
	rrotate_ops(a);
	ft_printf_fd(1, "rra\n");
	return (1);
}

int	rrotate_b(t_list *b)
{
	rrotate_ops(b);
	ft_printf_fd(1, "rrb\n");
	return (1);
}

int	rrotate_anb(t_list *a, t_list *b)
{
	rrotate_ops(a);
	rrotate_ops(b);
	ft_printf_fd(1, "rrr\n");
	return (1);
}
