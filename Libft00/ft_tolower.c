/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohollar <sohollar@student.42paris.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 17:14:30 by sohollar          #+#    #+#             */
/*   Updated: 2025/11/27 20:12:14 by sohollar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/* #include <stdio.h>
#include <ctype.h> */

int	ft_tolower(int c)
{
	if (c >= 'A' && c <= 'Z')
		return (c + 32);
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
	printf("%d, %d, %d\n", ft_tolower(a), ft_tolower(b), ft_tolower(c));
	printf("%d, %d, %d\n", tolower(a), tolower(b), tolower(c));
} */
