/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohollar <sohollar@student.42paris.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 16:34:21 by sohollar          #+#    #+#             */
/*   Updated: 2025/12/01 14:42:44 by sohollar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/* #include <ctype.h>
#include <stdio.h> */

int	ft_isascii(int c)
{
	if (c >= 0 && c <= 127)
		return (1);
	else
		return (0);
}

/* int	main(void)
{
	unsigned char	c;
	unsigned char	d;
	unsigned char	e;

	c = '5';
	d = '!';
	e = 128;
	printf("%d\n", ft_isascii(c));
	printf("%d\n", isascii(c));
	printf("%d\n", ft_isascii(d));
	printf("%d\n", isascii(d));
	printf("%d\n", ft_isascii(e));
	printf("%d\n", isascii(e));
} */
