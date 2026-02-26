/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohollar <sohollar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/25 23:03:21 by sohollar          #+#    #+#             */
/*   Updated: 2026/02/25 23:06:24 by sohollar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*find_indice(t_list *list, int indice)
{
	t_node	*cur;

	if (list == NULL || list->first == NULL)
		return (NULL);
	cur = list->first;
	while (cur->indice != indice)
		cur = cur->next;
	return (cur);
}
