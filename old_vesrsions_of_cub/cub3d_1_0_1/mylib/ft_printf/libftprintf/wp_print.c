/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wp_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmarva <gmarva@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/02 21:07:22 by gmarva            #+#    #+#             */
/*   Updated: 2020/08/11 12:06:43 by gmarva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int	ft_wp(int n, int k, int len, int i)
{
	if ((n > 0 && k == 0) || (n > k && k <= len))
	{
		while (i < n - len)
		{
			ft_putchar_fd(' ', 1);
			i++;
		}
	}
	if (n >= 0 && k > 0 && k >= n && k > len)
	{
		null_print(k - len);
		i = k - len;
	}
	if (n > 0 && k > 0 && n > k && k > len)
	{
		while (i < n - k)
		{
			ft_putchar_fd(' ', 1);
			i++;
		}
		null_print(k - len);
		i = i + (k - len);
	}
	return (i + len);
}

int	wp_print(int n, int k, int len)
{
	int i;

	i = 0;
	return (ft_wp(n, k, len, i));
}

int	ft_flagnprint(int w, int p, int len)
{
	if (w >= 0 && p >= 0 && w > len)
		len = wp_print(w, p, len);
	if (p >= 0 && w <= len)
		len = wp_print(0, p, len);
	return (len);
}

int	ft_flagtprint(int w, int len)
{
	if (w >= 0 && w >= len)
	{
		null_print(w - len);
		len = w;
	}
	return (len);
}

int	ft_xtest(unsigned int num, int flags, int pr)
{
	if (flags >= 1000 && num == 0 && (!pr || pr == 0))
		return (0);
	return (1);
}
