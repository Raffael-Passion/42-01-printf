/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhortens <rhortens@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 14:17:24 by rhortens          #+#    #+#             */
/*   Updated: 2022/11/25 17:58:21 by rhortens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <printf.h>
#include <libft.h>
#include <stdarg.h>

int	check(const char *str, va_list args)
{
	int	i;

	i = 0;
	while (str && str[i])
	{
		if (str[i] == '%')
		{
			i++;
			ft_format(str[i]);
		}
	}
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		size;

	if (str == NULL)
		return (NULL);
	va_start (args, str);
	size = check(str, args);
	va_end (args);
	return (size);
}
