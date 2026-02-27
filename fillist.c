/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillist.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohollar <sohollar@student.42paris.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/06 16:15:09 by sohollar          #+#    #+#             */
/*   Updated: 2026/02/27 11:46:41 by sohollar         ###   ########.fr       */
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

t_node	*ft_newnode(int n)
{
	t_node	*new;

	new = ft_calloc(1, sizeof(t_node));
	if (new == NULL)
		return (NULL);
	new->nb = n;
	return (new);
}

void	ft_listadd_back(t_list *list, t_node *new)
{
	t_node	*cur;

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
}

int	addnb(char *str, t_list *list)
{
	t_node	*new;
	int		nb;

	nb = atoicherry(str);
	new = ft_newnode(nb);
	if (new == NULL)
		return (0);
	ft_listadd_back(list, new);
	return (1);
}

int	fillist(char **argv, t_list *list)
{
	int	i;
	int	j;

	i = 0;
	while (argv[++i])
	{
		j = -1;
		while (argv[i][++j])
		{
			if (! (is_sep(argv[i][j])) && (j == 0 || is_sep(argv[i][j - 1])))
			{
				if (!checklimits(atoicherry(&argv[i][j])))
					return (0);
				if (! addnb(&argv[i][j], list))
					return (0);
			}
		}
	}
	return (1);
}
