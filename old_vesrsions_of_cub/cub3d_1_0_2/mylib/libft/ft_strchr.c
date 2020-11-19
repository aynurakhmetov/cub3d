/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmarva <gmarva@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/11 21:16:47 by gmarva            #+#    #+#             */
/*   Updated: 2020/05/15 14:32:49 by gmarva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *str, int ch)
{
	int	i;

	i = 0;
	while (str[i] != ch)
	{
		if (str[i] == '\0')
			return (NULL);
		i++;
	}
	if (str[i] == ch)
		return ((char *)&str[i]);
	return (NULL);
}
