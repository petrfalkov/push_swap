/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_act.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichubare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/02 18:04:42 by ichubare          #+#    #+#             */
/*   Updated: 2017/03/16 13:15:51 by ichubare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	init_check(t_check **check)
{
	*check = (t_check*)malloc(sizeof(t_check));
	(*check)->next = NULL;
	(*check)->stack_a = NULL;
	(*check)->stack_b = NULL;
	(*check)->v_flag = 0;
	(*check)->c_flag = 0;
}

void	len_stack(t_stack *stack, size_t *len)
{
	size_t	leng;

	leng = 0;
	while (stack)
	{
		leng++;
		stack = stack->next;
	}
	*len = leng;
}

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
