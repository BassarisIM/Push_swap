/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohollar <sohollar@student.42paris.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 14:58:43 by sohollar          #+#    #+#             */
/*   Updated: 2025/12/11 15:15:46 by sohollar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/* #include <bsd/string.h>
#include <stdio.h> */

size_t	ft_strlen(const char *str);
/* {
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
} */

static size_t	ft_min(size_t a, size_t b)
{
	if (a < b)
		return (a);
	else
		return (b);
}

size_t	ft_strlcat(char *dest, const char *src, size_t siz)
{
	size_t	i;
	size_t	lendest;

	if (siz == 0)
		return (ft_strlen(src));
	lendest = ft_strlen(dest);
	i = 0;
	while (src[i] && (lendest + i < siz - 1))
	{
		dest[lendest + i] = src[i];
		i++;
	}
	if ((lendest + i) < siz)
		dest[lendest + i] = '\0';
	return (ft_strlen(src) + ft_min((lendest), siz));
}

/* int	main(void)
{
	char	dest[20] = "Bonjour Madame ";
	char	dest2[20] = "Bonjour Madame ";
	char	src[30] = "Somevery polite words";

	ft_strlcat(dest, src, 20);
	printf("%s\n", dest);
	strlcat(dest2, src, 20);
	printf("%s\n%lu\n", dest2, ft_strlcat);
} */
