/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmarva <gmarva@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/15 14:44:28 by gmarva            #+#    #+#             */
/*   Updated: 2020/05/30 14:59:12 by gmarva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *str)
{
	size_t	len;
	size_t	j;
	char	*dup;

	j = 0;
	len = ft_strlen(str);
	if (!(dup = (char *)malloc((len + 1) * sizeof(char))))
		return (NULL);
	while (j < len)
	{
		dup[j] = str[j];
		j++;
	}
	dup[j] = '\0';
	return (dup);
}
