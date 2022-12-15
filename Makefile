# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ylabbe <ylabbe@student.42quebec.c>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/25 14:34:58 by ylabbe            #+#    #+#              #
#    Updated: 2022/10/05 16:59:01 by ylabbe           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	push_swap
GCC		=	@gcc
CFLAGS	=	-Wall -Wextra -Werror
RM		=	@rm -rfd

SRCS	=	main.c \
			ft_reverse_rotate_stack.c \
			ft_sort_big.c \
			ft_sort_small.c \
			ft_rotate_stack.c \
			ft_respect_the_subject.c \
			ft_swap_stack.c \
			ft_push_stack.c \
			ft_sort_quick.c

OBJS	=	${SRCS:.c=.o}

.c.o:	=
			${GCC} ${CFLAGS} -c $< -o $@

${NAME}:	Makefile push_swap.h ${OBJS}
			${GCC} ${CFLAGS} ${OBJS} -o ${NAME}
			@echo "\033[01;32mCompiling the program push_swap."

all:		${NAME}

clean:
			${RM} ${OBJS}
			@echo "\033[01;35mDelete all object files."

fclean:		clean
			${RM} ${NAME}
			@echo "\033[01;34mDeleting the executable file."

re:			fclean all

.PHONY:		all clean fclean re
