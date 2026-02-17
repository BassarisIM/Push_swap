/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillist.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohollar <sohollar@student.42paris.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/06 16:15:09 by sohollar          #+#    #+#             */
/*   Updated: 2026/02/17 22:39:19 by sohollar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*ft_newlist(void)
{
	t_list	*list;

	list = ft_calloc(1, sizeof(t_list));
	if (list == NULL)
		return (NULL);
	return (list);
}

t_node	*ft_newnode(int *n)
{
	t_node	*new;

	new = ft_calloc(1, sizeof(t_node));
	if (new == NULL)
		return (NULL);
	new->nb = *n;
	return (new);
}

int	ft_listadd_back(t_list *list, t_node *new)
{
	t_node	*cur;

	if (list == NULL)
		return (0);
	if (list->first == NULL)
		list->first = new;
	else
	{
		cur = list->first;
		while (cur->next != NULL)
			cur = cur->next;
		cur->next = new;
		cur->next->pre = cur;
	}
	list->len++;
	return (1);
}

int	addnb(char *str, t_list *list)
{
	t_node	*new;
	int		nb;

	nb = atoicherry(str);
	ft_printf_fd(1, str);
	ft_printf_fd(1, "\n");
	new = ft_newnode(&nb);
	if (new == NULL)
		return (0);
	if (ft_listadd_back(list, new) == 0)
		return (0);
	return (1);
}

int	fillist(char **argv, t_list *list)
{
	int	i;
	int	j;
	int	reussi;

	i = 1;
	while (argv[i])
	{
		j = 0;
		while (argv[i][j])
		{
			if (! (is_sep(argv[i][j])) && (j == 0 || is_sep(argv[i][j - 1])))
			{
				if (checklimits(atoicherry(&argv[i][j])))
				{
					reussi = addnb(&argv[i][j], list);
					if (!reussi)
						return (0);
				}
				else
					return (0);
			}
			j++;
		}
		i++;
	}
	return (1);
}
