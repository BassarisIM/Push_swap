/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohollar <sohollar@student.42paris.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 23:15:39 by sohollar          #+#    #+#             */
/*   Updated: 2026/02/11 19:53:55 by sohollar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>
#include "libft.h"

t_libftlist	*ft_lstlast(t_libftlist *lst)
{
	if (lst == NULL)
		return (0);
	else
	{
		while (lst->next != NULL)
			lst = lst->next;
	}
	return (lst);
}
