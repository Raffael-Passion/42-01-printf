/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhortens <rhortens@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 14:50:36 by rhortens          #+#    #+#             */
/*   Updated: 2022/11/08 16:45:50 by rhortens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *str, int c)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == (unsigned char)c)
			return ((char *)str + i);
		else
			i++;
	}
	if (str[i] == (unsigned char)c)
	{
		return ((char *)str + i);
	}
	return (0);
}
