#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: msarapii <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/10/31 12:37:49 by msarapii          #+#    #+#              #
#    Updated: 2017/11/21 18:51:50 by msarapii         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

CC = gcc

FLAGS = -Wall -Wextra -Werror

NAME = libftprintf.a

SRC = ft_printf.c prep_command_line.c flags.c specificator.c width.c size.c \
ft_bzero.c ft_strncpy.c ft_isdigit.c precision.c form_print.c add_null.c \
ft_atoi.c ft_is_it_space.c add_esp.c search_err.c print_d.c ft_itoa.c \
ft_strcpy.c ft_strdel.c ft_strjoin.c ft_strlen.c ft_strnew.c ft_memalloc.c \
ft_memdel.c ft_strcat.c print_du.c ft_itoa_u.c print_s.c print_s2.c \
add_null2.c add_esp2.c convert_str.c add_null3.c print_p.c \
print_c.c print_x.c add_hesh.c print_u.c ft_strdup.c ft_memset.c \
ft_itoa_base_s.c help.c

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
			ar rc $(NAME) $(OBJ)
			ranlib $(NAME)
%.o: %.c
	gcc $(FLAGS) -c -o $@ $<

clean:
	rm -rf $(OBJ)

fclean: 
	rm -rf $(NAME) $(OBJ)

re: fclean all

mainflag: 
	@gcc $(FLAGS) test_main.c libftprintf.a
	@./a.out

main:
	@cc test_main.c libftprintf.a
	@./a.out