/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohollar <sohollar@student.42paris.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 20:24:58 by sohollar          #+#    #+#             */
/*   Updated: 2025/12/01 18:52:42 by sohollar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/* #include <stdlib.h>
#include <string.h>*/
/* #include <stdio.h> */

size_t	ft_strlen(const char *str);
/* {
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
} */

static int	ft_getsiz(long n)
{
	long	siz;

	siz = 1;
	if (n < 0)
		n = -n;
	while (n >= 10)
	{
		n = n / 10;
		siz++;
	}
	return (siz);
}

static int	ft_initialise(char *s, int siz)
{
	int	i;

	i = 0;
	if (s == NULL)
		return (0);
	s[siz] = '\0';
	while (i < siz)
	{
		s[i] = 'c';
		i++;
	}
	return (1);
}

static void	ft_remplir(char *s, long n)
{
	long	i;

	i = ft_strlen(s) - 1;
	if (n < 0)
		n = -n;
	while (n >= 10)
	{
		s[i] = (n % 10) + 48;
		n = n / 10;
		i--;
	}
	s[i] = (n % 10) + 48;
}

char	*ft_itoa(int n)
{
	int		siz;
	char	*str;
	int		i;
	long	nb;

	nb = n;
	siz = ft_getsiz(nb);
	i = 0;
	if (nb < 0)
		siz++;
	str = (char *)malloc(sizeof(char) * (siz + 1));
	ft_initialise(str, siz);
	if (str == NULL)
		return (NULL);
	if (nb < 0)
	{
		str[i] = '-';
		i++;
	}
	ft_remplir(&str[i], nb);
	return (str);
}

/* int	main(void)
{
	int		n;
	char	*s;

	n = -456;
	s = ft_itoa(n);
	printf("%s\n", s);
	free(s);
	return (1);
} */
