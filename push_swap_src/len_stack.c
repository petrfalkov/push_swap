/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   len_stack.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichubare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/19 16:22:53 by ichubare          #+#    #+#             */
/*   Updated: 2017/03/19 16:22:55 by ichubare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

int		s_len(t_stack *stack)
{
	int		len;

	len = 0;
	while (stack)
	{
		len++;
		stack = stack->next;
	}
	return (len);
}
