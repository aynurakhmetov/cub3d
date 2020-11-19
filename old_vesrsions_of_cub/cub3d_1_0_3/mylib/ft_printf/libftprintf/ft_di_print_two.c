/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_di_print_two.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmarva <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/11 10:38:11 by gmarva            #+#    #+#             */
/*   Updated: 2020/08/13 21:41:09 by gmarva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int	di_pr_one_one(int num, t_prdata data, int len2)
{
	int l;

	l = 0;
	if (data.precision < 0)
	{
		l = data.precision;
		data.precision = 0;
	}
	data.length = len2 + ft_flagnprint(data.width, data.precision, data.length);
	if (l != 0)
		data.precision = l;
	ft_putdi(num, 1, data.flags, data.precision);
	return (data.length);
}

int	di_pr_one(int num, t_prdata data, int m, int k)
{
	int len2;

	len2 = 0;
	if (data.flags % 10 == 0)
	{
		if (num < 0 && num != -2147483648 &&
				(data.width >= data.precision && data.precision >= data.length))
		{
			data.width--;
			if (data.width > data.precision)
			{
				ft_flagnprint(data.width - data.precision, 0, 0);
				len2 = data.width - data.precision;
				data.width = data.precision;
			}
			ft_putchar_fd('-', 1);
			num = num * (-1);
			data.length--;
			m++;
		}
		data.length = di_pr_one_one(num, data, len2);
	}
	return (di_pr_two(num, data, m, k));
}

int	di_pr_two(int num, t_prdata data, int m, int k)
{
	if (num < 0 && num != -2147483648 && (data.width
				>= data.precision && data.precision >= data.length) && m == 0)
	{
		data.width--;
		if (data.width > data.precision && data.flags % 10 != 1)
		{
			ft_flagnprint(data.width - data.precision, 0, 0);
			m = data.width - data.precision;
			data.width = data.precision;
		}
		m++;
		ft_putchar_fd('-', 1);
		num = num * (-1);
		data.length--;
	}
	return (di_pr_two_two(num, data, m, k));
}

int	minus_print(int num, t_prdata data)
{
	if (num < 0 && num != -2147483648
			&& (data.precision < 0 || data.flags < 1000))
	{
		ft_putchar_fd('-', 1);
		num = num * (-1);
	}
	return (num);
}

int	di_pr_three(int num, t_prdata data, int m, int k)
{
	if (data.flags % 10 == 2)
	{
		if (m == 0)
			num = minus_print(num, data);
		if (k == 0 || (data.width > data.length && data.precision
			>= 0 && data.precision <= data.length && data.flags >= 1000))
		{
			if (k == 0)
				data.length = 0;
			data.length = ft_flagnprint(data.width, 0, data.length);
		}
		else if (data.width > data.precision
				&& data.precision > data.length && data.flags >= 1000)
			data.length = ft_flagnprint(data.width,
					data.precision, data.length);
		else
			data.length = ft_flagtprint(data.width, data.length);
		if (data.width <= data.length && data.precision > data.length)
			data.length = data.length + null_print(data.
					precision - data.length);
		k = ft_putdi(num, 1, data.flags, data.precision);
	}
	if (m > 0)
		data.length = data.length + m;
	return (data.length);
}
