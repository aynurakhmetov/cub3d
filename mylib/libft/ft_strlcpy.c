/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmarva <gmarva@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/11 16:14:39 by gmarva            #+#    #+#             */
/*   Updated: 2020/05/30 14:58:29 by gmarva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *des, const char *src, size_t size)
{
	size_t	lens;
	size_t	i;

	i = 0;
	lens = ft_strlen(src);
	if (!des)
		return (0);
	if (size == 0)
		return (lens);
	while ((i < size - 1) && (src[i] != '\0'))
	{
		des[i] = src[i];
		i++;
	}
	des[i] = '\0';
	return (lens);
}
