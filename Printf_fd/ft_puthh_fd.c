/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthh.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohollar <sohollar@student.42paris.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/18 15:02:38 by sohollar          #+#    #+#             */
/*   Updated: 2026/02/17 22:04:12 by sohollar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_fd.h"

static void	ft_matchhigh_fd(unsigned int n, int fd)
{
	char			*high;
	unsigned int	i;

	high = "0123456789ABCDEF";
	i = 0;
	while (i != n % 16 && high[i])
		i++;
	write(fd, &high[i], 1);
}

int	ft_puthh_fd(unsigned int n, int fd)
{
	int		r;

	r = 0;
	if (n < 0)
	{
		write(fd, "-", 1);
		n = -n;
		r++;
	}
	if (n < 16)
	{
		ft_matchhigh_fd(n, fd);
		r++;
	}
	else
	{
		r += ft_puthh_fd(n / 16, fd);
		r += ft_puthh_fd(n % 16, fd);
	}
	return (r);
}
