/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohollar <sohollar@student.42paris.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 16:12:02 by sohollar          #+#    #+#             */
/*   Updated: 2025/12/01 14:42:53 by sohollar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/* #include <ctype.h> */
/* #include <stdio.h> */

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	else
		return (0);
}

/* int	main(void)
{
	unsigned char	c;
	unsigned char	d;

	c = '5';
	d = '!';
	printf("%d\n", ft_isdigit(c));
	printf("%d\n", isdigit(c));
	printf("%d\n", ft_isdigit(d));
	printf("%d\n", isdigit(d));
} */
