/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_di_print_three.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmarva <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/13 21:31:53 by gmarva            #+#    #+#             */
/*   Updated: 2020/08/13 21:39:43 by gmarva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int	di_pr_two_two(int num, t_prdata data, int m, int k)
{
	if (data.flags % 10 == 1)
	{
		if (data.precision > data.length)
			data.length = wp_print(0, data.precision, data.length);
		k = ft_putdi(num, 1, data.flags, data.precision);
		if (data.precision < 0)
			data.precision = 0;
		if (data.width > data.length)
			data.length = wp_print(data.width, data.precision, data.length);
	}
	return (di_pr_three(num, data, m, k));
}
