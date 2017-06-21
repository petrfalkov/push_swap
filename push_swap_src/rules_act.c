/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules_act.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichubare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/19 16:46:04 by ichubare          #+#    #+#             */
/*   Updated: 2017/03/19 16:58:44 by ichubare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	del_rules(t_rules **rules)
{
	t_rules *temp;

	temp = (*rules)->next->next;
	free((*rules)->next);
	(*rules)->next = temp;
	temp = (*rules)->next->next;
	free((*rules)->next);
	(*rules)->next = temp;
}

void	rules_in(t_rules **rules, char *rul)
{
	t_rules *temp;
	t_rules *change;

	change = (t_rules*)malloc(sizeof(t_rules));
	change->data = rul;
	temp = (*rules)->next->next;
	free((*rules)->next);
	(*rules)->next = temp;
	temp = (*rules)->next->next;
	change->next = temp;
	free((*rules)->next);
	(*rules)->next = change;
}

void	del_rule(t_rules **stack)
{
	t_rules	*temp;

	if (*stack)
	{
		temp = (*stack)->next;
		free(*stack);
		*stack = temp;
	}
}

void	add_rules(t_rules **rules, char *data)
{
	t_rules *new;

	new = (t_rules*)malloc(sizeof(t_rules));
	new->next = NULL;
	new->data = data;
	if (!(*rules))
		*rules = new;
	else
	{
		new->next = *rules;
		*rules = new;
	}
}
