/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohollar <sohollar@student.42paris.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/23 15:59:01 by sohollar          #+#    #+#             */
/*   Updated: 2026/02/17 22:42:01 by sohollar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_freenodes(t_list	*list)
{
	t_node	*a;
	t_node	*b;

	if (list == NULL || list->first == NULL)
		return ;
	a = list->first;
	b = a->next;
	while (b != NULL)
	{
		a->next = NULL;
		a->pre = NULL;
		free(a);
		a = b;
		b = a->next;
	}
	a->next = NULL;
	a->pre = NULL;
	free(a);
	free(b);
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

void	print_list_ar(t_list *list)
{
	t_node	*test;

	if (list == NULL)
		return ;
	if (list->first == NULL)
	{
		ft_printf_fd(1, "\n");
		return ;
	}
	test = list->first;
	ft_printf_fd(1, "%d\n", test->nb);
	while (test->next != NULL)
	{
		test = test->next;
		ft_printf_fd(1, "%d\n", test->nb);
	}
	ft_printf_fd(1, "\n");
	while (test != NULL)
	{
		ft_printf_fd(1, "%d\n", test->nb);
		test = test->pre;
	}
	ft_printf_fd(1, "\n");
}

/*
** @brief cette fonction sert a imprimer une erreur, free la list et return un error code
 */
int	ft_error(t_list *list, char *str, int error_code)
{
	ft_freenodes(list);
	free(list);
	ft_printf_fd(2, str);
	return (error_code);
}

int	main(int argc, char **argv)
{
	t_list	*list;
	t_list	*b;
	int		i;
	int		valid;

	i = 1;
	if (argc == 1)
		return (0);
	if (!checknb(argv))
		return (ft_printf_fd(2, "Error not numbers\n"), 0);
	list = ft_newlist();
	if (list == NULL)
		return (0);
	valid = fillist(argv, list);
	if (!valid)
		return (ft_printf_fd(2, "Error invalid list\n"), 0);
	if (!doublons(list))
		return (ft_error(list, "Error duplicate numbers\n", 0));
	ft_printf_fd(1, "Printing default list\n");
	print_list_ar(list);
	b = ft_newlist();
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
	print_list_ar(b);
	ft_freenodes(list);
	ft_freenodes(b);
	free(b);
	free(list);
	return (0);
}
