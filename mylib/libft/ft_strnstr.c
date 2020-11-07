/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmarva <gmarva@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/13 19:49:47 by gmarva            #+#    #+#             */
/*   Updated: 2020/05/30 15:08:49 by gmarva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	lenlit;
	size_t	i;

	i = 0;
	lenlit = ft_strlen(little);
	if (!lenlit)
		return ((char *)big);
	if (len == 0)
		return (NULL);
	while ((len--) >= lenlit && big[i] != '\0')
	{
		if (big[i] == little[0])
		{
			if (ft_memcmp(&big[i], little, lenlit) == 0)
				return ((char *)&big[i]);
		}
		i++;
	}
	return (NULL);
}
