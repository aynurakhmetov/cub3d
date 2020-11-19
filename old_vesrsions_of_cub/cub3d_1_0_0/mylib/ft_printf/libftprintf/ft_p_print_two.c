/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_p_print_two.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmarva <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/13 20:59:25 by gmarva            #+#    #+#             */
/*   Updated: 2020/08/13 21:06:25 by gmarva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int	p_flag_print_one(int len, char *s, int k, t_prdata data)
{
	if (data.flags % 10 == 0)
	{
		if (data.precision > data.width && data.precision > data.length)
		{
			ft_putstr_fd("0x", 1);
			k++;
		}
		if (k == 0)
			len = len + 2;
		if (s != 0)
			len = ft_flagnprint(data.width, data.precision, len);
		else
			len = ft_flagnprint(data.width, data.precision, 2);
		if (k == 0)
			ft_putstr_fd("0x", 1);
		else
			len = len + 2;
		if (s != 0)
			ft_putstr_fd(s, 1);
	}
	len = p_flag_print(len, s, data);
	return (len);
}
