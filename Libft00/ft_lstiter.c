/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohollar <sohollar@student.42paris.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 16:24:54 by sohollar          #+#    #+#             */
/*   Updated: 2026/02/11 19:53:40 by sohollar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_libftlist *lst, void (*f)(void *))
{
	t_libftlist	*temp;

	temp = lst;
	while (temp != NULL)
	{
		f(temp->content);
		temp = temp->next;
	}
}
