/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichubare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/01 18:15:52 by ichubare          #+#    #+#             */
/*   Updated: 2017/03/26 13:59:37 by ichubare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	out_put(t_push_swap *p_s)
{
	t_rules *rules;

	rules = NULL;
	while (p_s->rules)
	{
		add_rules(&rules, p_s->rules->data);
		del_rule(&p_s->rules);
	}
	while (p_s->stack_a)
		del_elem(&p_s->stack_a);
	while (rules)
	{
		write(1, rules->data, ft_strlen(rules->data));
		write(1, "\n", 1);
		del_rule(&rules);
	}
}

int		main(int argc, char **argv)
{
	t_push_swap	*p_s;

	init_p_s(&p_s, argc);
	if (check_args_p(argc, argv, &p_s->stack_a) == -1)
	{
		while (p_s->stack_a)
			del_elem(&p_s->stack_a);
		return (0);
	}
	else
	{
		if (stack_ps_check(p_s))
			return (0);
		while (!stack_ps_check(p_s))
			find_rules(p_s, s_len(p_s->stack_a));
		clean_list(p_s);
		out_put(p_s);
	}
	return (0);
}
