/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_x_print.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmarva <gmarva@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/02 21:47:00 by gmarva            #+#    #+#             */
/*   Updated: 2020/08/13 21:19:09 by gmarva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int			ft_xlen(unsigned int n)
{
	int i;

	i = 0;
	if (n == 0)
		return (1);
	while (n != 0)
	{
		n = n / 16;
		i++;
	}
	return (i);
}

int			x_print(unsigned int num, char type)
{
	char *x;

	x = NULL;
	if (num >= 16)
		return (x_print(num / 16, type) + x_print(num % 16, type));
	else
	{
		if (type == 'x')
			x = ft_strdup("0123456789abcdef");
		if (type == 'X')
			x = ft_strdup("0123456789ABCDEF");
		write(1, &x[num], 1);
		if (x)
			free(x);
		return (1);
	}
}

int			x_flag_print(int len, int k, unsigned int num, t_prdata data)
{
	if (data.flags % 10 == 0)
	{
		if (data.precision < 0)
			data.precision = 0;
		len = ft_flagnprint(data.width, data.precision, len);
		if (k != 0)
			x_print(num, data.type);
	}
	return (x_flag_two_print(len, k, num, data));
}

int			x_flag_two_print(int len, int k, unsigned int num, t_prdata data)
{
	if (data.flags % 10 == 2)
	{
		if (k == 0 || (data.width > len && data.precision >= 0
					&& data.precision <= len && data.flags >= 1000))
		{
			if (k == 0)
				len = 0;
			len = ft_flagnprint(data.width, 0, len);
		}
		else if (data.width > data.precision
				&& data.precision > len && data.flags >= 1000)
			len = ft_flagnprint(data.width, data.precision, len);
		else
			len = ft_flagtprint(data.width, len);
		if (data.width <= len && data.precision > len)
			len = len + null_print(data.precision - len);
		if (k != 0)
			x_print(num, data.type);
	}
	return (len);
}

int			ft_x_print(va_list *ap, t_prdata data)
{
	int				len;
	unsigned int	num;
	int				k;

	k = 1;
	num = va_arg(*ap, unsigned int);
	len = ft_xlen(num);
	k = ft_xtest(num, data.flags, data.precision);
	if (k == 0)
		len--;
	if (data.flags % 10 == 1)
	{
		if (data.precision > len)
			len = wp_print(0, data.precision, len);
		if (k != 0)
			x_print(num, data.type);
		len = wp_print(data.width, data.precision, len);
	}
	len = x_flag_print(len, k, num, data);
	return (len);
}
