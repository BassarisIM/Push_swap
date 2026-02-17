/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohollar <sohollar@student.42paris.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/28 17:27:10 by sohollar          #+#    #+#             */
/*   Updated: 2026/02/17 22:42:08 by sohollar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include "Libft00/libft.h"
# include "Printf_fd/ft_printf_fd.h"

typedef struct s_node
{
	int				nb;
	int				indice;
	struct s_node	*next;
	struct s_node	*pre;
}					t_node;

typedef struct s_list
{
	int		len;
	t_node	*first;
}			t_list;

int		isok(char **argv, int i, int j);
int		checknb(char **argv);
int		doublons(t_list *list);
int		is_sep(char c);
int		checklimits(long nb);
long	atoicherry(char *str);
int		addnb(char *str, t_list *list);
int		fillist(char **argv, t_list *list);
t_list	*ft_newlist(void);
t_node	*ft_newnode(int *n);
int		ft_listadd_back(t_list *list, t_node *new);
void	ft_freenodes(t_list	*list);
void	rrotate_a(t_list *a);
void	rrotate_b(t_list *b);
void	rrotate_anb(t_list *a, t_list *b);
void	swap_a(t_list *list);
void	swap_b(t_list *list);
void	swap_anb(t_list *a, t_list *b);
void	push_a(t_list *a, t_list *b);
void	push_b(t_list *a, t_list *b);
void	rotate_a(t_list *a);
void	rotate_b(t_list *b);
void	rotate_anb(t_list *a, t_list *b);
void	rotate_ops(t_list *list);
void	swap_ops(t_list *list);
void	rrotate_ops(t_list *list);

#endif
