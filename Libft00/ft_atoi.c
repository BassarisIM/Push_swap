/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohollar <sohollar@student.42paris.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 19:40:52 by sohollar          #+#    #+#             */
/*   Updated: 2026/02/25 14:52:52 by sohollar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/* #include <stdio.h> */

int	ft_isdigit(int c);
/* {
	if (c >= '0' && c <= '9')
		return (1);
	else
		return (0);
} */

int	ft_atoi(const char *nptr)
{
	int	i;
	int	s;
	int	nb;

	i = 0;
	s = 1;
	nb = 0;
	while (nptr[i] && ((nptr[i] >= 9 && nptr[i] <= 13) || nptr[i] == 32))
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			s *= -1;
		i++;
	}
	while (ft_isdigit(nptr[i]))
	{
		nb = (nb * 10) + nptr[i] - 48;
		i++;
	}
	return (nb * s);
}

/* int	main(void)
{
	char	*str;
	int		result;

	str = "   			-54534358dfdrg";
	result = ft_atoi(str);
	printf("%d\n", result);
} */
