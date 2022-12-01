/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arguments_one.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhortens <rhortens@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 17:54:06 by rhortens          #+#    #+#             */
/*   Updated: 2022/12/01 12:33:00 by rhortens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

int	arg_c(va_list args)
{
	char	c;

	c = va_arg(args, int);
	ft_putchar_fd(c, 1);
	return (1);
}

int	arg_s(va_list args)
{
	char	*str;
	int		i;

	str = va_arg(args, char *);
	i = 0;
	if (str)
	{
		while (str[i] != 0)
		{
			ft_putchar_fd(str[i], 1);
			i++;
		}
	}
	else
	{
		ft_putstr_fd("(null)", 1);
		return (6);
	}
	return (ft_strlen(str));
}

int	arg_di(va_list args)
{
	int	d;
	int	i;

	d = va_arg(args, int);
	i = 0;
	ft_putnbr_fd(d, 1);
	if (d == 0)
		i++;
	if (d < 0)
	{
		i++;
		d *= -1;
	}
	while (d)
	{
		d = d / 10;
		i++;
	}
	return (i);
}

int	arg_u(va_list args)
{
	unsigned int	n;
	int				i;

	n = va_arg(args, unsigned int);
	i = 0;
	ft_putnbr_u(n);
	if (n == 0)
		i++;
	while (n)
	{
		n = n / 10;
		i++;
	}
	return (i);
}
