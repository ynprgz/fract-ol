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
