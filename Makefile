# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lelderbe <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/03/08 12:49:23 by lelderbe          #+#    #+#              #
#    Updated: 2021/03/14 18:03:44 by lelderbe         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS		= ft_strlen.s ft_strcpy.s ft_strcmp.s

B_SRCS		= 

HEADERS		= libasm.h

ifdef BONUS
	OBJS = ${C_OBJS} ${B_OBJS}
else
	OBJS = ${C_OBJS}
endif

C_OBJS		= ${SRCS:.s=.o}

B_OBJS		= ${B_SRCS:.s=.o}

NAME		= libasm.a
TEST_NAME	= test.out
TEST_BNAME	= bonus_test.out

CC			= gcc

ASMCC		= nasm

AR			= ar rc

RM			= rm -f

CFLAGS		= -Wall -Wextra -Werror -g

ASMFLAGS	= -f macho64 -g

ifeq ($(shell uname -s), Linux)
ASMFLAGS	= -f elf64 -g
endif

%.o:		%.s ${HEADERS}
			${ASMCC} ${ASMFLAGS} $< -o ${<:.s=.o}

${NAME}:	${OBJS}
			${AR} ${NAME} ${OBJS}
			ranlib ${NAME}

all:		${NAME}

bonus:		
			@$(MAKE) BONUS=1 ${NAME}

clean:
			${RM} ${OBJS}
			${RM} ${B_OBJS}
			${RM} test.o
			${RM} bonus_test.o

fclean:		clean
			${RM} ${NAME}
			${RM} ${TEST_NAME}
			${RM} ${TEST_BNAME}

re:			fclean all

test:		all
			${CC} ${CFLAGS} -c test.c -o test.o
			${CC} ${CFLAGS} test.o -L. -lasm -o ${TEST_NAME}

bonus_test:	bonus
			${CC} ${CFLAGS} -c bonus_test.c -o bonus_test.o
			${CC} ${CFLAGS} bonus_test.o -L. -lasm -o ${TEST_BNAME}

.PHONY:		all clean fclean re
