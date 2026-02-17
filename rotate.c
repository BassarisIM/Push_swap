/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohollar <sohollar@student.42paris.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/12 17:16:58 by sohollar          #+#    #+#             */
/*   Updated: 2026/02/17 22:21:38 by sohollar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_ops(t_list *list)
{
	t_node	*cur;

	cur = list->first;
	while (cur->next != NULL)
		cur = cur->next;
	cur->next = list->first;
	list->first->pre = cur;
	list->first->next->pre = NULL;
	list->first = list->first->next;
	cur->next->next = NULL;
}

void	rotate_a(t_list *a)
{
	if (a->first == NULL || a->first->next == NULL)
		;
	else
		rotate_ops(a);
	ft_printf_fd(1, "ra\n");
}

void	rotate_b(t_list *b)
{
	if (b->first == NULL || b->first->next == NULL)
		;
	else
		rotate_ops(b);
	ft_printf_fd(1, "rb\n");
}

void	rotate_anb(t_list *a, t_list *b)
{
	if (a->first == NULL || a->first->next == NULL)
		;
	else
		rotate_ops(a);
	if (b->first == NULL || b->first->next == NULL)
		;
	else
		rotate_ops(b);
	ft_printf_fd(1, "rr\n");
}
