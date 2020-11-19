/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_process.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmarva <gmarva@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/02 21:38:21 by gmarva            #+#    #+#             */
/*   Updated: 2020/08/12 15:32:29 by gmarva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int	ft_process(va_list *ap, t_prdata data)
{
	int k;

	k = 0;
	if (data.flags >= 1000)
	{
		data.flags = data.flags - 1000;
		k++;
	}
	if (data.flags >= 10 && data.flags < 100)
	{
		data.width = va_arg(*ap, int);
		if (data.width < 0)
		{
			if (data.flags % 10 != 1)
			{
				if (data.flags % 10 == 2)
					data.flags = data.flags - 2;
				data.flags = data.flags + 1;
			}
			data.width = data.width * (-1);
		}
	}
	return (ft_proc_two(ap, data, k));
}

int	ft_proc_two(va_list *ap, t_prdata data, int k)
{
	if (data.flags >= 100 && data.flags < 110)
	{
		data.precision = va_arg(*ap, int);
	}
	if (data.flags >= 110)
	{
		data.width = va_arg(*ap, int);
		if (data.width < 0)
		{
			if (data.flags % 10 != 1)
			{
				if (data.flags % 10 == 2)
					data.flags = data.flags - 2;
				data.flags = data.flags + 1;
			}
			data.width = data.width * (-1);
		}
		data.precision = va_arg(*ap, int);
	}
	if (k > 0)
		data.flags = data.flags + 1000;
	return (ft_typeprint(ap, data));
}
