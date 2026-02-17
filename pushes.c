/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushes.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohollar <sohollar@student.42paris.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/16 18:13:04 by sohollar          #+#    #+#             */
/*   Updated: 2026/02/17 22:21:03 by sohollar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_a(t_list *a, t_list *b)
{
	if (b == NULL || a == NULL || b->first == NULL)
		;
	else
	{
		if (a->first == NULL)
		{
			a->first = b->first;
			a->first->pre = NULL;
			b->first = b->first->next;
			a->first->next = NULL;
		}
		else
		{
			a->first->pre = b->first;
			b->first = b->first->next;
			a->first->pre->next = a->first;
			a->first = a->first->pre;
		}
		if (b->first != NULL)
				b->first->pre = NULL;
	}
	ft_printf_fd(1, "pa\n");
}

void	push_b(t_list *a, t_list *b)
{
	if (b == NULL || a == NULL || a->first == NULL)
		;
	else
	{
		if (b->first == NULL)
		{
			b->first = a->first;
			b->first->pre = NULL;
			a->first = a->first->next;
			b->first->next = NULL;
		}
		else
		{
			b->first->pre = a->first;
			a->first = a->first->next;
			b->first->pre->next = b->first;
			b->first = b->first->pre;
		}
		if (a->first != NULL)
				a->first->pre = NULL;
	}
	ft_printf_fd(1, "pb\n");
}
