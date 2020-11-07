/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmarva <gmarva@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/20 17:32:29 by gmarva            #+#    #+#             */
/*   Updated: 2020/05/30 15:02:36 by gmarva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_trans(int k, int nn, int minus)
{
	char	*str;

	if (!(str = (char *)malloc((k + 1) * sizeof(char))))
		return (NULL);
	str[k] = '\0';
	while (--k >= 0)
	{
		str[k] = (nn % 10) + '0';
		if ((nn == 2147483647) && (minus > 0))
			str[k] = '8';
		nn = (nn - (nn % 10)) / 10;
	}
	if (minus > 0)
		str[0] = '-';
	return (str);
}

char		*ft_itoa(int n)
{
	int		k;
	int		minus;
	int		nn;

	k = 0;
	minus = 0;
	if (n == 0)
		return (ft_trans(1, n, minus));
	if (n < 0)
	{
		minus++;
		if (n == -2147483648)
			n++;
		n = n * (-1);
		k++;
	}
	nn = n;
	while (n > 0)
	{
		n = (n - (n % 10)) / 10;
		k++;
	}
	return (ft_trans(k, nn, minus));
}
