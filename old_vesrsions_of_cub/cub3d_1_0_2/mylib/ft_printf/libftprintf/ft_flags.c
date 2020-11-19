/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmarva <gmarva@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/02 21:24:23 by gmarva            #+#    #+#             */
/*   Updated: 2020/08/13 20:25:45 by gmarva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int	ft_flags_two(const char *fmt, int i, int res, char type)
{
	i++;
	while (fmt[i] != type)
	{
		if (fmt[i] == '-')
		{
			if (res % 10 == 2)
				res = res - 2;
			return (res + 1);
		}
		if (fmt[i] == '0' && fmt[i - 1] != '.' && res % 10 != 2
				&& (fmt[i - 1] == '%' || fmt[i - 1] == '-'))
			res = res + 2;
		i++;
	}
	return (res);
}

int	ft_flags(const char *fmt, int i, char type)
{
	int res;
	int j;

	res = 0;
	j = i;
	while (fmt[++j] != type)
	{
		if (fmt[j] == '*' && fmt[j - 1] != '.')
			res = 10;
		if (fmt[j] == '.' && (fmt[j + 1] == '*'))
			res = res + 100;
		if (fmt[j] == '.')
			res = res + 1000;
	}
	return (ft_flags_two(fmt, i, res, type));
}
