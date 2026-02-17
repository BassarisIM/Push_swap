/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohollar <sohollar@student.42paris.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 20:24:58 by sohollar          #+#    #+#             */
/*   Updated: 2025/12/11 16:20:05 by sohollar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/* #include <stdlib.h>
#include <stdio.h> */

size_t	ft_strlenprot(const char *str)
{
	int	i;

	if (str == NULL)
		return (0);
	i = 0;
	while (str[i])
		i++;
	return (i);
}

static char	*ft_malloc(size_t end)
{
	char	*s;

	s = (char *)malloc(sizeof(char) * end + sizeof(char) * 1);
	if (s == NULL)
		return (NULL);
	s[end] = '\0';
	return (s);
}

static int	ft_isinset(const char *s, char c)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == c)
			return (1);
		else
			i++;
	}
	return (0);
}

static char	*ft_strncpy(char *dest, const char *src, size_t n)
{
	size_t	i;

	i = 0;
	while (src[i] && i < n)
	{
		dest[i] = src[i];
		i++;
	}
	return (dest);
}

/* static char	*ft_sinul(char *s1, size_t i)
{
	char	*str;

	if (i == ft_strlen(s1))
	{
		str = ft_malloc(0);
		if (str == NULL)
			return (NULL);
		return (str);
	}
	else
		return ;
} */

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	i;
	size_t	start;
	size_t	end;
	char	*str;

	i = 0;
	while (ft_isinset(set, s1[i]))
		i++;
	if (i == ft_strlenprot(s1))
	{
		str = ft_malloc(0);
		if (str == NULL)
			return (NULL);
		return (str);
	}
	else
		start = i;
	i = ft_strlenprot(s1) - 1;
	while (i > start && ft_isinset(set, s1[i]))
		i--;
	end = i;
	str = ft_malloc(end - start + 1);
	if (str == NULL)
		return (NULL);
	return (ft_strncpy(str, &s1[start], end - start + 1), str);
}

/* int	main(void)
{
	char	*s;
	char	*set;
	char	*ft_trim;

	s = "Benjamin";
	set = "nieB";
	ft_trim = ft_strtrim(s, set);
	printf("%s\n", ft_trim);
	free(ft_trim);
} */
