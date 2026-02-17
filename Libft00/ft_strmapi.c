/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohollar <sohollar@student.42paris.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 20:24:58 by sohollar          #+#    #+#             */
/*   Updated: 2025/12/11 15:31:18 by sohollar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/* #include <stdlib.h>
#include <string.h>
#include <stdio.h> */

//size_t	ft_strlen(const char *str);
/* {
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
} */

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t	i;
	char	*mapi;

	if (s == NULL)
		return (NULL);
	i = 0;
	mapi = (char *)malloc(sizeof(char) * ft_strlen(s) + 1);
	if (mapi == NULL)
		return (NULL);
	mapi[ft_strlen(s)] = '\0';
	while (s[i])
	{
		mapi[i] = f(i, s[i]);
		i++;
	}
	return (mapi);
}

/* char	fonction(unsigned int i, char c)
{
	c = c + 1;
	printf("%d", i);
	return (c);
}

int	main(void)
{
	char	*s;
	char	*mapi;
	int		i;
	char	c;

	i = 3;
	c = 'a';
	s = "J'avais la passion des mots";
	mapi = ft_strmapi(s, fonction);
	printf("%s\n", mapi);
	free(mapi);
} */
