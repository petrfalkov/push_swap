/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   acts.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichubare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/03 15:03:21 by ichubare          #+#    #+#             */
/*   Updated: 2017/03/20 17:46:43 by ichubare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	ft_a_acts(char *act, t_check *check)
{
	size_t	len;
	size_t	len_b;

	len = 0;
	len_b = 0;
	len_stack(check->stack_a, &len);
	len_stack(check->stack_b, &len_b);
	if (ft_strcmp(act, "sa") == 0 && len > 1)
		ft_sa(&check->stack_a, len);
	else if (ft_strcmp(act, "pa") == 0)
		ft_pa(&check->stack_a, &check->stack_b, len_b);
	else if (ft_strcmp(act, "ra") == 0 && len > 1)
		ft_ra(&check->stack_a, len);
	else if (ft_strcmp(act, "rra") == 0 && len > 1)
		ft_rra(&check->stack_a, len);
}

void	ft_b_acts(char *act, t_check *check)
{
	size_t	len;
	size_t	len_a;

	len = 0;
	len_a = 0;
	len_stack(check->stack_b, &len);
	len_stack(check->stack_a, &len_a);
	if (ft_strcmp(act, "sb") == 0 && len > 1)
		ft_sb(&check->stack_b, len);
	else if (ft_strcmp(act, "pb") == 0)
		ft_pb(&check->stack_b, &check->stack_a, len_a);
	else if (ft_strcmp(act, "rb") == 0 && len > 1)
		ft_rb(&check->stack_b, len);
	else if (ft_strcmp(act, "rrb") == 0 && len > 1)
		ft_rrb(&check->stack_b, len);
}

void	ft_both_acts(char *act, t_check *check)
{
	if (ft_strcmp(act, "ss") == 0)
		ft_ss(&check->stack_a, &check->stack_b);
	else if (ft_strcmp(act, "rr") == 0)
		ft_rr(&check->stack_a, &check->stack_b);
	else
		ft_rrr(&check->stack_a, &check->stack_b);
}

void	ft_acts(char *act, t_check *check)
{
	if (ft_strcmp(act, "sa") == 0 || ft_strcmp(act, "pa") == 0
			|| ft_strcmp(act, "ra") == 0 || ft_strcmp(act, "rra") == 0)
		ft_a_acts(act, check);
	else if (ft_strcmp(act, "sb") == 0 || ft_strcmp(act, "pb") == 0
		|| ft_strcmp(act, "rb") == 0 || ft_strcmp(act, "rrb") == 0)
		ft_b_acts(act, check);
	else
		ft_both_acts(act, check);
}
