/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichubare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/16 13:10:36 by ichubare          #+#    #+#             */
/*   Updated: 2017/03/23 14:27:40 by ichubare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H
# define RED "\033[1;31m"
# define YELLOW "\033[1;33m"
# define GREEN "\033[1;32m"
# define RESET "\033[0m"

# include "../ft_printf/ft_printf.h"

typedef struct			s_stack
{
	int					data;
	struct s_stack		*next;
}						t_stack;

typedef struct			s_check
{
	t_stack				*stack_a;
	t_stack				*stack_b;
	int					v_flag;
	int					c_flag;
	struct s_check		*next;
}						t_check;

void					add_new_elem(t_stack **stack, int data);
void					len_stack(t_stack *stack, size_t *len);
void					ft_sa(t_stack **stack_a, size_t len);
void					del_elem(t_stack **stack);
void					ft_pa(t_stack **stack_a,
						t_stack **stack_b, size_t len_b);
void					ft_ra(t_stack **stack_a, size_t len);
void					ft_rra(t_stack **stack_a, size_t len);
void					ft_sb(t_stack **stack_b, size_t len);
void					ft_pb(t_stack **stack_b,
						t_stack **stack_a, size_t len_a);
void					ft_rb(t_stack **stack_b, size_t len);
void					ft_rrb(t_stack **stack_b, size_t len);
void					ft_rrr(t_stack **stack_a, t_stack **stack_b);
void					ft_rr(t_stack **stack_a, t_stack **stack_b);
void					ft_ss(t_stack **stack_a, t_stack **stack_b);
int						read_acts(t_check *check);
int						is_instruction(char *act);
int						check_args(int argc, char **argv,
						t_stack **stack_a, t_check *check);
void					ft_acts(char *act, t_check *check);
void					init_check(t_check **check);
int						stack_check(t_check *check);
int						right_order(t_stack *stack);
int						ft_strchr_i(const char *s, int i);
int						biger_then_int(char *num);
int						dup_check(t_stack **stack);
void					not_instruction_error(char **act);
void					b_is_not_empty(t_check *check);
void					not_rigth_order_a(t_check *check);
void					border(char *act, t_stack **s_a, t_stack **s_b,
						t_check *check);
void					stack_show(t_check *check);
void					b_s(t_stack *s_b, t_check *check);
void					a_s(t_stack *s_a, t_check *check);
void					a_b(t_stack *s_a, t_stack *s_b, t_check *check);
#endif
