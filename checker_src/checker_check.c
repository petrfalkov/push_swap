/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_check.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichubare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/03 15:01:22 by ichubare          #+#    #+#             */
/*   Updated: 2017/03/26 14:16:18 by ichubare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int		right_order(t_stack *stack)
{
	int num;

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
	return (1);
}

int		stack_check(t_check *check)
{
	size_t	len;

	len = 0;
	len_stack(check->stack_b, &len);
	if (len > 0)
	{
		b_is_not_empty(check);
		return (0);
	}
	if (!(right_order(check->stack_a)))
	{
		not_rigth_order_a(check);
		return (0);
	}
	return (1);
}

int		is_instruction(char *act)
{
	if (ft_strcmp(act, "sa") == 0 || ft_strcmp(act, "sb") == 0 ||
		ft_strcmp(act, "ss") == 0 || ft_strcmp(act, "pa") == 0 ||
		ft_strcmp(act, "pb") == 0 || ft_strcmp(act, "ra") == 0 ||
		ft_strcmp(act, "rb") == 0 || ft_strcmp(act, "rr") == 0 ||
		ft_strcmp(act, "rra") == 0 || ft_strcmp(act, "rrb") == 0 ||
		ft_strcmp(act, "rrr") == 0)
		return (1);
	return (-1);
}

void	show_act(t_check *check, char *act)
{
	t_stack	*s_a;
	t_stack	*s_b;

	border(act, &s_a, &s_b, check);
	while (s_a || s_b)
	{
		if (s_a && s_b)
		{
			a_b(s_a, s_b, check);
			s_a = s_a->next;
			s_b = s_b->next;
		}
		else if (s_a)
		{
			a_s(s_a, check);
			s_a = s_a->next;
		}
		else if (s_b)
		{
			b_s(s_b, check);
			s_b = s_b->next;
		}
	}
	stack_show(check);
}

int		read_acts(t_check *check)
{
	char	*act;
	int		i;

	i = 0;
	(i == 0 && (check->v_flag || check->c_flag))
		? (show_act(check, "Start")) : 0;
	while ((get_next_line(0, &act)) == 1)
	{
		if (is_instruction(act) == -1)
		{
			not_instruction_error(&act);
			return (-1);
		}
		else
		{
			ft_acts(act, check);
			if (check->v_flag || check->c_flag)
				show_act(check, act);
		}
		i++;
		free(act);
	}
	if (stack_check(check))
		return (1);
	return (0);
}
