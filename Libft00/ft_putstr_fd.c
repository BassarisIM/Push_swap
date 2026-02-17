/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohollar <sohollar@student.42paris.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 16:47:50 by sohollar          #+#    #+#             */
/*   Updated: 2025/12/11 15:33:24 by sohollar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/* #include <unistd.h> */

void	ft_putstr_fd(char *s, int fd)
{
	int	i;

	if (s == NULL)
		return ((void) NULL);
	i = 0;
	while (s[i])
	{
		write(fd, &s[i], 1);
		i++;
	}
}

/* int	main(void)
{
	char	*s = "On peut toujours etre plus cale.";

	ft_putstr_fd(s, 2);
} */
