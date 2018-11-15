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
MLXFLAGS = -L /usr/locale/lib -lmlx -framework OpenGL -framework AppKit

SRC = srcs/main.c srcs/readnvalid.c srcs/init_mlx.c srcs/dllist.c

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
	@echo "$LFDF:$(GREEN)\tCompiling file:$(YELLOW)" $< "$(WHITE)to$(PURPLE)" $@ "$(WHITE)"
	@$(CC) -c $(CFLAGS) $< -o $@

$(LIBFT):
	@echo "\t\t$LFDF$(WHITE)"
	@$(LMAKE)

$(NAME): $(LIBFT) $(OBJ)
	@echo "$LFDF:$(GREEN)\tCompiling FDF executable...$(WHITE)"
	@$(CC) $(MLXFLAGS) $(OBJ) $(LIBFT) -o $(NAME)
	@echo "$LFDF:$(LGREEN)\tCompiled & fdf ready for use.$(WHITE)"

clean:
	@$(DEL) $(OBJ)
	@echo "$LFDF:$(ORANGE)\tRemoved: *.o files...$(WHITE)"
	@$(LMAKE) clean

fclean: clean
	@$(DEL) $(NAME)
	@echo "$LFDF:$(RED)\tRemoved: fdf...$(WHITE)"
	@$(LMAKE) fclean

re: fclean all

.PHONY: all fclean clean re