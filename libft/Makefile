# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bpodlesn <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/10/26 13:24:52 by bpodlesn          #+#    #+#              #
#    Updated: 2018/02/02 16:40:00 by bpodlesn         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=libft.a

SRCS = ft_putchar.c \
	   ft_putstr.c \
	   ft_strcmp.c \
	   ft_strncmp.c \
	   ft_strcpy.c \
	   ft_strncpy.c \
	   ft_strlen.c \
	   ft_strstr.c \
	   ft_strnstr.c \
	   ft_memcmp.c \
	   ft_memset.c \
	   ft_memcpy.c \
	   ft_memcpy2.c \
	   ft_memmove.c \
	   ft_memccpy.c \
	   ft_memchr.c \
	   ft_bzero.c \
	   ft_strchr.c \
	   ft_strrchr.c \
	   ft_strcat.c \
	   ft_strncat.c \
	   ft_strlcat.c \
	   ft_strdup.c \
	   ft_isalpha.c \
	   ft_isdigit.c \
	   ft_isalnum.c \
	   ft_isascii.c \
	   ft_isprint.c \
	   ft_toupper.c \
	   ft_tolower.c \
	   ft_atoi.c \
	   ft_atoi1.c \
	   ft_memalloc.c \
	   ft_memdel.c \
	   ft_strnew.c \
	   ft_strdel.c \
	   ft_strclr.c \
	   ft_striter.c \
	   ft_striteri.c \
	   ft_putchar_fd.c \
	   ft_strmap.c \
	   ft_strmapi.c \
	   ft_strnequ.c \
	   ft_strequ.c \
	   ft_strsub.c \
	   ft_strjoin.c \
	   ft_strtrim.c \
	   ft_strsplit.c \
	   ft_putstr_fd.c \
	   ft_putendl_fd.c \
	   ft_itoa.c \
	   ft_putendl.c \
	   ft_putnbr.c \
	   ft_putnbr_fd.c \
	   ft_lstnew.c \
	   ft_lstdelone.c \
	   ft_lstdel.c \
	   ft_lstadd.c \
	   ft_lstiter.c \
	   ft_lstmap.c \
	   get_next_line.c \

OFILES = ft_putchar.o \
		 ft_putstr.o \
		 ft_strcmp.o \
		 ft_strncmp.o \
		 ft_strcpy.o \
		 ft_strncpy.o \
		 ft_strlen.o \
		 ft_strstr.o \
		 ft_strnstr.o \
		 ft_memcmp.o \
		 ft_memset.o \
		 ft_memcpy.o \
		 ft_memcpy2.o \
		 ft_memmove.o \
		 ft_memccpy.o \
		 ft_memchr.o \
		 ft_bzero.o \
		 ft_strchr.o \
		 ft_strrchr.o \
		 ft_strcat.o \
		 ft_strncat.o \
		 ft_strlcat.o \
		 ft_strdup.o \
		 ft_isalpha.o \
		 ft_isdigit.o \
		 ft_isalnum.o \
		 ft_isascii.o \
		 ft_isprint.o \
		 ft_toupper.o \
		 ft_tolower.o \
		 ft_atoi.o \
		 ft_atoi1.o \
		 ft_memalloc.o \
		 ft_memdel.o \
		 ft_strnew.o \
		 ft_strdel.o \
		 ft_strclr.o \
		 ft_striter.o \
		 ft_striteri.o \
		 ft_putchar_fd.o \
		 ft_strmap.o \
		 ft_strmapi.o \
		 ft_strequ.o \
		 ft_strnequ.o \
		 ft_strsub.o \
		 ft_strjoin.o \
		 ft_strtrim.o \
		 ft_strsplit.o \
		 ft_putstr_fd.o \
		 ft_putendl_fd.o \
		 ft_itoa.o \
		 ft_putendl.o \
		 ft_putnbr.o \
		 ft_putnbr_fd.o \
		 ft_lstnew.o \
		 ft_lstdelone.o \
		 ft_lstdel.o \
		 ft_lstadd.o \
		 ft_lstiter.o \
		 ft_lstmap.o \
		 get_next_line.o \

HEADERS = -I libft.h

FLAGS = -Wall -Werror -Wextra

all: $(NAME)

$(NAME):
	@gcc $(FLAGS) -c $(SRCS) $(HEADERS)
	@ar rc $(NAME) $(OFILES)

clean:
	@rm -f $(OFILES)

fclean: clean
	@rm -f $(NAME)

re: fclean all
