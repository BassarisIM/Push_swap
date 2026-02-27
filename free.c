/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohollar <sohollar@student.42paris.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/27 14:27:36 by sohollar          #+#    #+#             */
/*   Updated: 2026/02/27 14:27:48 by sohollar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_freenodes(t_list	*list)
{
	t_node	*a;
	t_node	*b;

	if (list->first == NULL)
		return ;
	a = list->first;
	b = a->next;
	while (b != NULL)
	{
		a->next = NULL;
		a->pre = NULL;
		free(a);
		a = b;
		b = a->next;
	}
	a->next = NULL;
	a->pre = NULL;
	free(a);
	free(b);
}

void	ft_freelist(t_list *list)
{
	ft_freenodes(list);
	free(list);
}

void	free_anb(t_list *a, t_list *b)
{
	ft_freelist(a);
	ft_freelist(b);
}
