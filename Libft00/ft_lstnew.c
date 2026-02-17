/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohollar <sohollar@student.42paris.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 18:21:57 by sohollar          #+#    #+#             */
/*   Updated: 2026/02/11 19:55:05 by sohollar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*#include <stdlib.h>*/
//#include <stdio.h>

t_libftlist	*ft_lstnew(void *content)
{
	t_libftlist	*first;

	first = malloc(sizeof(t_libftlist));
	if (first == NULL)
		return (NULL);
	first->content = content;
	first->next = NULL;
	return (first);
}

/*int	main(void)
{
	t_list	*first;

	first = ft_lstnew("content");
	free(first);
}*/
