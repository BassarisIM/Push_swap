/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohollar <sohollar@student.42paris.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 17:19:58 by sohollar          #+#    #+#             */
/*   Updated: 2025/12/01 14:48:07 by sohollar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/* #include <string.h>
#include <stdio.h> */

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i] != (unsigned char)c && s[i])
		i++;
	if (s[i] == (unsigned char)c)
		return ((char *)&s[i]);
	else
		return (NULL);
}

/* int	main(void)
{
	char	*str;
	char	c;

	c = 'd';
	str = "The only Difference between science \
	anD messing around is writing it Down";
	printf("%s\n", ft_strchr(str, c));
	printf("%s\n", strchr(str, c));
} */
