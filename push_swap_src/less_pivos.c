/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   less_pivos.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichubare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/19 20:15:49 by ichubare          #+#    #+#             */
/*   Updated: 2017/03/19 20:15:50 by ichubare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		less_pivos(t_push_swap *p_s, int mid)
{
	t_stack *temp;

	temp = p_s->stack_a;
	while (temp && temp->data != mid)
	{
		if (temp->data < mid)
			return (1);
		temp = temp->next;
	}
	if (temp && temp->next)
	{
		temp = temp->next;
		while (temp)
		{
			if (temp->data < mid)
				return (1);
			temp = temp->next;
		}
	}
	return (0);
}

int		less_pivos_b(t_stack *stack, int mid_num)
{
	t_stack *temp;

	temp = stack;
	while (temp && temp->data != mid_num)
	{
		if (temp->data > mid_num)
			return (1);
		temp = temp->next;
	}
	if (temp && temp->next)
	{
		temp = temp->next;
		while (temp)
		{
			if (temp->data > mid_num)
				return (1);
			temp = temp->next;
		}
	}
	return (0);
}
