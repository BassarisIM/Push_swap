/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_r.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohollar <sohollar@student.42paris.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 19:16:17 by sohollar          #+#    #+#             */
/*   Updated: 2026/02/17 22:03:18 by sohollar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_fd.h"

int	ft_putnbr_r_fd(int n, int fd)
{
	char	c;
	int		r;

	r = 0;
	if (n == -2147483648)
		return (write(fd, "-2147483648", 11), 11);
	if (n < 0)
	{
		write(fd, "-", 1);
		n = -n;
		r++;
	}
	if (n < 10)
	{
		c = n + 48;
		write(fd, &c, 1);
		r++;
	}
	else if (n >= 10)
	{
		r += ft_putnbr_r_fd(n / 10, fd);
		r += ft_putnbr_r_fd(n % 10, fd);
	}
	return (r);
}
