/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohollar <sohollar@student.42paris.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 17:06:15 by sohollar          #+#    #+#             */
/*   Updated: 2025/11/27 20:12:17 by sohollar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/* #include <stdio.h>
#include <ctype.h> */

int	ft_toupper(int c)
{
	if (c >= 'a' && c <= 'z')
		return (c - 32);
	else
		return (c);
}

/* int	main(void)
{
	int	a;
	int	b;
	int	c;

	a = 50;
	b = 103;
	c = 82;
	printf("%d, %d, %d\n", ft_toupper(a), ft_toupper(b), ft_toupper(c));
	printf("%d, %d, %d\n", toupper(a), toupper(b), toupper(c));
} */
