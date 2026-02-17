/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohollar <sohollar@student.42paris.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 16:42:58 by sohollar          #+#    #+#             */
/*   Updated: 2025/12/01 14:43:09 by sohollar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/* #include <ctype.h> */
/* #include <stdio.h> */

int	ft_isprint(int c)
{
	if (c >= 32 && c <= 126)
		return (1);
	else
		return (0);
}

/* int	main(void)
{
	unsigned char	c;
	unsigned char	d;
	unsigned char	e;

	c = 31;
	d = 40;
	e = 127;
	printf("%d\n", ft_isprint(c));
	printf("%d\n", isprint(c));
	printf("%d\n", ft_isprint(d));
	printf("%d\n", isprint(d));
	printf("%d\n", ft_isprint(e));
	printf("%d\n", isprint(e));
} */
