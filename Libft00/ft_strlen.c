/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohollar <sohollar@student.42paris.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 16:53:20 by sohollar          #+#    #+#             */
/*   Updated: 2025/12/01 14:46:58 by sohollar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/* #include <string.h>
#include <stdio.h> */

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

/* int	main(void)
{
	const char	*s1;
	const char	*s2;

	s1 = "Au clair de la lune";
	s2 = "Keria the GOAT";
	printf("%lu\n", ft_strlen(s1));
	printf("%lu\n", strlen(s1));
	printf("%lu\n", ft_strlen(s2));
	printf("%lu\n", strlen(s2));
} */
