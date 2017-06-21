/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_act.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichubare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/02 18:04:42 by ichubare          #+#    #+#             */
/*   Updated: 2017/03/19 16:22:10 by ichubare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	add_new_elem(t_stack **stack, int data)
{
	t_stack *new;

	new = (t_stack*)malloc(sizeof(t_stack));
	new->next = NULL;
	new->data = data;
	if (!(*stack))
		*stack = new;
	else
	{
		new->next = *stack;
		*stack = new;
	}
}

void	init_p_s(t_push_swap **p_s, int argc)
{
	*p_s = (t_push_swap*)malloc(sizeof(t_push_swap));
	(*p_s)->next = NULL;
	(*p_s)->stack_a = NULL;
	(*p_s)->stack_b = NULL;
	(*p_s)->len = (size_t)(argc - 1);
	(*p_s)->len_b = 0;
	(*p_s)->len_a = 0;
	(*p_s)->rules = NULL;
}

void	del_elem(t_stack **stack)
{
	t_stack	*temp;

	if (*stack)
	{
		temp = (*stack)->next;
		free(*stack);
		*stack = temp;
	}
}
