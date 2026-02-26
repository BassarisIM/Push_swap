/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohollar <sohollar@student.42paris.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/26 17:23:47 by sohollar          #+#    #+#             */
/*   Updated: 2026/02/26 19:20:51 by sohollar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	max(int a, int b)
{
	if (a >= b)
		return (a);
	return (b);
}

int	ra_rrb(t_list *a, t_list *b, t_boite *boite)
{
	int	move_a;
	int	move_b;
	int	count;

	count = 0;
	move_a = boite->ra;
	move_b = boite->rrb;
	while (move_a > 0)
	{
		count += rotate_a(a);
		move_a--;
	}
	while (move_b > 0)
	{
		count += rrotate_b(b);
		move_b--;
	}
	return (count);
}

int	rra_rb(t_list *a, t_list *b, t_boite *boite)
{
	int	move_a;
	int	move_b;
	int	count;

	count = 0;
	move_a = boite->rra;
	move_b = boite->rb;
	while (move_a > 0)
	{
		count += rrotate_a(a);
		move_a--;
	}
	while (move_b > 0)
	{
		count += rotate_b(b);
		move_b--;
	}
	return (count);
}

int	rr_diff(t_list *a, t_list *b, t_boite *boite)
{
	int	move_ab;
	int	move_diff;
	int	count;

	count = 0;
	move_ab = boite->rr;
	while (move_ab > 0)
	{
		count += rotate_anb(a, b);
		move_ab--;
	}
	move_diff = max(boite->rr_diffa, boite->rr_diffb);
	while (move_diff > 0)
	{
		if (boite->rr_diffa >= boite->rr_diffb)
			count += rotate_a(a);
		else
			count += rotate_b(b);
		move_diff--;
	}
	return (count);
}

int	rrr_diff(t_list *a, t_list *b, t_boite *boite)
{
	int	move_ab;
	int	move_diff;
	int	count;

	count = 0;
	move_ab = boite->rrr;
	while (move_ab > 0)
	{
		count += rrotate_anb(a, b);
		move_ab--;
	}
	move_diff = max(boite->rrr_diffa, boite->rrr_diffb);
	while (move_diff > 0)
	{
		if (boite->rrr_diffa >= boite->rrr_diffb)
			count += rrotate_a(a);
		else
			count += rrotate_b(b);
		move_diff--;
	}
	return (count);
}
