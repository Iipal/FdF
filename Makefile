# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/13 13:30:08 by tmaluh            #+#    #+#              #
#    Updated: 2018/11/13 13:30:10 by tmaluh           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

CC = gcc -march=native
CFLAGS = -g -Wall -Wextra -Werror
MLXFLAGS = -L /usr/local/lib -lmlx -framework OpenGL -framework AppKit
INCLUDE = -I ./includes/

SRC = srcs/main.c srcs/pj_readnsave.c srcs/pj_mlx.c srcs/pj_free.c

OBJ = $(SRC:.c=.o)

LIBFT = libft/libft.a
LMAKE = make -C libft

WHITE=\033[0m
GREEN=\033[32m
RED=\033[31m

DEL = rm -rf

all: $(NAME)

$(OBJ): %.o: %.c
	@echo -n '+'
	@$(CC) -c $(CFLAGS) $< -o $@

$(LIBFT):
	@$(LMAKE)

$(NAME): $(LIBFT) $(OBJ)
	@$(CC) $(INCLUDE) $(MLXFLAGS) $(OBJ) $(LIBFT) -o $(NAME)
	@echo "> $(GREEN)FdF$(WHITE)"

clean:
	@$(DEL) $(OBJ)
	@$(LMAKE) clean

fclean: clean
	@$(LMAKE) fclean
	@$(DEL) $(NAME)
	@echo "$(RED)deleted$(WHITE): ./fdf"

re: fclean all

.PHONY: all fclean clean re
