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

	i = -1;
	while (all->map[++i])
		free(all->map[i]);
	free(all->map);
	if (all->plr)
		free(all->plr);
	i = -1;
	if (all->dist_wall)
		free(all->dist_wall);
	if (all->sprites)
		free(all->sprites);
	exit(0);
}

void	ft_lstclear_here(t_list **lst)
{
	t_list	*tmp;

	while (*lst)
	{
		tmp = (*lst)->next;
		free(*lst);
		(*lst) = tmp;
	}
}
