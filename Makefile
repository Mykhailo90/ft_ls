#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: msarapii <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/04/14 12:23:15 by msarapii          #+#    #+#              #
#    Updated: 2018/04/14 12:23:16 by msarapii         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = ft_ls

FLAGS = -c -Wall -Wextra -Werror

FT_PRINTF = libft/libftprintf.a

SRC =  ./SRC/main.c ./SRC/valid_flags.c ./SRC/help_func.c ./SRC/print_func.c

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
		@make -C libft/
		@gcc -o $(NAME) $(OBJ) $(FT_PRINTF)

%.o: %.c
	@gcc $(FLAGS) -o  $@ $<

clean:
		@/bin/rm -f $(OBJ)
		@make -C libft/ clean

fclean: clean
		@/bin/rm -f $(NAME)
		@make -C libft/ fclean

re: fclean all
