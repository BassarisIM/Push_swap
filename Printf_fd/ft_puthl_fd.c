/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthl.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohollar <sohollar@student.42paris.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/18 15:01:40 by sohollar          #+#    #+#             */
/*   Updated: 2026/02/17 22:03:43 by sohollar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_fd.h"

static void	ft_matchlow_fd(unsigned int n, int fd)
{
	char			*low;
	unsigned int	i;

	low = "0123456789abcdef";
	i = 0;
	while (i != n % 16 && low[i])
		i++;
	write(fd, &low[i], 1);
}

int	ft_puthl_fd(unsigned int n, int fd)
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
		ft_matchlow_fd(n, fd);
		r++;
	}
	else
	{
		r += ft_puthl_fd(n / 16, fd);
		r += ft_puthl_fd(n % 16, fd);
	}
	return (r);
}
