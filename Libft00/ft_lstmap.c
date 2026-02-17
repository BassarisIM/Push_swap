/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohollar <sohollar@student.42paris.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 16:30:06 by sohollar          #+#    #+#             */
/*   Updated: 2026/02/11 19:55:28 by sohollar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_libftlist	*ft_lstmap(t_libftlist *lst,
	void *(*f)(void *), void (*del)(void *))
{
	t_libftlist	*newlst;
	t_libftlist	*tempnew;
	void		*resultf;

	if (lst == NULL)
		return (NULL);
	resultf = f(lst->content);
	if (resultf == NULL)
		return (NULL);
	newlst = ft_lstnew(resultf);
	if (newlst == NULL)
		return (del(resultf), NULL);
	tempnew = newlst;
	while (lst->next != NULL)
	{
		lst = lst->next;
		resultf = f(lst->content);
		if (resultf == NULL)
			return (ft_lstclear(&newlst, del), NULL);
		tempnew->next = ft_lstnew(resultf);
		if (tempnew->next == NULL)
			return (ft_lstclear(&newlst, del), del(resultf), NULL);
		tempnew = tempnew->next;
	}
	return (newlst);
}
