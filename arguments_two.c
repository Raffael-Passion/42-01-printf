/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arguments_two.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhortens <rhortens@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 20:42:32 by rhortens          #+#    #+#             */
/*   Updated: 2022/11/28 20:53:20 by rhortens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <printf.h>
#include <libft.h>
#include <stdarg.h>

int	arg_p(va_list args)
{
	unsigned long	hex;
	char			*str;

	hex = (unsigned long)va_arg(args, void *);
	str = "0123456789abcdef";
	ft_putchar("0x");
	if (hex == 0)
	{
		ft_putchar("0");
		return (3);
	}
	else
		convert_hex(hex, str);
	return (hexlen(hex) + 2);
}

int	arg_x(va_list args)
{
	unsigned int	hex;
	char			*str;

	hex = va_arg(args, unsigned int);
	str = "0123456789abcdef";
	if (hex == 0)
	{
		ft_putchar("0");
		return (1);
	}
	else
		convert_hex(hex, str);
	return (hexlen(hex));
}

int	arg_cap_x(va_list args)
{
	unsigned int	hex;
	char			*str;

	hex = va_arg(args, unsigned int);
	str = "0123456789ABCDEF";
	if (hex == 0)
	{
		ft_putchar("0");
		return (1);
	}
	else
		convert_hex(hex, str);
	return (hexlen(hex));
}
