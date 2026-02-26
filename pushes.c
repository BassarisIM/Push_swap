/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushes.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohollar <sohollar@student.42paris.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/16 18:13:04 by sohollar          #+#    #+#             */
/*   Updated: 2026/02/26 22:38:39 by sohollar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	push_toempty(t_list *a, t_list *b)
{
	a->first = b->first;
	a->first->pre = NULL;
	b->first = b->first->next;
	a->first->next = NULL;
	apply_stack_pos(a);
	apply_stack_pos(b);
	apply_minmax(a);
	apply_minmax(b);
}

static void	push_tonotempty(t_list *a, t_list *b)
{
	a->first->pre = b->first;
	b->first = b->first->next;
	a->first->pre->next = a->first;
	a->first = a->first->pre;
	a->first->stack_pos = 0;
	apply_stack_pos(a);
	apply_stack_pos(b);
	apply_minmax(a);
	apply_minmax(b);
}

int	push_a(t_list *a, t_list *b)
{
	if (b == NULL || a == NULL || b->first == NULL)
		;
	else
	{
		a->len++;
		b->len--;
		if (a->first == NULL)
			push_toempty(a, b);
		else
			push_tonotempty(a, b);
		if (b->first != NULL)
				b->first->pre = NULL;
	}
	ft_printf_fd(1, "pa\n");
	return (1);
}

int	push_b(t_list *b, t_list *a)
{
	if (b == NULL || a == NULL || a->first == NULL)
		;
	else
	{
		b->len++;
		a->len--;
		if (b->first == NULL)
			push_toempty(b, a);
		else
			push_tonotempty(b, a);
		if (a->first != NULL)
			a->first->pre = NULL;
	}
	ft_printf_fd(1, "pb\n");
	return (1);
}
