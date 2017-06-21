/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_a.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichubare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/19 19:29:14 by ichubare          #+#    #+#             */
/*   Updated: 2017/03/19 19:34:39 by ichubare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_1a(t_push_swap *p_s)
{
	t_stack *mid;
	t_stack *last;

	last = p_s->stack_a->next;
	mid = last->next;
	if (!mid->next)
	{
		add_rules(&p_s->rules, "rra");
		add_rules(&p_s->rules, "sa");
		ft_rra(&p_s->stack_a, p_s->len_a);
		ft_sa(&p_s->stack_a, p_s->len_a);
	}
	else
	{
		add_rules(&p_s->rules, "ra");
		add_rules(&p_s->rules, "sa");
		add_rules(&p_s->rules, "rra");
		ft_ra(&p_s->stack_a, p_s->len_a);
		ft_sa(&p_s->stack_a, p_s->len_a);
		ft_rra(&p_s->stack_a, p_s->len_a);
	}
}

void	sort_2a(t_push_swap *p_s)
{
	add_rules(&p_s->rules, "sa");
	ft_sa(&p_s->stack_a, p_s->len_a);
}

void	sort_3a(t_push_swap *p_s)
{
	t_stack *mid;
	t_stack *last;

	last = p_s->stack_a->next;
	mid = last->next;
	if (!mid->next)
	{
		add_rules(&p_s->rules, "rra");
		ft_rra(&p_s->stack_a, p_s->len_a);
	}
	else
	{
		add_rules(&p_s->rules, "ra");
		add_rules(&p_s->rules, "sa");
		add_rules(&p_s->rules, "rra");
		add_rules(&p_s->rules, "sa");
		ft_ra(&p_s->stack_a, p_s->len_a);
		ft_sa(&p_s->stack_a, p_s->len_a);
		ft_rra(&p_s->stack_a, p_s->len_a);
		ft_sa(&p_s->stack_a, p_s->len_a);
	}
}

void	sort_4a(t_push_swap *p_s)
{
	t_stack *mid;
	t_stack *last;

	last = p_s->stack_a->next;
	mid = last->next;
	if (!mid->next)
	{
		add_rules(&p_s->rules, "ra");
		add_rules(&p_s->rules, "sa");
		ft_ra(&p_s->stack_a, p_s->len_a);
		ft_sa(&p_s->stack_a, p_s->len_a);
	}
	else
	{
		add_rules(&p_s->rules, "sa");
		add_rules(&p_s->rules, "ra");
		add_rules(&p_s->rules, "sa");
		add_rules(&p_s->rules, "rra");
		add_rules(&p_s->rules, "sa");
		ft_sa(&p_s->stack_a, p_s->len_a);
		ft_ra(&p_s->stack_a, p_s->len_a);
		ft_sa(&p_s->stack_a, p_s->len_a);
		ft_rra(&p_s->stack_a, p_s->len_a);
		ft_sa(&p_s->stack_a, p_s->len_a);
	}
}

void	sort_5a(t_push_swap *p_s)
{
	t_stack *mid;
	t_stack *last;

	last = p_s->stack_a->next;
	mid = last->next;
	if (!mid->next)
	{
		add_rules(&p_s->rules, "ra");
		ft_ra(&p_s->stack_a, p_s->len_a);
	}
	else
	{
		add_rules(&p_s->rules, "sa");
		add_rules(&p_s->rules, "ra");
		add_rules(&p_s->rules, "sa");
		add_rules(&p_s->rules, "rra");
		ft_sa(&p_s->stack_a, p_s->len_a);
		ft_ra(&p_s->stack_a, p_s->len_a);
		ft_sa(&p_s->stack_a, p_s->len_a);
		ft_rra(&p_s->stack_a, p_s->len_a);
	}
}
