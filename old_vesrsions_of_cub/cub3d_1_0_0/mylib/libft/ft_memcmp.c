/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmarva <gmarva@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/08 16:13:15 by gmarva            #+#    #+#             */
/*   Updated: 2020/05/30 14:57:45 by gmarva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *arr1, const void *arr2, size_t n)
{
	unsigned char	*a1;
	unsigned char	*a2;
	size_t			i;

	a1 = (unsigned char *)arr1;
	a2 = (unsigned char *)arr2;
	i = 0;
	while (i < n)
	{
		if (a1[i] > a2[i])
			return (a1[i] - a2[i]);
		if (a1[i] < a2[i])
			return (a1[i] - a2[i]);
		i++;
	}
	return (0);
}
