/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohollar <sohollar@student.42paris.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 20:18:27 by sohollar          #+#    #+#             */
/*   Updated: 2025/12/05 17:46:42 by sohollar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>
/* #include <stdio.h> */

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*d;
	unsigned char	*s;

	if (dest == NULL && src == NULL)
		return (NULL);
	d = (unsigned char *)dest;
	s = (unsigned char *)src;
	i = 0;
	while (i < n)
	{
		d[i] = s[i];
		i++;
	}
	return (dest);
}

/* int	main(void)
{
	char	str[30] = "Keria aussi et surtout";
	char	stri[20] = "Faker le GOAT";
	char	string[20] = "Faker le GOAT";

	//str = (char *)malloc(sizeof(char) * (50 + 1));
	//str[10] = '\0'; pour ne pas que le printf aille
		//trop loin si on ne remplit pas str...
	printf("%s\n", stri);
	ft_memcpy(stri, str, 20);
	printf("%s\n", stri);
	printf("%s\n", string);
	memcpy(string, str, 20);
	printf("%s\n", string);
	return (0);
} */
