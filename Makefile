#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: msarapii <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/05/12 13:43:53 by msarapii          #+#    #+#              #
#    Updated: 2018/05/12 13:43:54 by msarapii         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = "ft_ls"

FLAFS = "-Wall -Wexta -Werror"

FT_PRINTF = libft/libftprintf.a

SRC =  ./SRC/main.c ./SRC/valid_flags.c ./SRC/help_func.c ./SRC/print_func.c \
		./SRC/out_dirs.c ./SRC/recur_pr.c ./SRC/sort.c ./SRC/sort2.c \
		./SRC/print_l.c ./SRC/print_func_help.c ./SRC/help.c ./SRC/print1.c

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(OBJ) : %.o: %.c
		@gcc $(FLAGS) -I ./SRC/ -I ./libft/ -o $@ -c $<

$(NAME): $(OBJ)
		@make -C libft/
		@gcc -o $(NAME) $(OBJ) $(FT_PRINTF)

#%.o: %.c
#	@gcc $(FLAGS) -o $@ -c $<

clean:
		@/bin/rm -f $(OBJ)
		@make -C libft/ clean

fclean: clean
		@/bin/rm -f $(NAME)
		@make -C libft/ fclean

re: fclean all

