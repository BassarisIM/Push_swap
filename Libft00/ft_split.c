/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohollar <sohollar@student.42paris.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 20:24:58 by sohollar          #+#    #+#             */
/*   Updated: 2025/12/11 16:19:59 by sohollar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/* #include <stdlib.h>
#include <string.h>
#include <stdio.h> */

static size_t	ft_strlenw(const char *str, char c)
{
	int	i;

	if (str == NULL)
		return (0);
	i = 0;
	while (str[i] && str[i] != c)
		i++;
	return (i);
}

static int	ft_countwords(char const *s, char c)
{
	int		i;
	int		nb;

	i = 0;
	nb = 0;
	while (s[i])
	{
		if (s[i] != c && (i == 0 || (s[i - 1] == c)))
			nb++;
		i++;
	}
	return (nb);
}

static char	*ft_sousmalloc(char **tab, int i, int k)
{
	tab[k] = (char *)malloc(sizeof(char) * (i + 1));
	if (tab[k] == NULL)
	{
		k--;
		while (k >= 0)
		{
			free(tab[k]);
			k--;
		}
		free(tab);
		return (NULL);
	}
	else
		return (tab[k]);
}

static void	ft_remplir(char *tab, const char *s, const char c)
{
	int	j;

	j = 0;
	tab[ft_strlenw(s, c)] = '\0';
	while (s[j] && s[j] != c)
	{
		tab[j] = s[j];
		j++;
	}
}

char	**ft_split(char const *s, char c)
{
	int		nb;
	size_t	i;
	int		k;
	char	**tab;

	i = 0;
	k = 0;
	nb = ft_countwords(s, c);
	tab = (char **)malloc(sizeof(char *) * (nb + 1));
	if (tab == NULL)
		return (NULL);
	tab[nb] = NULL;
	while (s[i])
	{
		if (s[i] != c && (i == 0 || (s[i - 1] == c)))
		{
			tab[k] = ft_sousmalloc(tab, ft_strlenw(&s[i], c), k);
			if (tab[k] == NULL)
				return (NULL);
			ft_remplir(tab[k], &s[i], c);
			k++;
		}
		i++;
	}
	return (tab);
}

/* int	main(void)
{
	char	*s;
	char	c;
	int		i;
	char	**szzzut;

	i = 0;
	s = "  Ce qui se concoit bien  s'enonce clairement ";
	c = ' ';
	printf("%d\n", ft_countwords(s, c));
	szzzut = ft_split(s, c);
	while (szzzut[i])
	{
		printf("%s\n", szzzut[i]);
		free(szzzut[i]);
		i++;
	}
} */
