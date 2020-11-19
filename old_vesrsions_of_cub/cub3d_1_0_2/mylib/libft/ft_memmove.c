/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmarva <gmarva@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/07 17:00:09 by gmarva            #+#    #+#             */
/*   Updated: 2020/05/30 14:56:04 by gmarva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *des, const void *src, size_t n)
{
	unsigned char	*to;
	unsigned char	*from;
	size_t			i;

	i = 0;
	if (!des && !src)
		return (NULL);
	to = (unsigned char *)des;
	from = (unsigned char *)src;
	if (to < from)
	{
		while (i < n)
		{
			to[i] = from[i];
			i++;
		}
	}
	if (to > from)
	{
		while (n-- > 0)
			to[n] = from[n];
	}
	return (des);
}
