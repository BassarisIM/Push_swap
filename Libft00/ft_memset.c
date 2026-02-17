/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohollar <sohollar@student.42paris.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 17:36:57 by sohollar          #+#    #+#             */
/*   Updated: 2025/11/27 20:00:45 by sohollar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/* #include <string.h>
#include <stdio.h> */

void	*ft_memset(void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*str;
	unsigned char	d;

	str = (unsigned char *)s;
	d = (unsigned char)c;
	i = 0;
	while (i < n)
	{
		str[i] = d;
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
	ft_memset(str, 50, 10);
	printf("%s\n", str);
	printf("%s\n", stri);
	memset(stri, 50, 10);
	printf("%s\n", stri);
	return (0);
} */
