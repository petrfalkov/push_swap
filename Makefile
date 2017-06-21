# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ichubare <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/02/25 14:43:13 by ichubare          #+#    #+#              #
#    Updated: 2017/03/25 13:48:23 by ichubare         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAMEP = push_swap
NAMEC = checker

SRCP = push_swap_src/check_dup.c \
	   push_swap_src/chose_sort.c \
	   push_swap_src/clean_list.c \
	   push_swap_src/clear_list.c \
	   push_swap_src/find_mid_qs.c \
	   push_swap_src/find_rules.c \
	   push_swap_src/find_rules_rev.c \
	   push_swap_src/func_a.c \
	   push_swap_src/func_b.c \
	   push_swap_src/func_both.c \
	   push_swap_src/len_stack.c \
	   push_swap_src/less_pivos.c \
	   push_swap_src/order_ch.c \
	   push_swap_src/p_s_check.c \
	   push_swap_src/push_swap.c \
	   push_swap_src/rules_act.c \
	   push_swap_src/sort_a.c \
	   push_swap_src/sort_b.c \
	   push_swap_src/stack_act.c \

SRCC = checker_src/acts.c \
	   checker_src/biger_then_int.c \
	   checker_src/check_act.c \
	   checker_src/check_dup.c \
	   checker_src/checker_check.c \
	   checker_src/checker.c \
	   checker_src/error_check.c \
	   checker_src/func_a.c \
	   checker_src/func_b.c \
	   checker_src/func_both.c \
	   checker_src/show_act.c \
	   checker_src/stack_act.c \

OBJP = $(SRCP:.c=.o)

OBJC = $(SRCC:.c=.o)

HEADERP = push_swap.h

HEADERC = checker.h

LIB = -L ./ft_printf/ -lftprintf

FLAGS = -Wall -Wextra -Werror -c

all: $(NAMEP) $(NAMEC)
	
$(NAMEP): $(OBJP)
		make -C ./ft_printf/
		gcc $(FLAGS) $(SRCP)
		gcc -o $(NAMEP) $(LIB) $(OBJP)

$(NAMEC): $(OBJC)
		gcc $(FLAGS) $(SRCC)
		gcc -o $(NAMEC) $(LIB) $(OBJC)

$(RECPR):
	make -C ft_printf

clean:
	rm -f $(OBJC)
	rm -f $(OBJP)
	rm -f check_dup.o \
		chose_sort.o \
		clean_list.o \
		clear_list.o \
		find_mid_qs.o \
		find_rules.o \
		find_rules_rev.o \
		func_a.o \
		func_b.o \
		func_both.o \
		len_stack.o \
		less_pivos.o \
		order_ch.o \
		p_s_check.o \
		push_swap.o \
		rules_act.o \
		sort_a.o \
		sort_b.o \
		stack_act.o \
		check_act.o \
		acts.o \
		checker.o \
		error_check.o \
		show_act.o \
		biger_then_int.o \
		checker_check.o
	make clean -C ft_printf

fclean: clean 
	make fclean -C ft_printf
	rm -f $(NAMEP)
	rm -f $(NAMEC)

re:	fclean all
	make re -C ft_printf
