/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhortens <rhortens@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 18:15:15 by rhortens          #+#    #+#             */
/*   Updated: 2022/12/01 17:31:53 by rhortens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <stdarg.h>
# include <stdio.h>

int		arg_c(va_list args);
int		arg_s(va_list args);
int		arg_di(va_list args);
int		arg_u(va_list args);
int		arg_p(va_list args);
int		arg_x(va_list args);
int		arg_cap_x(va_list args);
int		ft_format(const char *str, int i, va_list args);
int		ft_printf(const char *str, ...);
void	ft_putnbr_u(unsigned int n);
void	convert_hex(unsigned long hex, char *str);
int		hexlen(unsigned long hex);
void	ft_putchar_fd(char c, int fd);
void	ft_putnbr_fd(int n, int fd);
void	ft_putstr_fd(char *s, int fd);
size_t	ft_strlen(const char *str);

#endif