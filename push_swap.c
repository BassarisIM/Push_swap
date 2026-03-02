/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohollar <sohollar@student.42paris.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/23 15:59:01 by sohollar          #+#    #+#             */
/*   Updated: 2026/03/02 16:42:44 by sohollar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	only_sep(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (is_sep(str[i]))
			i++;
		else
			return (0);
	}
	return (1);
}

long	atoicherry(char *str)
{
	int		i;
	int		sign;
	long	nb;

	sign = 1;
	nb = 0;
	i = 0;
	if (str[i] == '-')
	{
		sign = -1;
		i++;
	}
	while (str[i] && (!is_sep(str[i])))
	{
		nb = nb * 10 + str[i] - 48;
		i++;
	}
	return (nb * sign);
}

static int	is_sorted(t_list *list)
{
	t_node	*cur;

	if (list->first == NULL)
		return (1);
	cur = list->first;
	while (cur->next != NULL)
	{
		cur = cur->next;
		if (! (cur->nb > cur->pre->nb))
			return (0);
	}
	return (1);
}

/*
** @brief cette fonction sert a imprimer \
	erreur, free la list et return un error code
*/
static int	ft_error(t_list *list, t_list *b, char *str, int error_code)
{
	ft_freelist(list);
	free(b);
	ft_printf_fd(2, str);
	return (error_code);
}

int	main(int argc, char **argv)
{
	t_list	*list;
	t_list	*b;

	if (argc == 1)
		return (0);
	if (!checknb(argv))
		return (ft_printf_fd(2, "Error\n"), 0);
	list = ft_newlist();
	if (list == NULL)
		return (0);
	b = ft_newlist();
	if (b == NULL)
		return (free(list), 0);
	if (!fillist(argv, list))
		return (ft_error(list, b, "Error\n", 0));
	if (!doublons(list))
		return (ft_error(list, b, "Error\n", 0));
	if (is_sorted(list))
		return (ft_freelist(list), free(b), 0);
	if (!indicage(list))
		return (ft_error(list, b, "Error\n", 0));
	if (!turkish_sort(list, b))
		return (ft_freenodes(b), ft_error(list, b, "Error\n", 0));
	free_anb(list, b);
	return (0);
}
	/*print_list_ar(list);
	print_indices_ar(list);
	ft_printf_fd(1, "Printing default list\n");
	swap_a(list);
	swap_b(b);
	rotate_b(b);
	rrotate_b(b);
	push_a(list, b);
	push_b(list, b);
	swap_b(b);
	rotate_b(b);
	rrotate_b(b);
	push_b(list, b);
	swap_b(b);
	rotate_b(b);
	rrotate_b(b);
	push_b(list, b);
	swap_b(b);
	rotate_b(b);
	rrotate_b(b);
	push_b(list, b);
	ft_printf_fd(1, "Printing default list\n");
	print_list_ar(list);
	ft_printf_fd(1, "Printing B\n");
	print_list_ar(b); */
