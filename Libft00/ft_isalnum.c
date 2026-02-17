/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohollar <sohollar@student.42paris.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 16:17:15 by sohollar          #+#    #+#             */
/*   Updated: 2025/12/01 14:42:37 by sohollar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/* #include <ctype.h>
#include <stdio.h> */

int	ft_isalnum(int c)
{
	if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z')
		|| (c >= '0' && c <= '9'))
		return (1);
	else
		return (0);
}

/* int	main(void)
{
	unsigned char	c;
	unsigned char	d;
	unsigned char	e;

	c = 'd';
	d = '!';
	e = '3';
	printf("%d\n", ft_isalnum(c));
	printf("%d\n", isalnum(c));
	printf("%d\n", ft_isalnum(d));
	printf("%d\n", isalnum(d));
	printf("%d\n", ft_isalnum(e));
	printf("%d\n", isalnum(e));
} */
