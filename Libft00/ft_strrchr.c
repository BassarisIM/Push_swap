/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohollar <sohollar@student.42paris.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 18:11:20 by sohollar          #+#    #+#             */
/*   Updated: 2025/12/01 15:02:57 by sohollar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/* #include <string.h>
#include <stdio.h> */

size_t	ft_strlen(const char *str);
/* {
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
} */

char	*ft_strrchr(const char *s, int c)
{
	size_t	i;

	i = ft_strlen(s);
	while ((unsigned char)s[i] != (unsigned char) c && i > 0)
		i--;
	if ((unsigned char)s[i] == (unsigned char)c)
		return ((char *)&s[i]);
	else
		return (NULL);
}

/* int	main(void)
{
	char	*str;
	char	c;

	c = 'e';
	str = "teste";
	printf("%s\n", ft_strrchr(str, c));
	printf("%s\n", strrchr(str, c));
} */
