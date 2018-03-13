# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bpodlesn <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/02/19 13:23:34 by bpodlesn          #+#    #+#              #
#    Updated: 2018/03/13 14:56:20 by bpodlesn         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

SRCS = main.c \
	   turn_rev.c \
	   hex.c \
	   keys.c \
	   liner.c \
	   reader.c \
	   draw.c \
	   moves.c \

OBJ =	main.o \
	   turn_rev.o \
	   hex.o \
	   keys.o \
	   liner.o \
	   reader.o \
	   draw.o \
	   moves.o \

MLX = -lmlx -framework OpenGL -framework AppKit

FLAGS = -c -Wall -Werror -Wextra

HEADER = fdf.h

all: $(NAME)

$(NAME):
		@ make -C libft/
		@ gcc $(FLAGS) $(HEADER) $(SRCS)
		@ gcc -g -o $(NAME) $(OBJ) libft/libft.a $(MLX)

clean:
		@ /bin/rm -f $(OBJ) ./fdf.h.gch
		@ make -C libft/ clean

fclean: clean
		@ /bin/rm -f $(NAME)
		@ make -C libft/ fclean

re: fclean all
