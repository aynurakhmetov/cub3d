# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gmarva <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/07/15 16:26:01 by gmarva            #+#    #+#              #
#    Updated: 2020/08/13 22:07:23 by gmarva           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
FUNCS = ft_printf.c ft_flags.c ft_length.c ft_parser.c \
		ft_precision.c ft_type.c ft_width.c \
		ft_process.c ft_typeprint.c null_print.c \
		wp_print.c ft_di_print.c ft_c_print.c ft_s_print.c \
		ft_u_print.c ft_x_print.c ft_p_print.c ft_di_print_three.c \
		ft_di_print_two.c ft_percent_print.c ft_p_print_two.c

FLAG_GCC = -Wall -Wextra -Werror
HEADER = includes
SOURCES = libftprintf
OBJ = objects

FILES_C = $(addprefix $(SOURCES)/,$(FUNCS))

FILES_O = $(addprefix $(OBJ)/,$(FUNCS:.c=.o))

all: $(NAME)
	@mkdir -p $(OBJ)

$(NAME): $(FILES_O) 
	@make -C ../libft/
	@cp ../libft/libft.a ./$(NAME)
	@ar rc $(NAME) $(FILES_O)
	@ranlib $(NAME)
	@echo "Ready"

$(OBJ)/%.o : $(SOURCES)/%.c $(HEADER)/printf.h
	@mkdir -p $(OBJ)
	@gcc $(FLAG_GCC) -I $(HEADER) -o $@ -c $<
	@echo "$@ ready"

clean: 
	@rm -f $(FILES_O)
	@rm -rf $(OBJ)
	@echo "O-files deleted"

fclean: clean
	@rm -f $(NAME)
	@make fclean -C ../libft/
	@echo "All files delete"

re: fclean all

.PHONY: clean fclean all re
