/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show_act.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichubare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/21 16:23:25 by ichubare          #+#    #+#             */
/*   Updated: 2017/03/26 14:19:46 by ichubare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	a_b(t_stack *s_a, t_stack *s_b, t_check *check)
{
	char	*a;
	char	*b;

	a = ft_itoa_base(s_a->data, 10);
	b = ft_itoa_base(s_b->data, 10);
	if (check->c_flag == 1)
	{
		write(1, GREEN, ft_strlen(GREEN));
		write(1, a, ft_strlen(a));
		write(1, "               ", 15 - ft_strlen(a));
		write(1, YELLOW, ft_strlen(YELLOW));
		write(1, "|               ", 16 - ft_strlen(b));
		write(1, RED, ft_strlen(RED));
		write(1, b, ft_strlen(b));
	}
	else
	{
		write(1, a, ft_strlen(a));
		write(1, "               ", 15 - ft_strlen(a));
		write(1, "|               ", 16 - ft_strlen(b));
		write(1, b, ft_strlen(b));
	}
	write(1, RESET"\n", ft_strlen(RESET) + 1);
	free(a);
	free(b);
}

void	a_s(t_stack *s_a, t_check *check)
{
	char	*a;

	a = ft_itoa_base(s_a->data, 10);
	if (check->c_flag == 1)
	{
		write(1, GREEN, ft_strlen(GREEN));
		write(1, a, ft_strlen(a));
		write(1, "               ", 15 - ft_strlen(a));
		write(1, YELLOW, ft_strlen(YELLOW));
	}
	else
	{
		write(1, a, ft_strlen(a));
		write(1, "               ", 15 - ft_strlen(a));
	}
	free(a);
	write(1, "|\n", 2);
	write(1, RESET, ft_strlen(RESET));
}

void	b_s(t_stack *s_b, t_check *check)
{
	char	*b;

	b = ft_itoa_base(s_b->data, 10);
	if (check->c_flag == 1)
	{
		write(1, "               ", 15);
		write(1, YELLOW, ft_strlen(YELLOW));
		write(1, "|               ", 16 - ft_strlen(b));
		write(1, RED, ft_strlen(RED));
		write(1, b, ft_strlen(b));
	}
	else
	{
		write(1, "               ", 15);
		write(1, "|               ", 16 - ft_strlen(b));
		write(1, b, ft_strlen(b));
	}
	write(1, "\n", 1);
	write(1, RESET, ft_strlen(RESET));
	free(b);
}

void	stack_show(t_check *check)
{
	if (check->c_flag == 1)
	{
		write(1, GREEN, ft_strlen(GREEN));
		write(1, "stack_a", 7);
		write(1, "               ", 8);
		write(1, YELLOW, ft_strlen(YELLOW));
		write(1, "|               ", 8);
		write(1, RED, ft_strlen(RED));
		write(1, "stack_b\n", 8);
	}
	else
	{
		write(1, "stack_a", 7);
		write(1, "               ", 8);
		write(1, "|               ", 8);
		write(1, "stack_b\n", 8);
	}
	write(1, RESET, ft_strlen(RESET));
	write(1, "\n", 1);
}

void	border(char *act, t_stack **s_a, t_stack **s_b, t_check *check)
{
	*s_a = check->stack_a;
	*s_b = check->stack_b;
	if (check->c_flag == 1)
		write(1, YELLOW, ft_strlen(YELLOW));
	write(1, "-------------------------------\n", 32);
	write(1, "                 ", 17 - ft_strlen(act));
	write(1, act, ft_strlen(act));
	write(1, "\n-------------------------------\n", 33);
	write(1, RESET, ft_strlen(RESET));
}
