/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_rules.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichubare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/19 20:17:33 by ichubare          #+#    #+#             */
/*   Updated: 2017/03/19 20:41:11 by ichubare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	zero_len(t_push_swap *p_s)
{
	p_s->len_a = 0;
	p_s->len_b = 0;
}

int		separate_a(t_push_swap *p_s,
		int *len, int *count_push, int *count_rotate)
{
	int		stack_len;
	int		mid;

	stack_len = *len;
	*count_push = 0;
	*count_rotate = 0;
	find_mid_b(stack_len, &mid, p_s->stack_a);
	while (((*len) - 1) >= 0 && less_pivos(p_s, mid) && (*len)--)
	{
		if (p_s->stack_a->data <= mid)
		{
			add_rules(&p_s->rules, "pb");
			ft_pb(&p_s->stack_b, &p_s->stack_a, p_s->len_a--);
			(*count_push)++;
		}
		else
		{
			add_rules(&p_s->rules, "ra");
			ft_ra(&p_s->stack_a, p_s->len_a);
			(*count_rotate)++;
		}
	}
	return (stack_len);
}

void	find_rules(t_push_swap *p_s, int len)
{
	int		count_push;
	int		count_rotate;
	int		stack_len;

	zero_len(p_s);
	len_stack(p_s->stack_a, &p_s->len_a);
	len_stack(p_s->stack_b, &p_s->len_b);
	if (len <= 3)
		return (sort(p_s, len, 0));
	stack_len = separate_a(p_s, &len, &count_push, &count_rotate);
	while (count_rotate-- && s_len(p_s->stack_a) + count_push != stack_len)
	{
		add_rules(&p_s->rules, "rra");
		ft_rra(&p_s->stack_a, p_s->len_a);
	}
	zero_len(p_s);
	find_rules(p_s, stack_len - count_push);
	find_rules_rev(p_s, count_push);
	len_stack(p_s->stack_b, &p_s->len_b);
	while (count_push--)
	{
		add_rules(&p_s->rules, "pa");
		ft_pa(&p_s->stack_a, &p_s->stack_b, p_s->len_b--);
	}
	zero_len(p_s);
}
