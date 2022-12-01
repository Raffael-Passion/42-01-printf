/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arguments_one.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhortens <rhortens@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 17:54:06 by rhortens          #+#    #+#             */
/*   Updated: 2022/12/01 16:48:43 by rhortens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

/*
arg_c of pointer to the list of arguments:
set a char c to va_arg of the pointer with the type int to print
a single character with ft_putchar.
*/
int	arg_c(va_list args)
{
	char	c;

	c = va_arg(args, int);
	ft_putchar_fd(c, 1);
	return (1);
}

/*
arg_s of pointer to the list of arguments:
set *str to va_arg(args and type char *).
afterwards check if (str) otherwise just put out
null with ft_putstr_fd and size i of 6 returned.
if (str) go in while loop and put out every str[i],
while incrementing i. After that return strlen of str.
*/
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

/*
arg_di is for d (decimal(base 10) number) and i (integer in base 10).
So those 2 args can be handled in one function.
int d is set to va_arg(args, int) and
ft_putnbr_fd is called to output all args.
afterwards check if d == 0, smaller than 0 and
while(d) to incement i for the right size to return.
*/
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

/*
arg_u is for an unsigned decimal base 10 number.
almost same as with arg_i, but it's just for unsigned int,
so ft_putnbr_fd can be shortened to ft_putnbr_u.
ft_putnbr_u is called to output all args
and after that follow same procedure as above to increment i.
*/
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
