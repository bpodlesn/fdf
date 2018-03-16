# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bpodlesn <bpodlesn@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/02/19 13:23:34 by bpodlesn          #+#    #+#              #
#    Updated: 2018/03/16 14:10:31 by bpodlesn         ###   ########.fr        #
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

OBJ =	$(SRCS:.c=.o)

MLX = -lmlx -framework OpenGL -framework AppKit

FLAGS = -c -Wall -Werror -Wextra

HEADER = fdf.h

all: lib $(NAME)

$(NAME): $(OBJ) $(HEADER) libft/libft.a
		gcc $(FLAGS) $(SRCS)
		gcc -g -o $(NAME) $(OBJ) libft/libft.a $(MLX)

libft/libft.a: lib

lib:
	make -C libft

$(OBJ): %.o : %.c $(HEADER)
	gcc $(FLAGS) $< -o $@

clean:
		@ /bin/rm -f $(OBJ) ./fdf.h.gch
		@ make -C libft/ clean

fclean: clean
		@ /bin/rm -f $(NAME)
		@ make -C libft/ fclean

re: fclean all
