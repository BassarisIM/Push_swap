/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohollar <sohollar@student.42paris.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/05 15:54:42 by sohollar          #+#    #+#             */
/*   Updated: 2026/02/11 19:53:48 by sohollar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//#include <stdio.h>

void	ft_lstadd_front(t_libftlist **lst, t_libftlist *new)
{
	if (!new || !lst)
		return ;
	new->next = *lst;
	*lst = new;
}
