/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   indicage.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohollar <sohollar@student.42paris.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/17 22:56:33 by sohollar          #+#    #+#             */
/*   Updated: 2026/02/28 18:50:44 by sohollar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* int	iseven(int nb)
{
	if (nb % 2 == 0)
		return (1);
	return (0);
} */

static void	tri_n_indices(t_list *list)
{
	t_node	*base;
	t_node	*compare;
	int		ntemp;

	base = list->first;
	base->indice = 0;
	while (base->next != NULL)
	{
		compare = base->next;
		while (compare != NULL)
		{
			if (compare->nb < base->nb)
			{
				ntemp = base->nb;
				base->nb = compare->nb;
				compare->nb = ntemp;
			}
			compare = compare->next;
		}
		base = base->next;
		base->indice = base->pre->indice + 1;
	}
}

static void	report_indices(t_list *list, t_list *temp)
{
	t_node	*cur_list;
	t_node	*cur_temp;

	cur_list = list->first;
	while (cur_list != NULL)
	{
		cur_temp = temp->first;
		while (cur_temp->nb != cur_list->nb)
			cur_temp = cur_temp->next;
		cur_list->indice = cur_temp->indice;
		cur_list = cur_list->next;
	}
}

void	apply_stack_pos(t_list *list)
{
	t_node	*cur;
	int		p;

	p = 0;
	cur = list->first;
	while (cur != NULL)
	{
		cur->stack_pos = p++;
		cur = cur->next;
	}
}

int	indicage(t_list *list)
{
	t_list	*temp;
	t_node	*base;
	t_node	*compare;

	if (list->first == NULL)
		return (1);
	temp = ft_newlist();
	if (temp == NULL)
		return (0);
	base = list->first;
	while (base != NULL)
	{
		compare = ft_newnode(base->nb);
		if (compare == NULL)
			return (ft_freelist(temp), 0);
		compare->nb = base->nb;
		ft_listadd_back(temp, compare);
		base = base->next;
	}
	tri_n_indices(temp);
	report_indices(list, temp);
	ft_freelist(temp);
	return (apply_minmax(list), apply_stack_pos(list), 1);
}
