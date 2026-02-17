/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohollar <sohollar@student.42paris.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 13:56:19 by sohollar          #+#    #+#             */
/*   Updated: 2025/12/01 17:09:50 by sohollar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/* #include <string.h>
#include <stdio.h> */

void	*ft_memmove(void *dest, const void *src, size_t n)
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
		if (&d[0] < &s[0])
			d[i] = s[i];
		else if (&d > &s)
			d[n - i - 1] = s[n - i - 1];
		i++;
	}
	return (dest);
}

/* int	main(void)
{
	char	str[30] = "Keria aussi et surtout";
	char	stri[25] = "Faker le GOAT";
	char	string[25] = "Faker le GOAT";

	ft_memmove(stri, str, 20);
	printf("%s\n%c\n", stri, stri[20]);
	memmove(string, str, 20);
	printf("%s\n%c\n", string, string[20]);
	return (0);
}
 */
