# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lelderbe <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/03/08 12:49:23 by lelderbe          #+#    #+#              #
#    Updated: 2021/03/08 13:05:08 by lelderbe         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS		= 

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
TEST_NAME	= test
TEST_BNAME	= bonus_test

CC			= gcc

ASMCC		= nasm

AR			= ar rc

RM			= rm -f

CFLAGS		= -Wall -Wextra -Werror

ASMFLAGS	= -f macho64

%.o:		%.s ${HEADERS}
			${CC} ${CFLAGS} -c $< -o ${<:.s=.o}

${NAME}:	${OBJS}
			${AR} ${NAME} ${OBJS}

all:		${NAME}

bonus:		
			@$(MAKE) BONUS=1 ${NAME}

clean:
			${RM} ${OBJS}
			${RM} ${B_OBJS}

fclean:		clean
			${RM} ${NAME}

re:			fclean all

test:		all
			${CC} ${CFLAGS} -c test.c -o test.o
			${CC} ${CFLAGS} -L. -lasm test.o -o ${TEST_NAME}

bonus_test:	bonus
			${CC} ${CFLAGS} -c bonus_test.c -o bonus_test.o
			${CC} ${CFLAGS} -L. -lasm bonus_test.o -o ${TEST_BNAME}

.PHONY:		all clean fclean re
