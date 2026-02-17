/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohollar <sohollar@student.42paris.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 14:00:16 by sohollar          #+#    #+#             */
/*   Updated: 2025/12/01 13:13:33 by sohollar         ###   ########.fr       */
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

size_t	ft_strlcpy(char *dest, const char *src, size_t siz)
{
	size_t	lensrc;
	size_t	i;

	lensrc = ft_strlen(src);
	i = 0;
	if (siz == 0)
	{
		return (lensrc);
	}
	while (src[i] && i < siz - 1)
	{
		dest[i] = src[i];
		i++;
	}
	if (siz > 0)
		dest[i] = '\0';
	return (lensrc);
}

/* int	main(void)
{
	char	s1[15] = "Let's go G2";
	char	s2[20] = "aaa";
	char	s3[15] = "Let's go G2";

	printf("%lu\n%s\n", ft_strlcpy(s1, s2, 11), s1);
	printf("%lu\n%s\n", strlcpy(s1, s2, 11), s1);
	printf("%lu\n%s\n", ft_strlcpy(s3, s2, 11), s3);
	printf("%lu\n%s\n", strlcpy(s3, s2, 11), s3);
	printf("%lu\n%s\n", ft_strlcpy(s3, s2, 0), s3);
	printf("%lu\n%s\n", strlcpy(s3, s2, 0), s3);
	return (0);
}
 */
