/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func_both.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichubare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/02 15:02:47 by ichubare          #+#    #+#             */
/*   Updated: 2017/03/23 14:32:49 by ichubare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_ss(t_stack **stack_a, t_stack **stack_b)
{
	size_t	len_a;
	size_t	len_b;

	len_a = 0;
	len_b = 0;
	len_stack(*stack_a, &len_a);
	len_stack(*stack_b, &len_b);
	ft_sa(stack_a, len_a);
	ft_sb(stack_b, len_b);
}

void	ft_rr(t_stack **stack_a, t_stack **stack_b)
{
	size_t	len_a;
	size_t	len_b;

	len_a = 0;
	len_b = 0;
	len_stack(*stack_a, &len_a);
	len_stack(*stack_b, &len_b);
	ft_ra(stack_a, len_a);
	ft_rb(stack_b, len_b);
}

void	ft_rrr(t_stack **stack_a, t_stack **stack_b)
{
	size_t	len_a;
	size_t	len_b;

	len_a = 0;
	len_b = 0;
	len_stack(*stack_a, &len_a);
	len_stack(*stack_b, &len_b);
	ft_rra(stack_a, len_a);
	ft_rrb(stack_b, len_b);
}
