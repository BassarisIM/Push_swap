/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohollar <sohollar@student.42paris.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/21 18:48:48 by sohollar          #+#    #+#             */
/*   Updated: 2025/12/11 16:08:13 by sohollar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/* #include <string.h>
#include <stdio.h> */

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	size_t	i;

	if (s == NULL)
		return ((void) NULL);
	i = 0;
	while (s[i])
	{
		f(i, &s[i]);
		i++;
	}
}

/* void	fonction(unsigned int i, char *s)
{
	s[i] = s[i] + 1;
}

int	main(void)
{
	char	s[30] = "J'avais la passion des mots";

	ft_striteri(s, &fonction);
	printf("%s\n", s);
} */
