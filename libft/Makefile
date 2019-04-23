# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: grougeau <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/02/14 13:47:39 by grougeau          #+#    #+#              #
#    Updated: 2019/03/12 14:26:47 by grougeau         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRC = ft_strrchr.c \
	ft_strlcat.c \
	ft_memcpy.c \
	ft_memmove.c \
	ft_strncpy.c \
	ft_strstr.c \
	ft_isdigit.c \
	ft_memccpy.c \
	ft_bzero.c \
	ft_isalnum.c \
	ft_toupper.c \
	ft_strcpy.c \
	ft_isascii.c \
	ft_strlen.c \
	ft_strncat.c \
	ft_memset.c \
	ft_isalpha.c \
	ft_strcat.c \
	ft_tolower.c \
	ft_isprint.c \
	ft_strchr.c \
	ft_atoi.c \
	ft_strcmp.c \
	ft_strncmp.c \
	ft_memcmp.c \
	ft_memchr.c \
	ft_strdup.c \
	ft_putstr.c \
	ft_putstr_fd.c \
	ft_putnbr.c \
	ft_putnbr_fd.c \
	ft_putchar.c \
	ft_putchar_fd.c \
	ft_putendl.c \
	ft_putendl_fd.c \
	ft_memalloc.c \
	ft_memdel.c \
	ft_strdel.c \
	ft_strnew.c \
	ft_strclr.c \
	ft_striter.c \
	ft_striteri.c \
	ft_strmap.c \
	ft_strmapi.c \
	ft_strequ.c \
	ft_strnequ.c \
	ft_strsub.c \
	ft_strjoin.c \
	ft_strtrim.c \
	ft_strnstr.c \
	ft_itoa.c \
	ft_strsplit.c \
	ft_wdcount.c \
	ft_wdlen.c	\
	ft_lstiter.c \
	ft_lstadd.c \
	ft_lstdel.c \
	ft_lstdelone.c \
	ft_lstnew.c \
	ft_lstmap.c

BINARY =  $(SRC:.c=.o)

FLAG = -c -Wall -Wextra -Werror -Iincludes.

all: $(NAME)

$(NAME):
	gcc $(FLAG) $(SRC)
	ar -rc $(NAME) $(BINARY)
	
clean:
	/bin/rm -f $(BINARY)

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all

.PHONY: clean fclean re


