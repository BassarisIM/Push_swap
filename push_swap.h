/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohollar <sohollar@student.42paris.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/28 17:27:10 by sohollar          #+#    #+#             */
/*   Updated: 2026/02/26 19:33:39 by sohollar         ###   ########.fr       */
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
	int		ra;
	int		rra;
	int		rb;
	int		rrb;
	int		rr;
	int		rr_diffa;
	int		rr_diffb;
	int		rrr;
	int		rrr_diffa;
	int		rrr_diffb;
	int		ra_rrb;
	int		rra_rb;
	int		rr_diff;
	int		rrr_diff;
	int		cost;
	char	*combi;
	int		idx;
}			t_boite;

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
//int		sort_simple(t_list *a, t_list *b, int nb_ops);
int		turkish_sort(t_list *a, t_list *b, int nb_ops);
void	apply_depth(t_list *list);
void	apply_stack_pos(t_list *list);
void	apply_minmax(t_list *list);
t_boite	*init_boite(void);
int		find_cheapest(t_list *a, t_list *b, t_boite *cheap);
int		move_cheapest_atob(t_list *a, t_list *b, t_boite *cheap);
int		merge_btoa(t_list *a, t_list *b);
void	fill_costs(t_list *a, t_list *b, t_node *na, t_node *nb, t_boite *boite);
void	fill_boite(t_list *a, t_list *b, t_node *na, t_node *nb, t_boite *boite);
t_node	*find_indice(t_list *list, int indice);
//t_boite	*cost(t_list *a, t_list *b, t_node *node);
t_boite	*init_boite(void);
int		rrr_diff(t_list *a, t_list *b, t_boite *boite);
int		rr_diff(t_list *a, t_list *b, t_boite *boite);
int		rra_rb(t_list *a, t_list *b, t_boite *boite);
int		ra_rrb(t_list *a, t_list *b, t_boite *boite);
int		move_cheapest_atob(t_list *a, t_list *b, t_boite *cheap);


#endif
