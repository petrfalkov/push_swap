/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   order_ch.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichubare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/19 15:31:26 by ichubare          #+#    #+#             */
/*   Updated: 2017/03/21 16:32:31 by ichubare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		right_order_a(t_stack *stack)
{
	int		num;

	if (s_len(stack) != 0)
	{
		num = stack->data;
		stack = stack->next;
		while (stack)
		{
			if (num < stack->data)
			{
				num = stack->data;
				stack = stack->next;
			}
			else
				return (0);
		}
	}
	return (1);
}

int		right_order_b(t_stack *stack)
{
	int num;

	if (stack)
	{
		num = stack->data;
		stack = stack->next;
		while (stack)
		{
			if (num > stack->data)
			{
				num = stack->data;
				stack = stack->next;
			}
			else
				return (0);
		}
		return (1);
	}
	return (0);
}

int		not_num_error(char ***arr, t_stack **stack, int pos)
{
	int		i;

	i = 0;
	write(1, "Not a number [", 14);
	write(1, (*arr)[pos], ft_strlen((*arr)[pos]));
	write(1, "].\n", 3);
	while ((*arr)[i])
	{
		free((*arr)[i]);
		i++;
	}
	while (*stack)
		del_elem(stack);
	return (-1);
}

int		bigger_then_int_error(char ***arr, t_stack **stack, int pos)
{
	int		i;

	i = 0;
	write(1, "Bigger then INT [", 17);
	write(1, (*arr)[pos], ft_strlen((*arr)[pos]));
	write(1, "].\n", 3);
	while ((*arr)[i])
	{
		free((*arr)[i]);
		i++;
	}
	while (*stack)
		del_elem(stack);
	return (-1);
}

int		stack_ps_check(t_push_swap *check)
{
	size_t len;

	len = 0;
	len_stack(check->stack_b, &len);
	if (len > 0)
		return (0);
	if (!(right_order_a(check->stack_a)))
		return (0);
	return (1);
}
