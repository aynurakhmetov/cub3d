/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_finish.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmarva <gmarva@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/07 18:47:26 by gmarva            #+#    #+#             */
/*   Updated: 2020/11/08 19:04:35 by gmarva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../includes/cub3d.h"

void	ft_exit(char *errormassage)
{
	ft_putendl_fd("Error", 1);
	ft_putendl_fd(errormassage, 1);
	exit(0);
}

void	ft_exit_identifier(char *errormassage, char *identifier)
{
	ft_putendl_fd("Error", 1);
	ft_putstr_fd(errormassage, 1);
	ft_putendl_fd(identifier, 1);
	exit(0);
}

int		ft_finish_game(t_all *all)
{
	int i;

	i = 0;
	if (all->map[i])
	{
		while (all->map[i])
		{
			free(all->map[i]);
			i++;
		}
		free(all->map[i]);
	}
	exit(0);
}

void	ft_lstclear_here(t_list **lst)
{
	t_list	*tmp;

	while (*lst)
	{
		tmp = (*lst)->next;
		//free((*lst)->content);
		free(*lst);
		(*lst) = tmp;
	}
}

void	ft_free_array(char **str)
{
	int i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	//free(str);
}
