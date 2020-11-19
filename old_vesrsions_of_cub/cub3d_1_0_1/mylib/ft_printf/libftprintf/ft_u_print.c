/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_u_print.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmarva <gmarva@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/02 19:51:05 by gmarva            #+#    #+#             */
/*   Updated: 2020/08/13 21:17:07 by gmarva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int	ft_putnbru_fd(uintmax_t n, int fd)
{
	if (n > 9)
		ft_putnbru_fd(n / 10, fd);
	ft_putchar_fd((n % 10) + '0', fd);
	return (1);
}

int	ft_ulen(unsigned int n)
{
	int i;

	i = 0;
	if (n == 0)
		return (1);
	while (n != 0)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

int	u_flag_print(uintmax_t num, int len, int k, t_prdata data)
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
			ft_putnbru_fd(num, 1);
	}
	return (len);
}

int	ft_u_print(va_list *ap, t_prdata data)
{
	int				len;
	unsigned int	num;
	int				k;

	num = (unsigned int)va_arg(*ap, unsigned int);
	num = (uintmax_t)num;
	len = ft_ulen(num);
	k = ft_utest(num, data.flags, data.precision);
	if (k == 0)
		len--;
	if (data.flags % 10 == 0)
	{
		if (data.precision < 0)
			data.precision = 0;
		len = ft_flagnprint(data.width, data.precision, len);
		if (k != 0)
			ft_putnbru_fd(num, 1);
	}
	return (ft_u_two(len, num, k, data));
}

int	ft_u_two(int len, unsigned int num, int k, t_prdata data)
{
	if (data.flags % 10 == 1)
	{
		if (data.precision > len)
			len = wp_print(0, data.precision, len);
		if (k != 0)
			ft_putnbru_fd(num, 1);
		len = wp_print(data.width, data.precision, len);
	}
	len = u_flag_print(num, len, k, data);
	return (len);
}
