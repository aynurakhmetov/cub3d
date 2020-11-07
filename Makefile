# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gmarva <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/10/19 17:09:12 by gmarva            #+#    #+#              #
#    Updated: 2020/11/07 18:15:13 by gmarva           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

all:
	gcc -Wall -Wextra -Werror libmlx.dylib -framework \
	OpenGL -framework Appkit -o test \
	./srcs/main.c ./srcs/ft_drawing.c ./srcs/ft_make_sprite.c ./srcs/ft_map_check.c \
	./srcs/ft_map_parser.c ./srcs/ft_start_game.c ./srcs/ft_keyboard.c ./srcs/ft_get_info.c \
	./srcs/ft_raycasting.c ./srcs/ft_make_screenshote.c \
	mylib/libft/libft.a mylib/gnl/get_next_line.c mylib/gnl/get_next_line_utils.c

gcc: all
	./test ./maps/map.cub

save: all
	./test ./maps/map.cub --save
