/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohollar <sohollar@student.42paris.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/06 13:44:44 by sohollar          #+#    #+#             */
/*   Updated: 2026/02/11 19:55:25 by sohollar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//#include <stdio.h>
//#include <stdlib.h>

void	ft_lstdelone(t_libftlist *lst, void (*del)(void *))
{
	if (lst == NULL)
		return ((void) NULL);
	del(lst->content);
	lst->next = NULL;
	free(lst);
	lst = NULL;
}
