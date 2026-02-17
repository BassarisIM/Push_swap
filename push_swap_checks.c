/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_checks.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohollar <sohollar@student.42paris.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/06 15:42:33 by sohollar          #+#    #+#             */
/*   Updated: 2026/02/11 19:59:38 by sohollar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	checklimits(long nb)
{
	if (nb >= -2147483648 && nb <= 2147483647)
		return (1);
	return (0);
}

int	doublons(t_list *list)
{
	t_node	*cur;
	t_node	*base;

	base = list->first;
	while (base->next != NULL)
	{
		cur = base->next;
		while (cur != NULL)
		{
			if (base->nb == cur->nb)
				return (0);
			cur = cur->next;
		}
		base = base->next;
	}
	return (1);
}

int	is_sep(char c)
{
	if (c == ' ' || c == '	')
		return (1);
	return (0);
}

int	isok(char **argv, int i, int j)
{
	if (is_sep(argv[i][j]) || ft_isdigit(argv[i][j]))
		return (1);
	if (argv[i][j] == '-')
	{
		if (j == 0)
		{
			if (ft_isdigit(argv[i][1]))
				return (1);
		}
		else
		{
			if (is_sep(argv[i][j - 1]) && (ft_isdigit(argv[i][j + 1])))
				return (1);
		}
	}
	return (0);
}

int	checknb(char **argv)
{
	int	i;
	int	j;

	i = 1;
	while (argv[i])
	{
		j = 0;
		while (argv[i][j])
		{
			if (isok(argv, i, j))
				j++;
			else
				return (0);
		}
		i++;
	}
	return (1);
}
