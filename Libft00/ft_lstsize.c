/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohollar <sohollar@student.42paris.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 22:57:00 by sohollar          #+#    #+#             */
/*   Updated: 2026/02/11 19:53:29 by sohollar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//#include <stdio.h>

int	ft_lstsize(t_libftlist *lst)
{
	int		nb;

	nb = 0;
	if (lst == NULL)
		return (0);
	else
	{
		nb++;
		while (lst->next != NULL)
		{
			nb ++;
			lst = lst->next;
		}
	}
	return (nb);
}
