# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gmarva <gmarva@student.21-school.ru>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/05/06 13:04:33 by gmarva            #+#    #+#              #
#    Updated: 2020/05/26 14:22:19 by gmarva           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
FILES_C = ft_memset.c ft_bzero.c ft_memcpy.c ft_memmove.c ft_memchr.c \
		  ft_memccpy.c ft_memcmp.c ft_strlen.c ft_strlcpy.c ft_strlcat.c\
		  ft_strchr.c ft_strrchr.c ft_strnstr.c ft_strncmp.c ft_atoi.c\
		  ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c\
		  ft_toupper.c ft_tolower.c ft_substr.c ft_strjoin.c ft_strtrim.c\
		  ft_split.c ft_itoa.c ft_strmapi.c ft_calloc.c ft_strdup.c\
		  ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c\
		  ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c ft_lstadd_back.c\
                  ft_lstiter.c ft_lstmap.c ft_lstdelone.c ft_lstclear.c

FILES_O = ft_memset.o ft_bzero.o ft_memcpy.o ft_memmove.o ft_memchr.o \
		  ft_memccpy.o ft_memcmp.o ft_strlen.o ft_strlcpy.o ft_strlcat.o\
		  ft_strchr.o ft_strrchr.o ft_strnstr.o ft_strncmp.o ft_atoi.o\
		  ft_isalpha.o ft_isdigit.o ft_isalnum.o ft_isascii.o ft_isprint.o\
		  ft_toupper.o ft_tolower.o ft_substr.o ft_strjoin.o ft_strtrim.o\
		  ft_split.o ft_itoa.o ft_strmapi.o ft_calloc.o ft_strdup.o\
		  ft_putchar_fd.o ft_putstr_fd.o ft_putendl_fd.o ft_putnbr_fd.o\
		  ft_lstnew.o ft_lstadd_front.o  ft_lstsize.o ft_lstlast.o ft_lstadd_back.o\
                  ft_lstiter.o ft_lstmap.o ft_lstdelone.o ft_lstclear.o

BONUS_C = ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c ft_lstadd_back.c\
                  ft_lstiter.c ft_lstmap.c ft_lstdelone.c ft_lstclear.c

BONUS_O = ft_lstnew.o ft_lstadd_front.o  ft_lstsize.o ft_lstlast.o ft_lstadd_back.o\
                  ft_lstiter.o ft_lstmap.o ft_lstdelone.o ft_lstclear.o

FLAGC_GCC = -Wall -Wextra -Werror
HEADER = libft.h

all:$(NAME)
		
%.o : %.c $(HEADER)
	@gcc -c $(FLAGC_GCC) $< -o $@ 
	@echo "$@ ready"

$(NAME): $(FILES_O)
	@ar rc $(NAME) $?
	@ranlib $(NAME)
	@echo "Part1 & Part2 ready"

bonus: $(BONUS_O)
	@ar rc $(NAME) $?
	@ranlib $(NAME)
	@echo "Bonus part ready"

clean: 
	@rm -f $(FILES_O) $(BONUS_O)
	@echo "O-files deleted"

fclean: clean
	@rm -f $(NAME) libft.so
	@echo "All files deleted"

re: fclean all

so:
	gcc -fPIC -c $(FILES_C) $(BONUS_C)
	gcc -shared -o libft.so *.o

.PHONY: clean fclean all re
