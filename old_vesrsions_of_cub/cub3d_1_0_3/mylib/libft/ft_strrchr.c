/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmarva <gmarva@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/11 22:03:29 by gmarva            #+#    #+#             */
/*   Updated: 2020/05/30 15:01:50 by gmarva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int ch)
{
	int	i;

	i = ft_strlen(str);
	if (ch == '\0')
		return ((char*)&str[i]);
	i--;
	while (str[i] != ch && i > 0)
		i--;
	if (str[i] == ch)
		return ((char *)&str[i]);
	return (NULL);
}
