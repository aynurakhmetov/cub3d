/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmarva <gmarva@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/07 15:38:14 by gmarva            #+#    #+#             */
/*   Updated: 2020/05/30 14:54:13 by gmarva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *des, const void *src, size_t n)
{
	unsigned char	*s;
	unsigned char	*r;
	size_t			i;

	if (!des && !src)
		return (NULL);
	s = (unsigned char *)des;
	r = (unsigned char *)src;
	i = 0;
	while (i < n)
	{
		s[i] = r[i];
		i++;
	}
	return (des);
}
