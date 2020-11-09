# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gmarva <gmarva@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/10/19 17:09:12 by gmarva            #+#    #+#              #
#    Updated: 2020/11/08 18:06:02 by gmarva           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

all:
	gcc -Wall -Wextra -Werror libmlx.dylib -framework \
	OpenGL -framework Appkit -o cub3d \
	./srcs/main.c \
	./srcs/ft_map_parser.c \
	./srcs/ft_map_parser_two.c \
	./srcs/ft_map_parser_three.c \
	./srcs/ft_map_check.c \
	./srcs/ft_start.c \
	./srcs/ft_get_info.c \
	./srcs/ft_raycasting.c \
	./srcs/ft_drawing.c \
	./srcs/ft_make_wall.c \
	./srcs/ft_make_sprite.c \
	./srcs/ft_make_screenshote.c \
	./srcs/ft_keyboard.c \
	./srcs/ft_finish.c \
	mylib/libft/libft.a mylib/gnl/get_next_line.c mylib/gnl/get_next_line_utils.c

gcc: all
	./cub3d ./maps/map.cub

save: all
	./cub3d ./maps/map.cub --save

norma:
	norminette ./srcs/ ./mylib/libft/*.c ./mylib/libft/*.h ./mylib/gnl/ ./includes/