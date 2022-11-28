/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arguments_one.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhortens <rhortens@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 17:54:06 by rhortens          #+#    #+#             */
/*   Updated: 2022/11/28 20:48:59 by rhortens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <printf.h>
#include <libft.h>
#include <stdarg.h>

int	arg_c(va_list args)
{
	char	c;

	c = va_arg(args, int);
	ft_putchar(c);
	return (1);
}

int	arg_s(va_list args)
{
	char	*str;
	int		i;

	str = va_arg(args, char *);
	i = 0;
	if (str && str[i] != 0)
	{
		ft_putchar(str[i]);
		i++;
	}
	else
	{
		ft_putchar("NULL");
		return (4);
	}
	return (ft_strlen(str));
}

int	arg_di(va_list args)
{
	int	d;
	int	i;

	d = va_arg(args, int);
	i = 0;
	ft_putnbr(d);
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
	unsigned int	u;
	int				i;

	u = va_arg(args, unsigned int);
	i = 0;
	ft_putnbr_u(u);
	if (u == 0)
		i++;
	while (u)
	{
		u = u / 10;
		i++;
	}
	return (i);
}
