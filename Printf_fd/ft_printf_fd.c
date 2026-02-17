/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohollar <sohollar@student.42paris.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/15 14:23:19 by sohollar          #+#    #+#             */
/*   Updated: 2026/02/17 22:05:35 by sohollar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_fd.h"
//#include <stdarg.h>
//#include <unistd.h>
//#include <stdio.h>

static int	ft_putunb_fd(unsigned int n, int fd)
{
	char	c;
	int		r;

	r = 0;
	if (n < 10)
	{
		c = n + 48;
		write(fd, &c, 1);
		r++;
	}
	else if (n >= 10)
	{
		r += ft_putunb_fd(n / 10, fd);
		r += ft_putunb_fd(n % 10, fd);
	}
	return (r);
}

static int	ft_triage_fd(const char *s, va_list args, int fd)
{
	int		r;
	char	c;

	r = 0;
	if (*s == 'c')
		return (c = (char)va_arg(args, int), write(fd, &c, 1), r++, r);
	else if (*s == 's')
		return (r += ft_putstr_r_fd(va_arg(args, char *), fd), r);
	else if (*s == 'p')
		return (r += ft_putptr_fd(va_arg(args, unsigned long), fd), r);
	else if (*s == 'd' || *s == 'i')
		return (r += ft_putnbr_r_fd(va_arg(args, int), fd), r);
	else if (*s == 'u')
		return (r += ft_putunb_fd(va_arg(args, unsigned int), fd), r);
	else if (*s == 'x')
		return (r += ft_puthl_fd(va_arg(args, unsigned int), fd), r);
	else if (*s == 'X')
		return (r += ft_puthh_fd(va_arg(args, unsigned int), fd), r);
	else
		return (write(fd, "%", 1), r++, r);
}

int	ft_printf_fd(int fd, const char *s, ...)
{
	int		r;
	va_list	args;

	r = 0;
	va_start(args, s);
	if (s == NULL)
		return (-1);
	while (*s != '\0')
	{
		if (*s != '%')
			r += write (fd, s, 1);
		else
		{
			s++;
			if (ft_isinset("cspdiuxX%", *s) == 1)
				r += ft_triage_fd(s, args, fd);
			else
				return (0);
		}
		s++;
	}
	va_end(args);
	return (r);
}

/* int	main(void)
{

	char			c = 'f';
	//char			*s = "String for the match";
	int				n = -2147483648;
	unsigned int	un = 4294967295;
	unsigned long	x = 10;

	ft_printf("Bonjour !\n");
	printf("Bonjour !\n");
	ft_printf("%c\n", c);
	printf("%c\n", c);
	ft_printf("%s\n", (char *) NULL);
	printf("%s\n", (char *) NULL);
	ft_printf("%p\n", (char *) NULL);
	printf("%p\n", (char *) NULL);
	ft_printf("%d\n", n);
	printf("%d\n", n);
	ft_printf("%i\n", n);
	printf("%i\n", n);
	ft_printf("%u\n", un);
	printf("%u\n", un);
	ft_printf("%x\n", x);
	//printf("%x\n", x);
	ft_printf("%X\n", x);
	//printf("%X\n", x);
	ft_printf("J'ai eu 10%% d'augmentation\n");
	printf("J'ai eu 10%% d'augmentation\n");
	ft_printf("J'ai eu 10%% d'augmentation\n");
	printf("J'ai eu 10%% d'augmentation\n");
} */
