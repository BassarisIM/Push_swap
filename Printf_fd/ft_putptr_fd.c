/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohollar <sohollar@student.42paris.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/15 14:23:19 by sohollar          #+#    #+#             */
/*   Updated: 2026/02/17 22:02:38 by sohollar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_fd.h"

static void	ft_matchlow_fd(unsigned long n, int fd)
{
	char			*low;
	unsigned long	i;

	low = "0123456789abcdef";
	i = 0;
	while (i != n % 16 && low[i])
		i++;
	write(fd, &low[i], 1);
}

static int	ft_puthlptr_fd(unsigned long n, int fd)
{
	int		r;

	r = 0;
	if (n < 16)
	{
		ft_matchlow_fd(n, fd);
		r++;
	}
	else
	{
		r += ft_puthlptr_fd(n / 16, fd);
		r += ft_puthlptr_fd(n % 16, fd);
	}
	return (r);
}

int	ft_putptr_fd(unsigned long p, int fd)
{
	int		r;

	r = 0;
	if (p == 0)
		return (r += ft_putstr_r_fd("(nil)", fd), r);
	else
	{
		write(fd, "0x", 2);
		r = 2 + ft_puthlptr_fd(p, fd);
	}
	return (r);
}
