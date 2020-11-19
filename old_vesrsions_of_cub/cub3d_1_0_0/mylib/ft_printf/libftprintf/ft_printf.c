/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmarva <gmarva@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/27 19:17:24 by gmarva            #+#    #+#             */
/*   Updated: 2020/08/12 16:26:08 by gmarva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int	ft_pf(t_prdata data, va_list *ap, const char *format, size_t i)
{
	int len;

	len = 0;
	while (format[i] != 0 && i < ft_strlen(format))
	{
		if (format[i] == '%')
		{
			data = ft_parser(format, i);
			i = i + data.length + 1;
			if (data.type != 0)
				len = len + ft_process(ap, data);
			if (data.type == 0 && data.length > 0)
			{
				write(1, &format[i - 1], 1);
				len++;
			}
		}
		if (format[i] == '%' || i == ft_strlen(format))
			continue ;
		write(1, &format[i], 1);
		len++;
		i++;
	}
	return (len);
}

int	ft_printf(const char *format, ...)
{
	va_list		ap;
	size_t		i;
	t_prdata	data;
	int			len;

	i = 0;
	data.length = 0;
	va_start(ap, format);
	len = ft_pf(data, &ap, format, i);
	va_end(ap);
	return (len);
}
