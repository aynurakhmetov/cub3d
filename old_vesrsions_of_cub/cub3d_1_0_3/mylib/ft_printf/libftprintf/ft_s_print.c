/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_s_print.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmarva <gmarva@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/02 19:39:29 by gmarva            #+#    #+#             */
/*   Updated: 2020/08/13 21:11:38 by gmarva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	s_print(char *s, int n)
{
	int i;

	i = 0;
	while (i < n)
	{
		write(1, &s[i], 1);
		i++;
	}
}

int		s_flags_print(char *s, int len, int k, t_prdata data)
{
	if (data.width > len)
		k = wp_print(data.width, 0, len);
	else
		k = len;
	s_print(s, len);
	len = k;
	return (len);
}

int		s_flags_two_print(char *s, int len, t_prdata data)
{
	s_print(s, len);
	if (data.width > len)
		len = wp_print(data.width, 0, len);
	return (len);
}

int		ft_s_print(va_list *ap, t_prdata data)
{
	char	*s;
	int		len;
	int		k;

	s = va_arg(*ap, char*);
	if (s == NULL)
		s = "(null)";
	len = strlen(s);
	k = len;
	if (data.flags >= 1000 &&
			(data.precision == 0 || !data.precision) && !data.width)
		return (0);
	if (data.precision > 0 && data.precision < len)
		len = data.precision;
	if (data.flags >= 1000 && (data.precision == 0 || !data.precision))
		len = 0;
	if (data.flags % 10 == 0 || data.flags % 10 == 2)
		len = s_flags_print(s, len, k, data);
	if (data.flags % 10 == 1)
		len = s_flags_two_print(s, len, data);
	return (len);
}
