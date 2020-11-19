/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmarva <gmarva@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/22 15:38:31 by gmarva            #+#    #+#             */
/*   Updated: 2020/05/22 17:19:55 by gmarva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list *tmp;

	if (!(tmp = (t_list*)malloc(sizeof(t_list))))
		return (NULL);
	tmp->content = content;
	tmp->next = NULL;
	return (tmp);
}
