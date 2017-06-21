/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func_a.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichubare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/02 15:02:02 by ichubare          #+#    #+#             */
/*   Updated: 2017/03/16 13:14:14 by ichubare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	ft_sa(t_stack **stack, size_t len)
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

void	ft_pa(t_stack **stack_a, t_stack **stack_b, size_t len_b)
{
	t_stack *temp;

	if (len_b > 0)
	{
		temp = *stack_b;
		add_new_elem(stack_a, temp->data);
		del_elem(stack_b);
	}
}

void	ft_ra(t_stack **stack, size_t len)
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

void	ft_rra(t_stack **stack, size_t len)
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
