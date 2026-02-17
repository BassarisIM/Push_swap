/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohollar <sohollar@student.42paris.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 17:24:34 by sohollar          #+#    #+#             */
/*   Updated: 2026/02/11 19:54:47 by sohollar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_libftlist **lst, void (*del)(void *))
{
	t_libftlist	*temp;
	t_libftlist	*suivant;

	temp = *lst;
	if (temp == NULL)
		return ((void) NULL);
	else
	{
		while (temp != NULL)
		{
			suivant = temp->next;
			ft_lstdelone(temp, del);
			temp = suivant;
		}
		*lst = NULL;
	}
}
