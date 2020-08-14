# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: qsymond <qsymond@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/08/09 23:20:21 by qsymond           #+#    #+#              #
#    Updated: 2020/08/10 20:56:15 by qsymond          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= libasm.a

SRCS	= ft_strlen.s \
		  ft_strcpy.s \
		  ft_strcmp.s \
		  ft_strdup.s \
		  ft_write.s \
		  ft_read.s \

OBJS	= $(SRCS:.s=.o)

TEST	= test

TXT		= example.txt

%.o		: %.s
	nasm -f macho64 $<

all		: $(NAME)

$(NAME)	: $(OBJS)
	ar rcs $(NAME) $(OBJS)

clean	: 
	rm -rf $(OBJS)

fclean	: clean
	rm -rf $(NAME) $(TEST) $(TXT) $(NAME)

re		: fclean all

test	: re
	gcc main.c -o test -L. -lasm