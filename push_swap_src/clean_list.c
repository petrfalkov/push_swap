/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_list.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichubare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/19 16:37:00 by ichubare          #+#    #+#             */
/*   Updated: 2017/03/23 14:45:58 by ichubare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	clean_list_rp(t_rules **rules, int point)
{
	t_rules *temp;

	temp = *rules;
	while (--point > 0)
		(*rules) = (*rules)->next;
	del_rules(rules);
	*rules = temp;
}

void	clean_list_s(t_rules **rules, int point)
{
	t_rules *temp;

	temp = *rules;
	while (--point > 0)
		(*rules) = (*rules)->next;
	rules_in(rules, "ss");
	*rules = temp;
}

void	clean_list_rr(t_rules **rules, int point)
{
	t_rules *temp;

	temp = *rules;
	while (--point > 0)
		(*rules) = (*rules)->next;
	rules_in(rules, "rr");
	*rules = temp;
}

void	clean_list_rrr(t_rules **rules, int point)
{
	t_rules *temp;

	temp = *rules;
	while (--point > 0)
		(*rules) = (*rules)->next;
	rules_in(rules, "rrr");
	*rules = temp;
}

void	clean_list(t_push_swap *p_s)
{
	int point;

	while ((point = clear_list_s(p_s->rules)) != -1)
		clean_list_s(&p_s->rules, point);
	while ((point = clear_list_rrr(p_s->rules)) != -1)
		clean_list_rrr(&p_s->rules, point);
	while ((point = clear_list_rr(p_s->rules)) != -1)
		clean_list_rr(&p_s->rules, point);
	while ((point = clear_list_p(p_s->rules)) != -1)
		clean_list_rp(&p_s->rules, point);
	while ((point = clear_list_r(p_s->rules)) != -1)
		clean_list_rp(&p_s->rules, point);
}
