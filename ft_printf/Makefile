# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: axburin- <axburin-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/17 14:52:14 by axburin-          #+#    #+#              #
#    Updated: 2025/01/12 14:56:35 by axburin-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_printf.a

CC = cc
CFLAGS = -Wall -Wextra -Werror

LIBC = fonction_utils ft_printf ft_putnbr ftc_hex

SRCS = $(addsuffix .c, ${LIBC})
OBJS = $(addsuffix .o, ${LIBC})

all: ${NAME}

${NAME}: ${OBJS}
	@echo "✅ Compilation des fichiers sources"
	@ar -rcs ${NAME} ${OBJS}
	@echo "✅ Bibliothèque créée"

.c.o:
	@${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

clean:
	@rm -rf ${OBJS}
	@echo "✅ Suppression des fichiers objets"

fclean: clean
	@rm -rf ${NAME}
	@echo "✅ Suppression de la bibliothèque"

re: fclean all

.PHONY = all clean fclean re