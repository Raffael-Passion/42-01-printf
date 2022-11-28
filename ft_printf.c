/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhortens <rhortens@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 14:17:24 by rhortens          #+#    #+#             */
/*   Updated: 2022/11/28 20:01:42 by rhortens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <printf.h>
#include <libft.h>
#include <stdarg.h>

int	ft_format(const char *str, int i, va_list args)
{
	int	size;

	size = 0;
	if (str[i] == 'c')
		size += arg_c(args);
	else if (str[i] == 's')
		size += arg_s(args);
	else if (str[i] == 'p')
		size += arg_p(args);
	else if (str[i] == 'd' || str[i] == 'i')
		size += arg_di(args);
	else if (str[i] == 'u')
		size += arg_u(args);
	else if (str[i] == 'x')
		size += arg_x(args);
	else if (str[i] == 'X')
		size += arg_cap_x(args);
	else if (str[i] == '%')
	{
		ft_putchar("%");
		size = 1;
	}
	return (size);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		size;
	int		i;

	if (str == NULL)
		return (NULL);
	va_start (args, str);
	i = 0;
	size = 0;
	while (str[i])
	{
		if (str[i] == '%')
		{
			i++;
			size += ft_format(str, i, args);
		}
		else
		{
			ft_putchar(str[i]);
			size++;
		}
		i++;
	}
	va_end (args);
	return (size);
}
