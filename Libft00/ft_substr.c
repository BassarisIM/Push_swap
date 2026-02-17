/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohollar <sohollar@student.42paris.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 20:24:58 by sohollar          #+#    #+#             */
/*   Updated: 2025/12/11 15:22:09 by sohollar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/* #include <stdlib.h>
#include <stdio.h> */

size_t	ft_strlen(const char *str);
/* {
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
} */

size_t	ft_min(size_t a, size_t b)
{
	if (a > b)
		return (b);
	else
		return (a);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	unsigned int	i;
	char			*substr;

	if (s == NULL)
		return (NULL);
	i = start;
	if (start >= ft_strlen(s) || !s)
	{
		substr = (char *)malloc(sizeof(char) * 1);
		if (substr == 0)
			return (NULL);
		substr[0] = '\0';
		return (substr);
	}
	substr = (char *)malloc(sizeof(char)
			* ft_min(len, ft_strlen(s) - start) + 1);
	if (substr == 0)
		return (NULL);
	substr[ft_min(len, ft_strlen(s) - start)] = '\0';
	while (i < start + ft_min(len, ft_strlen(s) - start))
	{
		substr[i - start] = s[i];
		i++;
	}
	return (substr);
}

/* int	main(void)
{
	const char		*s;
	unsigned int	start;
	size_t			len;
	char			*sub;

	s = "Bonjour Madame Sand !";
	start = 20;
	len = 1;
	sub = ft_substr(s, start, len);
	printf("%s\n", sub);
	free(sub);
} */
