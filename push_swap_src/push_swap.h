/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichubare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/19 16:28:14 by ichubare          #+#    #+#             */
/*   Updated: 2017/03/23 14:32:05 by ichubare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../ft_printf/ft_printf.h"

typedef struct			s_stack
{
	int					data;
	struct s_stack		*next;
}						t_stack;

typedef struct			s_rules
{
	char				*data;
	struct s_rules		*next;
}						t_rules;

typedef struct			s_push_swap
{
	t_stack				*stack_a;
	t_stack				*stack_b;
	t_rules				*rules;
	size_t				len;
	size_t				len_a;
	size_t				len_b;
	struct s_push_swap	*next;
}						t_push_swap;

void					add_new_elem(t_stack **stack, int data);
void					len_stack(t_stack *stack, size_t *len);
void					ft_sa(t_stack **stack_a, size_t len);
void					del_elem(t_stack **stack);
void					ft_pa(t_stack **stack_a, t_stack **stack_b,
						size_t len_b);
void					ft_ra(t_stack **stack_a, size_t len);
void					ft_rra(t_stack **stack_a, size_t len);
void					ft_sb(t_stack **stack_b, size_t len);
void					ft_pb(t_stack **stack_b, t_stack **stack_a,
						size_t len_a);
void					ft_rb(t_stack **stack_b, size_t len);
void					ft_rrb(t_stack **stack_b, size_t len);
int						check_args_p(int argc, char **argv, t_stack **stack_a);
int						stack_ps_check(t_push_swap *check);
void					init_p_s(t_push_swap **p_s, int argc);
void					add_rules(t_rules **rules, char *data);
int						right_order_b(t_stack *stack);
int						right_order_a(t_stack *stack);
void					find_rules(t_push_swap *p_s, int len);
void					del_rule(t_rules **stack);
int						s_len(t_stack *stack);
int						dup_check(t_stack **stack);
int						stack_ps_check(t_push_swap *check);
int						right_order_b(t_stack *stack);
int						right_order_a(t_stack *stack);
int						not_num_error(char ***arr, t_stack **stack, int pos);
int						bigger_then_int_error(char ***arr, t_stack **stack,
						int pos);
void					clean_list(t_push_swap *p_s);
void					clean_list_rrr(t_rules **rules, int point);
int						clear_list_rrr(t_rules *rules);
void					clean_list_rr(t_rules **rules, int point);
int						clear_list_rr(t_rules *temp);
void					clean_list_rp(t_rules **rules, int point);
int						clear_list_r(t_rules *temp);
void					clean_list_s(t_rules **rules, int point);
int						clear_list_s(t_rules *temp);
int						clear_list_p(t_rules *temp);
void					rules_in(t_rules **rules, char *rul);
void					del_rules(t_rules **rules);
void					find_mid_b(int len, int *mid_num, t_stack *stack_b);
void					sort_1a(t_push_swap *p_s);
void					sort_2a(t_push_swap *p_s);
void					sort_3a(t_push_swap *p_s);
void					sort_4a(t_push_swap *p_s);
void					sort_5a(t_push_swap *p_s);
void					sort_1b(t_push_swap *p_s);
void					sort_2b(t_push_swap *p_s);
void					sort_3b(t_push_swap *p_s);
void					sort_4b(t_push_swap *p_s);
void					sort_5b(t_push_swap *p_s);
void					sort(t_push_swap *p_s, int len, int rev);
int						less_pivos_b(t_stack *stack, int mid_num);
int						less_pivos(t_push_swap *p_s, int mid);
void					find_rules_rev(t_push_swap *p_s, int len);
void					zero_len(t_push_swap *p_s);

#endif
