/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_type.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmarva <gmarva@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/02 20:57:42 by gmarva            #+#    #+#             */
/*   Updated: 2020/08/12 15:50:03 by gmarva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

char	ft_type(const char *fmt, int i)
{
	i++;
	while (fmt[i] && fmt[i] != '%')
	{
		if (fmt[i] == 'c')
			return ('c');
		if (fmt[i] == 's')
			return ('s');
		if (fmt[i] == 'u')
			return ('u');
		if (fmt[i] == 'p')
			return ('p');
		if (fmt[i] == 'd')
			return ('d');
		if (fmt[i] == 'i')
			return ('i');
		if (fmt[i] == 'x')
			return ('x');
		if (fmt[i] == 'X')
			return ('X');
		i++;
	}
	return (0);
}
