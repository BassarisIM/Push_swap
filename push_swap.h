/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohollar <sohollar@student.42paris.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/28 17:27:10 by sohollar          #+#    #+#             */
/*   Updated: 2026/02/25 22:02:27 by sohollar         ###   ########.fr       */
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
	int				stack_pos;
	int				depth;
	int				ismin;
	int				ismax;
	struct s_node	*next;
	struct s_node	*pre;
}					t_node;

typedef struct s_list
{
	int		len;
	int		min;
	int		max;
	t_node	*first;
}			t_list;

typedef struct s_boite
{
	int	rr_diff;
	int	rrr_diff;
	int	ra_rrb;
	int	rra_rb;
	int	cost;
}		t_boite;

int		checknb(char **argv);
int		doublons(t_list *list);
int		is_sep(char c);
int		checklimits(long nb);
long	atoicherry(char *str);
int		fillist(char **argv, t_list *list);
t_list	*ft_newlist(void);
t_node	*ft_newnode(int *n);
int		ft_listadd_back(t_list *list, t_node *new);
void	ft_freelist(t_list *list);
int		rrotate_a(t_list *a);
int		rrotate_b(t_list *b);
int		rrotate_anb(t_list *a, t_list *b);
int		swap_a(t_list *list);
int		swap_b(t_list *list);
int		swap_anb(t_list *a, t_list *b);
int		push_a(t_list *a, t_list *b);
int		push_b(t_list *a, t_list *b);
int		rotate_a(t_list *a);
int		rotate_b(t_list *b);
int		rotate_anb(t_list *a, t_list *b);
int		indicage(t_list *list);
void	print_list_ar(t_list *list);
int		sort_simple(t_list *a, t_list *b, int nb_ops);
int		turkish_sort(t_list *a, t_list *b);
void	apply_depth(t_list *list);
void	apply_stack_pos(t_list *list);
void	apply_minmax(t_list *list);

#endif
