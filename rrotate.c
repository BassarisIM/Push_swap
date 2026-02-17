/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rrotate.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohollar <sohollar@student.42paris.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/12 17:01:32 by sohollar          #+#    #+#             */
/*   Updated: 2026/02/17 22:22:05 by sohollar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rrotate_ops(t_list *list)
{
	t_node	*cur;

	cur = list->first;
	while (cur->next != NULL)
		cur = cur->next;
	cur->next = list->first;
	cur->pre->next = NULL;
	cur->pre = NULL;
	list->first->pre = cur;
	list->first = cur;
}

void	rrotate_a(t_list *a)
{
	if (a == NULL || a->first == NULL || a->first->next == NULL)
		;
	else
		rrotate_ops(a);
	ft_printf_fd(1, "rra\n");
}

void	rrotate_b(t_list *b)
{
	if (b == NULL || b->first == NULL || b->first->next == NULL)
		;
	else
		rrotate_ops(b);
	ft_printf_fd(1, "rrb\n");
}

void	rrotate_anb(t_list *a, t_list *b)
{
	if (a == NULL || a->first == NULL || a->first->next == NULL)
		;
	rrotate_ops(a);
	if (b == NULL || b->first == NULL || b->first->next == NULL)
		;
	else
		rrotate_ops(b);
	ft_printf_fd(1, "rrr\n");
}
