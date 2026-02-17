/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohollar <sohollar@student.42paris.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 18:30:00 by sohollar          #+#    #+#             */
/*   Updated: 2025/11/27 20:08:05 by sohollar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/* #include <stdlib.h>
#include <string.h>
#include <stdio.h> */

size_t	ft_strlen(const char *str);
/* {
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
} */

char	*ft_strdup(const char *s)
{
	int		i;
	char	*str;

	i = 0;
	str = (char *)malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (str == NULL)
		return (NULL);
	str[ft_strlen(s)] = '\0';
	while (s[i])
	{
		str[i] = s[i];
		i++;
	}
	return (str);
}

/* int	main(void)
{
	const char	*str = "Bonjour Madame";
	char		*dup;
	char		*ft_dup;

	ft_dup = ft_strdup(str);
	dup = strdup(str);
	printf("%s\n", ft_dup);
	printf("%s\n", dup);
	free(dup);
	free(ft_dup);
} */
