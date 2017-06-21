/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chose_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichubare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/19 19:38:53 by ichubare          #+#    #+#             */
/*   Updated: 2017/03/19 20:10:21 by ichubare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		get_nr_sort(t_stack **stack)
{
	t_stack *mid;
	t_stack *last;

	mid = (*stack)->next;
	last = mid->next;
	if ((*stack)->data > mid->data && (*stack)->data > last->data
			&& mid->data < last->data)
		return (5);
	else if ((*stack)->data > mid->data && (*stack)->data > last->data
			&& mid->data > last->data)
		return (4);
	else if ((*stack)->data < mid->data && (*stack)->data > last->data
			&& mid->data > last->data)
		return (3);
	else if ((*stack)->data > mid->data && (*stack)->data < last->data
			&& mid->data < last->data)
		return (2);
	else if ((*stack)->data < mid->data && (*stack)->data < last->data
			&& mid->data > last->data)
		return (1);
	return (0);
}

void	not_rev_sort(t_push_swap *p_s, int len)
{
	int		n_sort;

	if (len == 1 || len == 2)
	{
		if (len == 2 && p_s->stack_a->data > p_s->stack_a->next->data)
		{
			add_rules(&p_s->rules, "sa");
			ft_sa(&p_s->stack_a, p_s->len_a);
		}
	}
	else if (len == 3)
	{
		n_sort = get_nr_sort(&p_s->stack_a);
		n_sort == 1 ? sort_1a(p_s) : 0;
		n_sort == 2 ? sort_2a(p_s) : 0;
		n_sort == 3 ? sort_3a(p_s) : 0;
		n_sort == 4 ? sort_4a(p_s) : 0;
		n_sort == 5 ? sort_5a(p_s) : 0;
	}
}

int		get_r_sort(t_stack **stack)
{
	t_stack	*mid;
	t_stack	*last;

	mid = (*stack)->next;
	last = mid->next;
	if ((*stack)->data > mid->data && (*stack)->data > last->data
			&& mid->data < last->data)
		return (1);
	else if ((*stack)->data < mid->data && (*stack)->data > last->data
			&& mid->data > last->data)
		return (2);
	else if ((*stack)->data > mid->data && (*stack)->data < last->data
			&& mid->data < last->data)
		return (3);
	else if ((*stack)->data < mid->data && (*stack)->data < last->data
			&& mid->data < last->data)
		return (4);
	else if ((*stack)->data < mid->data && (*stack)->data < last->data
			&& mid->data > last->data)
		return (5);
	return (0);
}

void	rev_sort(t_push_swap *p_s, int len)
{
	int		n_sort;

	if (len == 1 || len == 2)
	{
		if (len == 2 && p_s->stack_b->data < p_s->stack_b->next->data)
		{
			add_rules(&p_s->rules, "sb");
			ft_sb(&p_s->stack_b, p_s->len_b);
		}
	}
	else if (len == 3)
	{
		n_sort = get_r_sort(&p_s->stack_b);
		n_sort == 1 ? sort_1b(p_s) : 0;
		n_sort == 2 ? sort_2b(p_s) : 0;
		n_sort == 3 ? sort_3b(p_s) : 0;
		n_sort == 4 ? sort_4b(p_s) : 0;
		n_sort == 5 ? sort_5b(p_s) : 0;
	}
}

void	sort(t_push_swap *p_s, int len, int rev)
{
	if (!rev)
	{
		if (!right_order_a(p_s->stack_a))
			not_rev_sort(p_s, len);
	}
	else
	{
		if (!right_order_b(p_s->stack_b))
			rev_sort(p_s, len);
	}
}
