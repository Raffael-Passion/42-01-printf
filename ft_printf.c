/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhortens <rhortens@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 14:17:24 by rhortens          #+#    #+#             */
/*   Updated: 2022/12/01 13:26:23 by rhortens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

/*
ft_format checks the char after the percent sign, which describes the conversion we will be handling.
after getting the if statement right, proceed to the function, where argument will be handled.
Alway return size after getting the value, e.g. with size = size + arg_c(args).
*/
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
		ft_putstr_fd("%", 1);
		size = 1;
	}
	return (size);
}

/*
ft_printf starts with defining the variadic arguments using va_list and va_start. 
va_list holds the information needed by the macros va_start, va_arg, va_end.
va_start = access to variadic function args taking the fixed arg as input and start to iterate in function args.
while having a str, check if it is % and then move to ft_format after incrementing. Otherwise putchar and size++.
va_arg obtains the current variadic function arg and advances to the next location in stack.
va_end ends the traversal of the variadic function arguments.
return size in the end.
*/
int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		size;
	int		i;

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
			ft_putchar_fd(str[i], 1);
			size++;
		}
		i++;
	}
	va_end (args);
	return (size);
}

/*
int	main(int argc, char **argv)
{
	test_zero();
	test_space();
	test_plus();
	test_space_plus();

	test_precision();
	test_width();
	test_width_and_precision();

	test_unsigned_int();
	test_unsigned_hex();
	test_char();
	test_pointer();
	test_string();
	test_big_num();

	return (0);
}
*/