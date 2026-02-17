/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohollar <sohollar@student.42paris.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 15:44:28 by sohollar          #+#    #+#             */
/*   Updated: 2025/12/01 14:43:45 by sohollar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/* #include <ctype.h>
#include <stdio.h> */

int	ft_isalpha(int c)
{
	if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'))
		return (1);
	else
		return (0);
}

/* int	main(void)
{
	unsigned char	c;
	unsigned char	d;

	c = 'd';
	d = (unsigned char) -1;
	printf("%d\n", ft_isalpha(c));
	printf("%d\n", isalpha(c));
	printf("%d\n", ft_isalpha(d));
	printf("%d\n", isalpha(d));
} */
