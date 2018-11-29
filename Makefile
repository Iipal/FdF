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
# macOS:
MLXFLAGS = -L /usr/local/lib -lmlx -framework OpenGL -framework AppKit
# linux:
# MLXFLAGS = -L /usr/local/lib -I /usr/local/lib -lmlx -lXext -lX11

SRC = srcs/main.c srcs/pj/pj_readnsave.c srcs/pj/pj_mlx.c srcs/pj/pj_free.c \
srcs/pj/pj_drawing_raw.c

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
	@$(CC) $(OBJ) $(MLXFLAGS) $(LIBFT) -o $(NAME)
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
