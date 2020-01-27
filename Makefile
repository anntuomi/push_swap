# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: atuomine <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/15 13:38:08 by atuomine          #+#    #+#              #
#    Updated: 2020/01/24 11:57:56 by atuomine         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = checker
NAME2 = push_swap
INC = ../libft/includes
SRC = src_checker/checker.c \
	  src_checker/checker_exec_p.c \
	  src_checker/checker_exec_r.c \
	  src_checker/checker_exec_s.c \
	  src_checker/valid_check.c \
	  src_checker/commands.c
OBJECT = checker.o checker_exec_p.o \
		 checker_exec_r.o checker_exec_s.o \
		 valid_check.o commands.o
SRC2 = src_pushswap/adjust_size.c \
	   src_pushswap/algorithm_big.c \
	   src_pushswap/algorithm_small.c \
	   src_pushswap/check_valid.c \
	   src_pushswap/median.c \
	   src_pushswap/push_swap.c \
	   src_pushswap/pushback.c \
	   src_pushswap/assign_order.c \
	   src_pushswap/exec_p.c \
	   src_pushswap/exec_r.c \
	   src_pushswap/exec_s.c \
	   src_pushswap/divide_stack.c
OBJECT2 = adjust_size.o algorithm_big.o algorithm_small.o \
		  median.o push_swap.o \
		  pushback.o check_valid.o assign_order.o exec_p.o \
		  exec_r.o exec_s.o divide_stack.o
LIBRARY = libft.a

all: $(LIBRARY) $(NAME) $(NAME2)

$(LIBRARY):
			make -C libft/
		
$(NAME):
			gcc -Wall -Wextra -Werror -I $(INC) -c $(SRC) 
			gcc -Wall -Wextra -Werror $(OBJECT) libft/libft.a -o $(NAME)

$(NAME2):
			gcc -Wall -Wextra -Werror -I $(INC) -c $(SRC2)
			gcc -Wall -Wextra -Werror $(OBJECT2) libft/libft.a -o $(NAME2)
	
clean:
			/bin/rm -f $(OBJECT) $(OBJECT2)
			make -C libft/ clean

fclean:		clean
			make -C libft/ fclean
			/bin/rm -f $(NAME) $(NAME2)

re:			fclean all
