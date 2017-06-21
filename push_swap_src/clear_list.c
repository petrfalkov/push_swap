/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear_list.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichubare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/19 16:43:39 by ichubare          #+#    #+#             */
/*   Updated: 2017/03/23 14:45:26 by ichubare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		clear_list_rr(t_rules *temp)
{
	int		i;
	t_rules	*rules;

	i = 0;
	rules = temp;
	while (rules && rules->next)
	{
		if (((ft_strcmp("ra", rules->data) == 0)
					&& (ft_strcmp("rb", rules->next->data) == 0))
				|| ((ft_strcmp("rb", rules->data) == 0)
					&& (ft_strcmp("ra", rules->next->data) == 0)))
			return (i);
		i++;
		rules = rules->next;
	}
	return (-1);
}

int		clear_list_rrr(t_rules *temp)
{
	int		i;
	t_rules	*rules;

	i = 0;
	rules = temp;
	while (rules && rules->next)
	{
		if (((ft_strcmp("rra", rules->data) == 0)
					&& (ft_strcmp("rrb", rules->next->data) == 0))
				|| ((ft_strcmp("rrb", rules->data) == 0)
					&& (ft_strcmp("rra", rules->next->data) == 0)))
			return (i);
		i++;
		rules = rules->next;
	}
	return (-1);
}

int		clear_list_s(t_rules *temp)
{
	int		i;
	t_rules	*rules;

	i = 0;
	rules = temp;
	while (rules && rules->next)
	{
		if (((ft_strcmp("sa", rules->data) == 0)
					&& (ft_strcmp("sb", rules->next->data) == 0))
				|| ((ft_strcmp("sb", rules->data) == 0)
					&& (ft_strcmp("sa", rules->next->data) == 0)))
			return (i);
		i++;
		rules = rules->next;
	}
	return (-1);
}

int		clear_list_p(t_rules *temp)
{
	t_rules	*rules;
	int		i;

	i = 0;
	rules = temp;
	while (rules && rules->next)
	{
		if (((ft_strcmp("pb", rules->data) == 0)
					&& (ft_strcmp("pa", rules->next->data) == 0))
				|| ((ft_strcmp("pa", rules->data) == 0)
					&& (ft_strcmp("pb", rules->next->data) == 0)))
			return (i);
		i++;
		rules = rules->next;
	}
	return (-1);
}

int		clear_list_r(t_rules *temp)
{
	int		i;
	t_rules	*rules;

	i = 0;
	rules = temp;
	while (rules && rules->next)
	{
		if (((ft_strcmp("rra", rules->data) == 0)
					&& (ft_strcmp("ra", rules->next->data) == 0))
				|| ((ft_strcmp("rrb", rules->data) == 0)
					&& (ft_strcmp("rb", rules->next->data) == 0))
				|| ((ft_strcmp("ra", rules->data) == 0)
					&& (ft_strcmp("rra", rules->next->data) == 0))
				|| ((ft_strcmp("rb", rules->data) == 0)
					&& (ft_strcmp("rrb", rules->next->data) == 0)))
			return (i);
		i++;
		rules = rules->next;
	}
	return (-1);
}
