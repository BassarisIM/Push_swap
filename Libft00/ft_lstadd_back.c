/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohollar <sohollar@student.42paris.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/05 12:56:07 by sohollar          #+#    #+#             */
/*   Updated: 2026/02/11 19:56:56 by sohollar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//#include <stdio.h>
//#include<stdlib.h>

void	ft_lstadd_back(t_libftlist **lst, t_libftlist *new)
{
	t_libftlist	*current;

	current = *lst;
	if (lst == NULL)
		return ((void) NULL);
	if (*lst == NULL)
		*lst = new;
	else
	{
		while (current->next != NULL)
			current = current->next;
		current->next = new;
	}
}
