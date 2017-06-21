/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichubare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/21 15:00:18 by ichubare          #+#    #+#             */
/*   Updated: 2017/03/21 15:19:18 by ichubare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	not_instruction_error(char **act)
{
	write(1, "Is not instruction [", 20);
	write(1, *act, ft_strlen(*act));
	write(1, "].\n", 3);
	free(*act);
}

void	b_is_not_empty(t_check *check)
{
	write(1, "Stack 'B' is not empty.\n", 24);
	while (check->stack_a)
		del_elem(&check->stack_a);
	while (check->stack_b)
		del_elem(&check->stack_b);
}

void	not_rigth_order_a(t_check *check)
{
	write(1, "Stack 'A' is not sorted.\n", 25);
	while (check->stack_a)
		del_elem(&check->stack_a);
	while (check->stack_b)
		del_elem(&check->stack_b);
}
