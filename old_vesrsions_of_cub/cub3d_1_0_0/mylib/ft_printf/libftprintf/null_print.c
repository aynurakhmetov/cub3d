/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   null_print.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmarva <gmarva@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/02 20:07:51 by gmarva            #+#    #+#             */
/*   Updated: 2020/08/11 12:13:04 by gmarva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	null_print(int n)
{
	int i;

	i = 0;
	while (i < n)
	{
		ft_putchar_fd('0', 1);
		i++;
	}
	return (i);
}

int	ft_utest(uintmax_t num, int flags, int pr)
{
	if (flags >= 1000 && num == 0 && (!pr || pr == 0))
		return (0);
	return (1);
}
