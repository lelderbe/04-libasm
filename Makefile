# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lelderbe <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/03/08 12:49:23 by lelderbe          #+#    #+#              #
#    Updated: 2021/03/15 21:05:58 by lelderbe         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS		= ft_strlen.s ft_strcpy.s ft_strcmp.s ft_write.s ft_read.s ft_strdup.s

B_SRCS		= ft_list_size.s ft_list_push_front.s

HEADERS		= libasm.h libasm_bonus.h

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
TEST_TEXT	= test.txt

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
			${RM} ${TEST_TEXT}

re:			fclean all

test:		all
			${CC} ${CFLAGS} -c test.c -o test.o
			${CC} ${CFLAGS} test.o -L. -lasm -o ${TEST_NAME}
			echo "ABCDEF1234567890\c" > ${TEST_TEXT}

bonus_test:	bonus
			${CC} ${CFLAGS} -c bonus_test.c -o bonus_test.o
			${CC} ${CFLAGS} bonus_test.o -L. -lasm -o ${TEST_BNAME}
			echo "ABCDEF1234567890\c" > ${TEST_TEXT}

.PHONY:		all clean fclean re
