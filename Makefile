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

CC = gcc
CFLAGS = -Wall -Wextra -Werror
MLXFLAGS = -L /usr/local/lib -lmlx -framework OpenGL -framework AppKit

SRC = srcs/main.c srcs/readnvalid.c 

OBJ = $(SRC:.c=.o)

LIBFT = libft/libft.a
LMAKE = make -C libft

WHITE=\033[0m
GREEN=\033[32m
LGREEN=\033[92m
RED=\033[31m
ORANGE=\033[33m
YELLOW=\033[93m
PURPLE=\033[34m
L=\033[36m

DEL = rm -rf

all: $(NAME)

$(OBJ): %.o: %.c
	@echo -n '+'
	@$(CC) -c $(CFLAGS) $< -o $@

$(LIBFT):
	@$(LMAKE)

$(NAME): $(LIBFT) $(OBJ)
	@$(CC) $(MLXFLAGS) $(OBJ) $(LIBFT) -o $(NAME)
	@echo "> $(GREEN)FdF$(WHITE)"

clean:
	@$(DEL) $(OBJ)
	@$(LMAKE) clean

fclean: clean
	@$(DEL) $(NAME)
	@echo "./fdf $(RED)deleted.$(WHITE)"
	@$(LMAKE) fclean

re: fclean all

.PHONY: all fclean clean re