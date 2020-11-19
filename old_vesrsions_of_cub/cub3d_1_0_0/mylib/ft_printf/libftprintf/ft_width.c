/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_width.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmarva <gmarva@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/02 21:00:17 by gmarva            #+#    #+#             */
/*   Updated: 2020/08/12 16:12:50 by gmarva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int	ft_width(const char *fmt, int i, char type)
{
	int width;
	int k;

	width = 0;
	k = 0;
	i++;
	while (fmt[i] != type && fmt[i] != '.')
	{
		if ((fmt[i] >= '0') && (fmt[i] <= '9'))
		{
			k++;
			if (k > 1)
				width = width * 10;
			width = width + (fmt[i] - '0');
		}
		i++;
	}
	return (width);
}
