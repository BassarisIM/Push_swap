/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_fd.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohollar <sohollar@student.42paris.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 19:06:40 by sohollar          #+#    #+#             */
/*   Updated: 2026/02/17 22:04:37 by sohollar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_FD_H
# define FT_PRINTF_FD_H
# include <stdarg.h>
# include <unistd.h>

int	ft_printf_fd(int fd, const char *s, ...);
int	ft_putstr_r_fd(char *s, int fd);
int	ft_putnbr_r_fd(int n, int fd);
int	ft_isinset(const char *s, char c);
int	ft_puthh_fd(unsigned int n, int fd);
int	ft_puthl_fd(unsigned int n, int fd);
int	ft_putptr_fd(unsigned long p, int fd);

#endif
