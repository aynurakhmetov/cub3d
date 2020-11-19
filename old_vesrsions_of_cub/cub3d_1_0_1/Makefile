# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gmarva <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/10/19 17:09:12 by gmarva            #+#    #+#              #
#    Updated: 2020/10/19 17:09:19 by gmarva           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

all:
	gcc -Wall -Wextra -Werror libmlx.dylib -framework \
	OpenGL -framework Appkit -o test main.c ft_drawing.c sprite.c \
	ft_map_parser.c ft_start_game.c ft_keyboard.c ft_get_info.c ft_raycasting.c \
	mylib/libft/libft.a mylib/gnl/get_next_line.c mylib/gnl/get_next_line_utils.c
	./test map.cub