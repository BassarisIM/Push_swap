/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohollar <sohollar@student.42paris.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 19:21:45 by sohollar          #+#    #+#             */
/*   Updated: 2025/12/01 16:51:24 by sohollar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/* #include <string.h>
#include <stdio.h> */

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			i;
	unsigned char	*r1;
	unsigned char	*r2;

	r1 = (unsigned char *)s1;
	r2 = (unsigned char *)s2;
	i = 0;
	if (n == 0)
		return (0);
	while (i < n - 1)
	{
		if (r1[i] == r2[i])
			i++;
		else
			return (r1[i] - r2[i]);
	}
	return (r1[i] - r2[i]);
}

/* int	main(void)
{
	char	*s1;
	char	*s2;

	s1 = "Le GOAT Faker";
	s2 = "Le GOAT Keria";
	printf("%d, %d", ft_memcmp(s1, s2, 9), memcmp(s1, s2, 9));
} */
