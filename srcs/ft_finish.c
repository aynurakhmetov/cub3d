/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_finish.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmarva <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/07 18:47:26 by gmarva            #+#    #+#             */
/*   Updated: 2020/11/07 18:47:28 by gmarva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../includes/cub3d.h"

void ft_exit(char *errormassage)
{
	ft_putendl_fd("error", 1);
	ft_putendl_fd(errormassage, 1);
	exit(0);
}

void ft_exit_identifier(char *errormassage, char *identifier)
{
	ft_putendl_fd("error", 1);
	ft_putstr_fd(errormassage, 1);
    ft_putendl_fd(identifier, 1);
    exit (0);
}

int ft_finish_game(t_all *all)
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