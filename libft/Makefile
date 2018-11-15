# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/10/25 11:27:37 by tmaluh            #+#    #+#              #
#    Updated: 2018/10/30 17:22:11 by tmaluh           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

CC = gcc -march=native
LC = ar rc

CFLAGS = -Wall -Wextra -Werror -Ofast

WHITE=\033[0m
GREEN=\033[32m
LGREEN=\033[92m
RED=\033[31m
ORANGE=\033[33m
YELLOW=\033[93m
PURPLE=\033[34m
L=\033[36m

DEL = rm -rf

LIBSRC = srcs/mem/ft_bzero.c srcs/mem/ft_memset.c srcs/mem/ft_memalloc.c \
		srcs/mem/ft_memcpy.c srcs/mem/ft_memccpy.c srcs/mem/ft_memmove.c \
		srcs/mem/ft_memchr.c srcs/mem/ft_memcmp.c srcs/mem/ft_memdel.c \
		srcs/math/ft_pow.c srcs/math/ft_sqrt.c \
		srcs/put/ft_putchar.c srcs/put/ft_putchar_fd.c srcs/put/ft_putendl.c \
		srcs/put/ft_putendl_fd.c srcs/put/ft_putnbr.c srcs/put/ft_putnbr_fd.c \
		srcs/put/ft_putstr.c srcs/put/ft_putstr_fd.c \
		srcs/lst/ft_lstadd.c srcs/lst/ft_lstdel.c srcs/lst/ft_lstdelone.c \
		srcs/lst/ft_lstiter.c srcs/lst/ft_lstmap.c srcs/lst/ft_lstnew.c \
		srcs/ctype/ft_isalnum.c srcs/ctype/ft_isalpha.c srcs/ctype/ft_isascii.c \
		srcs/ctype/ft_isblank.c srcs/ctype/ft_isdigit.c srcs/ctype/ft_islower.c \
		srcs/ctype/ft_isprint.c srcs/ctype/ft_isupper.c srcs/ctype/ft_toupper.c \
		srcs/ctype/ft_tolower.c \
		srcs/str/ft_atoi.c srcs/str/ft_count_if.c srcs/str/ft_itoa.c srcs/str/ft_strcat.c \
		srcs/str/ft_strchr.c srcs/str/ft_strclr.c srcs/str/ft_strcmp.c srcs/str/ft_strcpy.c \
		srcs/str/ft_strdel.c srcs/str/ft_strdup.c srcs/str/ft_strequ.c srcs/str/ft_striter.c \
		srcs/str/ft_striteri.c srcs/str/ft_strjoin.c srcs/str/ft_strlcat.c srcs/str/ft_strlcpy.c \
		srcs/str/ft_strlen.c srcs/str/ft_strmap.c srcs/str/ft_strmapi.c srcs/str/ft_strncat.c \
		srcs/str/ft_strncmp.c srcs/str/ft_strncpy.c srcs/str/ft_strndup.c srcs/str/ft_strnequ.c \
		srcs/str/ft_strnew.c srcs/str/ft_strnstr.c srcs/str/ft_strrchr.c srcs/str/ft_strsplit.c \
		srcs/str/ft_strstr.c srcs/str/ft_strsub.c srcs/str/ft_strtrim.c \
		srcs/lft/ft_gnl.c

LIBOBJ = $(LIBSRC:%.c=%.o)

all: $(NAME)

$(NAME): $(LIBOBJ)
	@echo "$LFDF:$(GREEN)\tCompiling LIBFT...$(WHITE)"
	@$(LC) $(NAME) $(LIBOBJ)
	@echo "$LLIBFT:$(LGREEN)\tCompiled & libft.a ready for use.$(WHITE)"

$(LIBOBJ): %.o: %.c
	@echo "$LLIBFT:$(GREEN)\tCompiling file:$(YELLOW)" $< "$(WHITE)to$(PURPLE)" $@ "$(WHITE)"
	@$(CC) -c $(CFLAGS) $< -o $@

clean:
	@$(DEL) $(LIBOBJ)
	@echo "$LLIBFT:$(ORANGE)\tRemoved: *.o files.$(WHITE)"

fclean: clean
	@$(DEL) $(NAME)
	@echo "$LLIBFT:$(RED)\tRemoved: libft.a.$(WHITE)"

re: fclean all

.PHONY: re fclean clean all
