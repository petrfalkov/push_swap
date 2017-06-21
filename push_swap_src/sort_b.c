/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_b.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichubare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/19 19:29:02 by ichubare          #+#    #+#             */
/*   Updated: 2017/03/19 19:38:03 by ichubare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_1b(t_push_swap *p_s)
{
	t_stack *mid;
	t_stack *last;

	last = p_s->stack_b->next;
	mid = last->next;
	if (!mid->next)
	{
		add_rules(&p_s->rules, "rrb");
		add_rules(&p_s->rules, "sb");
		ft_rrb(&p_s->stack_b, p_s->len_b);
		ft_sb(&p_s->stack_b, p_s->len_b);
	}
	else
	{
		add_rules(&p_s->rules, "rb");
		add_rules(&p_s->rules, "sb");
		add_rules(&p_s->rules, "rrb");
		ft_rb(&p_s->stack_b, p_s->len_b);
		ft_sb(&p_s->stack_b, p_s->len_b);
		ft_rrb(&p_s->stack_b, p_s->len_b);
	}
}

void	sort_2b(t_push_swap *p_s)
{
	add_rules(&p_s->rules, "sb");
	ft_sb(&p_s->stack_b, p_s->len_b);
}

void	sort_3b(t_push_swap *p_s)
{
	t_stack *mid;
	t_stack *last;

	last = p_s->stack_b->next;
	mid = last->next;
	if (!mid->next)
	{
		add_rules(&p_s->rules, "rrb");
		ft_rrb(&p_s->stack_b, p_s->len_b);
	}
	else
	{
		add_rules(&p_s->rules, "rb");
		add_rules(&p_s->rules, "sb");
		add_rules(&p_s->rules, "rrb");
		add_rules(&p_s->rules, "sb");
		ft_rb(&p_s->stack_b, p_s->len_b);
		ft_sb(&p_s->stack_b, p_s->len_b);
		ft_rrb(&p_s->stack_b, p_s->len_b);
		ft_sb(&p_s->stack_b, p_s->len_b);
	}
}

void	sort_4b(t_push_swap *p_s)
{
	t_stack *mid;
	t_stack *last;

	last = p_s->stack_b->next;
	mid = last->next;
	if (!mid->next)
	{
		add_rules(&p_s->rules, "rb");
		add_rules(&p_s->rules, "sb");
		ft_rb(&p_s->stack_b, p_s->len_b);
		ft_sb(&p_s->stack_b, p_s->len_b);
	}
	else
	{
		add_rules(&p_s->rules, "sb");
		add_rules(&p_s->rules, "rb");
		add_rules(&p_s->rules, "sb");
		add_rules(&p_s->rules, "rrb");
		add_rules(&p_s->rules, "sb");
		ft_sb(&p_s->stack_b, p_s->len_b);
		ft_rb(&p_s->stack_b, p_s->len_b);
		ft_sb(&p_s->stack_b, p_s->len_b);
		ft_rrb(&p_s->stack_b, p_s->len_b);
		ft_sb(&p_s->stack_b, p_s->len_b);
	}
}

void	sort_5b(t_push_swap *p_s)
{
	t_stack *mid;
	t_stack *last;

	last = p_s->stack_b->next;
	mid = last->next;
	if (!mid->next)
	{
		add_rules(&p_s->rules, "rb");
		ft_rb(&p_s->stack_b, p_s->len_b);
	}
	else
	{
		add_rules(&p_s->rules, "sb");
		add_rules(&p_s->rules, "rb");
		add_rules(&p_s->rules, "sb");
		add_rules(&p_s->rules, "rrb");
		ft_sb(&p_s->stack_b, p_s->len_b);
		ft_rb(&p_s->stack_b, p_s->len_b);
		ft_sb(&p_s->stack_b, p_s->len_b);
		ft_rrb(&p_s->stack_b, p_s->len_b);
	}
}
