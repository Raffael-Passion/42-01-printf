/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arguments_two.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhortens <rhortens@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 20:42:32 by rhortens          #+#    #+#             */
/*   Updated: 2022/12/05 17:41:52 by rhortens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
arg_p is for the void * pointer argument,
which has to be printed in hexadecimal format (base 16).
therefor set unsigned long hex to va_arg with the type (void *).
also set a char *str
and assign it to "0123456789abcdef" for the hexadecimal digits.
fd_putstr_fd("0x") to clarify that the number
that comes afterwards is a hexadecimal.
this is normally not needed (see arg_x or arg_cap_x)
but in this case of args it is needed.
check if hex == 0, then just write "0" and return (3) for "0x0".
otherwise call function convert_hex and return (hexlen + 2) for the size.
*/
int	arg_p(va_list args)
{
	unsigned long	hex;
	char			*str;

	hex = (unsigned long)va_arg(args, void *);
	str = "0123456789abcdef";
	ft_putstr_fd("0x", 1);
	if (hex == 0)
	{
		write(1, "0", 1);
		return (3);
	}
	else
		convert_hex(hex, str);
	return (hexlen(hex) + 2);
}

/*
arg_x is used to print a number in hexadecimal in lowercase format.
therefor str is also set to lowercase "..abcdef".
also check again if hex == 0, then just write "0" and return (1)
otherwise call convert_hex and return hexlen
*/
int	arg_x(va_list args)
{
	unsigned int	hex;
	char			*str;

	hex = va_arg(args, unsigned int);
	str = "0123456789abcdef";
	if (hex == 0)
	{
		write(1, "0", 1);
		return (1);
	}
	else
		convert_hex(hex, str);
	return (hexlen(hex));
}

/*
the only change to arg_x is that str is now set to uppercase
"..ABCDEF" to print a number in hex uppercase format.
*/
int	arg_cap_x(va_list args)
{
	unsigned int	hex;
	char			*str;

	hex = va_arg(args, unsigned int);
	str = "0123456789ABCDEF";
	if (hex == 0)
	{
		write(1, "0", 1);
		return (1);
	}
	else
		convert_hex(hex, str);
	return (hexlen(hex));
}
