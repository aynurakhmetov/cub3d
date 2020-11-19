/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_length.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmarva <gmarva@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/02 19:02:58 by gmarva            #+#    #+#             */
/*   Updated: 2020/08/11 11:22:49 by gmarva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int	ft_length(const char *fmt, int i, char type)
{
	int	len;

	len = 0;
	i++;
	while (fmt[i] != type)
	{
		len++;
		i++;
	}
	len++;
	return (len);
}
