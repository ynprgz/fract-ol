# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yaperalt <yaperalt@student.42malaga.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/15 13:12:26 by yaperalt          #+#    #+#              #
#    Updated: 2025/02/15 13:13:33 by yaperalt         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fract-ol
CC = cc
RM = rm -rf
CFLAGS = -Wall -Wextra -Werror
MLXFLAGS = -lX11 -lXext -lXrandr -lXrender -lXfixes -lXcursor -lXinerama -lm


all:

$(NAME):

clean:

fclean: clean

re: fclean all

.phony: re clean fclean all
