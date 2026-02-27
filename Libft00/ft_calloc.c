/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohollar <sohollar@student.42paris.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 18:54:48 by sohollar          #+#    #+#             */
/*   Updated: 2026/02/26 19:23:07 by sohollar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/* #include <stdlib.h>
#include <string.h>
#include <stdio.h> */
//pas besoin de malloc(0) car non portable d'une lib a l'autre pour size == 0
void	*ft_calloc(size_t nmemb, size_t size)
{
	size_t			i;
	unsigned char	*tab;

	i = 0;
	if (size == 0)
		return (NULL);
	if (nmemb > __SIZE_MAX__ / size)
		return (NULL);
	tab = malloc(nmemb * size);
	if (tab == NULL)
		return (NULL);
	while (i < nmemb * size)
	{
		tab[i] = 0;
		i++;
	}
	return (tab);
}

/* int	main(void)
{
	size_t	i;
	size_t	n;
	size_t	sz;
	int		*tab;

	i = 0;
	n = 10;
	sz = sizeof(int);
	tab = (int *)calloc(n, sz);
	while (i < n)
	{
		tab[i] = i;
		printf("%d", tab[i]);
		i++;
	}
	printf("\n");
	free(tab);
	return (0);
} */
