/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_rules_rev.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichubare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/19 20:41:54 by ichubare          #+#    #+#             */
/*   Updated: 2017/03/19 20:48:01 by ichubare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		separate_b(t_push_swap *p_s,
		int *len, int *count_push, int *count_rotate)
{
	int		stack_len;
	int		mid;

	stack_len = *len;
	*count_push = 0;
	*count_rotate = 0;
	find_mid_b(stack_len, &mid, p_s->stack_b);
	while (((*len) - 1) >= 0 && less_pivos_b(p_s->stack_b, mid) && (*len)--)
	{
		if (p_s->stack_b->data > mid)
		{
			add_rules(&p_s->rules, "pa");
			ft_pa(&p_s->stack_a, &p_s->stack_b, p_s->len_a--);
			(*count_push)++;
		}
		else
		{
			add_rules(&p_s->rules, "rb");
			ft_rb(&p_s->stack_b, p_s->len_b);
			(*count_rotate)++;
		}
	}
	return (stack_len);
}

void	find_rules_rev(t_push_swap *p_s, int len)
{
	int		count_push;
	int		stack_len;
	int		count_rotate;

	len_stack(p_s->stack_a, &p_s->len_a);
	len_stack(p_s->stack_b, &p_s->len_b);
	if (len <= 3)
		return (sort(p_s, len, 1));
	stack_len = separate_b(p_s, &len, &count_push, &count_rotate);
	zero_len(p_s);
	find_rules(p_s, count_push);
	len_stack(p_s->stack_b, &p_s->len_b);
	while (count_rotate-- && s_len(p_s->stack_b) + count_push != stack_len)
	{
		add_rules(&p_s->rules, "rrb");
		ft_rrb(&p_s->stack_b, p_s->len_b);
	}
	find_rules_rev(p_s, stack_len - count_push);
	len_stack(p_s->stack_a, &p_s->len_a);
	while (count_push--)
	{
		add_rules(&p_s->rules, "pb");
		ft_pb(&p_s->stack_b, &p_s->stack_a, p_s->len_a--);
	}
	zero_len(p_s);
}
