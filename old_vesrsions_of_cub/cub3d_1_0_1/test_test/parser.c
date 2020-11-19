/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmarva <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/19 16:25:23 by gmarva            #+#    #+#             */
/*   Updated: 2020/10/19 16:25:26 by gmarva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mylib/libft/libft.h"
#include "mylib/gnl/get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

// Парсить в двумерный массив
// Проверять на валидность (игрок в стене, два игрока, остутствие, нет стены), цвет

void make_map(t_list **head, int size)
{
    char **map;
    int i;
    t_list *tmp;

    map = ft_calloc(size + 1, sizeof(char *));
    i = 0;
    tmp = *head;

    while (tmp)
    {
        map[i] = tmp->content;
        tmp = tmp->next;
        i++;
    }
    i = 0;
    while (map[i])
    {
        ft_putendl_fd(map[i], 1);
        i++;
    }
}
int main(int argc, char *argv[])
{
    int fd;
    char *line;
    t_list *head;

    if (argc != 2)
        return (0);
    fd = open(argv[1], O_RDONLY);
    line = NULL;
    head = NULL;    
    while (get_next_line(fd, &line))
    {
        ft_lstadd_back(&head, ft_lstnew(line));
    }
    ft_lstadd_back(&head, ft_lstnew(line));
    make_map(&head, ft_lstsize(head));
    return (0);
}