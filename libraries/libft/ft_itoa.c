/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcaro-ro <mcaro-ro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 16:47:52 by mcaro-ro          #+#    #+#             */
/*   Updated: 2024/02/27 13:01:34 by mcaro-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_countdigits(long num)
{
	size_t	count;

	count = 0;
	if (num <= 0)
	{
		num = num * -1;
		count++;
	}
	while (num > 0)
	{
		num = num / 10;
		count++;
	}
	return (count);
}

static char	*ft_setstr(char *str, long num, size_t count)
{
	str[count--] = '\0';
	if (num < 0)
	{
		num = num * -1;
		str[0] = '-';
	}
	if (num == 0)
		str[0] = '0';
	while (num)
	{
		str[count] = num % 10 + '0';
		num = num / 10;
		count--;
	}
	return (str);
}

char	*ft_itoa(int n)
{
	char	*str;
	size_t	count;

	count = ft_countdigits(n);
	str = ft_calloc(count + 1, sizeof(char));
	if (str)
	{
		ft_setstr(str, n, count);
		return (str);
	}
	return (NULL);
}
