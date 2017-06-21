/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func_b.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichubare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/02 15:02:25 by ichubare          #+#    #+#             */
/*   Updated: 2017/03/16 13:14:27 by ichubare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	ft_sb(t_stack **stack, size_t len)
{
	t_stack *temp;
	t_stack *temp2;

	if (len > 1)
	{
		temp = *stack;
		temp2 = (*stack)->next;
		temp->next = temp2->next;
		temp2->next = temp;
		*stack = temp2;
	}
}

void	ft_pb(t_stack **stack_b, t_stack **stack_a, size_t len_a)
{
	t_stack *temp;

	if (len_a > 0)
	{
		temp = *stack_a;
		add_new_elem(stack_b, temp->data);
		del_elem(stack_a);
	}
}

void	ft_rb(t_stack **stack, size_t len)
{
	t_stack	*temp;
	t_stack *new;

	if (len > 1)
	{
		new = *stack;
		*stack = (*stack)->next;
		temp = *stack;
		new->next = NULL;
		while ((*stack)->next)
			*stack = (*stack)->next;
		(*stack)->next = new;
		*stack = temp;
	}
}

void	ft_rrb(t_stack **stack, size_t len)
{
	t_stack	*temp;
	t_stack *new;

	if (len > 1)
	{
		temp = *stack;
		new = *stack;
		while ((temp->next)->next)
			temp = temp->next;
		while (new->next)
			new = new->next;
		temp->next = NULL;
		new->next = *stack;
		*stack = new;
	}
}
