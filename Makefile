# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/13 13:30:08 by tmaluh            #+#    #+#              #
#    Updated: 2019/02/08 18:41:26 by tmaluh           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

UNAME_S := $(shell uname -s)
ifeq ($(UNAME_S),Linux)
	MLXFLAGS := -L /usr/local/lib -I /usr/local/lib -lmlx -lXext -lX11 -lm
endif
ifeq ($(UNAME_S),Darwin)
	MLXFLAGS := -L /usr/local/lib -lmlx -lm -framework OpenGL -framework AppKit
endif

CC = gcc -march=native
CFLAGS = -Wall -Wextra -Werror -Ofast

SRC = srcs/main.c srcs/fdf_readnsave.c srcs/fdf_free.c srcs/fdf_rendering.c \
srcs/fdf_brasenham_drawing.c srcs/fdf_key_hooks.c srcs/fdf_movenrot.c \
srcs/fdf_frog.c srcs/fdf_projections.c srcs/fdf_rendering_buff.c \
srcs/fdf_additional.c srcs/fdf_bdrawing_gradient.c srcs/fdf_image.c \
srcs/fdf_mouse_hooks.c

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

del:
	@$(DEL) $(OBJ)

clean:
	@$(DEL) $(OBJ)
	@$(LMAKE) clean

fclean: clean
	@$(LMAKE) fclean
	@$(DEL) $(NAME)
	@echo "$(RED)deleted$(WHITE): ./fdf"

re: fclean all

.PHONY: all fclean clean re
