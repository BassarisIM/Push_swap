/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   affichages.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohollar <sohollar@student.42paris.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/18 19:07:42 by sohollar          #+#    #+#             */
/*   Updated: 2026/02/27 14:25:37 by sohollar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_list_ar(t_list *list)
{
	t_node	*test;

	if (list->first == NULL)
	{
		ft_printf_fd(1, "\n");
		return ;
	}
	test = list->first;
	ft_printf_fd(1, "idx:%d, max:%d, min:%d, pos:%d, nb:%d\n",
		test->indice,
		test->ismax,
		test->ismin,
		test->stack_pos,
		test->nb);
	while (test->next != NULL)
	{
		test = test->next;
		ft_printf_fd(1, "idx:%d, max:%d, min:%d, pos:%d, nb:%d\n",
			test->indice,
			test->ismax,
			test->ismin,
			test->stack_pos,
			test->nb);
	}
	ft_printf_fd(1, "\n");
	ft_printf_fd(1, "len:%d, listmin:%d, listmax:%d\n",
		list->len, list->min, list->max);
}

/* void	print_indices_ar(t_list *list)
{
	t_node	*test;

	if (list == NULL)
		return ;
	if (list->first == NULL)
	{
		ft_printf_fd(1, "\n");
		return ;
	}
	test = list->first;
	ft_printf_fd(1, "%d ", test->indice);
	while (test->next != NULL)
	{
		test = test->next;
		ft_printf_fd(1, "%d ", test->indice);
	}
	ft_printf_fd(1, "\n");
	while (test != NULL)
	{
		ft_printf_fd(1, "%d ", test->indice);
		test = test->pre;
	}
	ft_printf_fd(1, "\n");
} */
