# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yaperalt <yaperalt@student.42malaga.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/15 13:12:26 by yaperalt          #+#    #+#              #
#    Updated: 2025/02/25 14:46:49 by yaperalt         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fract-ol
CC = cc
RM = rm -rf
CFLAGS = -Wall -Wextra -Werror

SRCS = $(wildcard src/*.c)
OBJS = $(SRCS:src/%.c=obj/%.o)

MLXPATH = minilibx-linux/
MLXLIB = $(MLXPATH)libmlx_Linux.a
MLXFLAGS = -lX11 -lXext -lXrandr -lXrender -lXfixes -lXcursor

all: $(NAME)

obj:
	@mkdir -p obj

obj/%.o: src/%.c | obj
	@$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJS)
	@$(CC) $(OBJS) $(MLXLIB) $(CFLAGS) $(MLXFLAGS) -o $(NAME)
	@echo "\n\nfract-ol executable created\n\n"

clean:
	@$(RM) obj

fclean: clean
	@$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
