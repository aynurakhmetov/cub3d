/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_di_print.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmarva <gmarva@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/02 20:09:12 by gmarva            #+#    #+#             */
/*   Updated: 2020/08/13 20:43:06 by gmarva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int	ft_putdi(int num, int fd, int flags, int pr)
{
	if (flags >= 1000 && num == 0 && (!pr || pr == 0))
		return (0);
	ft_putnbr_fd(num, fd);
	return (1);
}

int	ft_ditest(int num, int flags, int pr)
{
	if (flags >= 1000 && num == 0 && (!pr || pr == 0))
		return (0);
	return (1);
}

int	ft_dilen(int n)
{
	int i;

	i = 0;
	if (n == 0)
		return (1);
	if (n < 0)
	{
		i++;
		n = n * (-1);
	}
	while (n != 0)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

int	ft_di_print(va_list *ap, t_prdata data)
{
	int		num;
	int		m;
	int		k;

	k = 0;
	num = va_arg(*ap, int);
	data.length = ft_dilen(num);
	k = ft_ditest(num, data.flags, data.precision);
	if (k == 0)
		data.length--;
	m = 0;
	if (num < 0 && data.width <= data.length &&
			data.precision > 0 && num != -2147483648)
	{
		ft_putchar_fd('-', 1);
		num = num * (-1);
		if (data.width != data.length || data.precision >= data.length)
			m++;
		if (data.width != data.length || data.precision >= data.length)
			data.length--;
	}
	return (di_pr_one(num, data, m, k));
}
