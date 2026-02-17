/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohollar <sohollar@student.42paris.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 19:40:52 by sohollar          #+#    #+#             */
/*   Updated: 2025/12/11 15:19:18 by sohollar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/* #include <bsd/string.h>
#include <stdio.h> */

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;

	if (len == 0 && big == NULL)
		return (NULL);
	i = 0;
	if (little[i] == '\0')
		return ((char *)big);
	while (big[i] && i < len)
	{
		j = 0;
		if (big[i] == little[j])
		{
			while (big[i + j] == little[j] && (i + j) < len && big[i + j])
				j++;
			if (little[j] == '\0')
				return ((char *)&big[i]);
		}
		i++;
	}
	return (NULL);
}

/* int	main(void)
{
	char	*s1;
	char	*s2;

	s1 = "The only difference between \
	science and messing around is writing it down";
	s2 = "science";
	printf("%s\n%s", ft_strnstr(s1, s2, 36), strnstr(s1, s2, 36));
} */
