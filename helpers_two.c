/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers_two.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhortens <rhortens@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 20:23:34 by rhortens          #+#    #+#             */
/*   Updated: 2022/12/01 16:51:01 by rhortens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

/*
convert_hex is used to convert the args of unsigned long hex.
as long as hex > 15, recursion is used and hex gets
divided by 16 and modulo 16. 16 because hex has base of 16.
if it is not > 16 anymore, str[hex] will be put out with ft_putchar_fd
*/
void	convert_hex(unsigned long hex, char *str)
{
	if (hex > 15)
	{
		convert_hex(hex / 16, str);
		convert_hex(hex % 16, str);
	}
	else
		ft_putchar_fd(str[hex], 1);
}

/*
hexlen checks the length of unsigned long hex.
therefor a while loop is used and whenever
hex > 0 the hex gets divided by 16 and i is incremented.
*/
int	hexlen(unsigned long hex)
{
	int	i;

	i = 0;
	while (hex > 0)
	{
		hex = hex / 16;
		i++;
	}
	return (i);
}
