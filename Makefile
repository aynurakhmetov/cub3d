# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gmarva <gmarva@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/10/19 17:09:12 by gmarva            #+#    #+#              #
#    Updated: 2020/11/09 21:28:21 by gmarva           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3d
FLAG_MLX = -framework OpenGL -framework Appkit
FLAG_GCC = -Wall -Wextra -Werror
GNL_FUNC = get_next_line.c get_next_line_utils.c
CUB_FUNC = main.c \
			ft_map_parser.c \
			ft_map_parser_two.c \
			ft_map_parser_three.c \
			ft_map_check.c \
			ft_map_check_two.c \
			ft_start.c \
			ft_get_info.c \
			ft_raycasting.c \
			ft_drawing.c \
			ft_make_wall.c \
			ft_make_sprite.c \
			ft_make_screenshote.c \
			ft_keyboard.c \
			ft_finish.c \

HEADER = includes
SOURCES = srcs
GNL = mylib/gnl
OBJ = objects

FILES_C = $(addprefix $(SOURCES)/,$(CUB_FUNC)) $(addprefix $(GNL)/,$(GNL_FUNC))
FILES_O = $(addprefix $(OBJ)/,$(CUB_FUNC:.c=.o)) $(addprefix $(GNL)/,$(GNL_FUNC:.c=.o))

all: $(NAME)
	@mkdir -p $(OBJ)

$(NAME): $(FILES_O) 
	@make -C mylib/libft/
	@gcc ./minilibx_mms/libmlx.dylib $(FLAG_MLX) $(FILES_O) mylib/libft/libft.a -o $(NAME)
	@echo "Ready"

$(OBJ)/%.o : $(SOURCES)/%.c
	@mkdir -p $(OBJ)
	@gcc $(FLAG_GCC) -o $@ -c $^
	@echo "$@ ready"

run: all
	./cub3d ./maps/map.cub

save: all
	./cub3d ./maps/map.cub --save

norma:
	norminette ./srcs/ ./mylib/libft/*.c ./mylib/libft/*.h ./mylib/gnl/ ./includes/

clean: 
	@rm -f $(FILES_O)
	@rm -f $(GNL)/$(FILES_O)
	@rm -rf $(OBJ)
	@make clean -C ./mylib/libft
	@echo "O-files deleted"

fclean: clean
	@rm -f $(NAME)
	@rm -rf screenshot.bmp
	@make fclean -C ./mylib/libft/
	@echo "All files delete"
	
re: fclean all

.PHONY: clean fclean all re
