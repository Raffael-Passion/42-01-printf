/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers_two.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhortens <rhortens@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 20:23:34 by rhortens          #+#    #+#             */
/*   Updated: 2022/11/30 20:05:19 by rhortens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

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
