/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohollar <sohollar@student.42paris.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 19:24:14 by sohollar          #+#    #+#             */
/*   Updated: 2025/11/27 20:06:14 by sohollar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/* #include <string.h>
#include <stdio.h> */

void	*ft_bzero(void *s, size_t n)
{
	size_t			i;
	unsigned char	*str;

	str = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		str[i] = '\0';
		i++;
	}
	return (s);
}

/* int	main(void)
{
	char	str[20] = "Keria le GOAT";
	char	stri[20] = "Keria le GOAT";

	//str = (char *)malloc(sizeof(char) * (50 + 1));
	//str[10] = '\0'; pour ne pas que le printf aille
	//trop loin si on ne remplit pas str...
	printf("%s\n", str);
	ft_bzero(str, 5);
	printf("%s\n", str);
	printf("%s\n", stri);
	bzero(stri, 5);
	printf("%s\n", stri);
	return (0);
} */
