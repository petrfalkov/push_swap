/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_s_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichubare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/19 14:50:44 by ichubare          #+#    #+#             */
/*   Updated: 2017/03/19 15:43:50 by ichubare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		w_min(char *num)
{
	num++;
	if (num[0] > '2' || (num[0] == '2' && num[1] > '1') ||
		(num[0] == '2' && num[1] == '1' && num[2] > '4')
		|| (num[0] == '2' && num[1] == '1' && num[2] == '4' && num[3] > '7')
		|| (num[0] == '2' && num[1] == '1' && num[2] == '4'
			&& num[3] == '7' && num[4] > '4')
		|| (num[0] == '2' && num[1] == '1' && num[2] == '4'
			&& num[3] == '7' && num[4] == '4' && num[5] > '8')
		|| (num[0] == '2' && num[1] == '1' && num[2] == '4'
			&& num[3] == '7' && num[4] == '4' && num[5] == '8'
			&& num[6] > '3')
		|| (num[0] == '2' && num[1] == '1' && num[2] == '4'
			&& num[3] == '7' && num[4] == '4' && num[5] == '8'
			&& num[6] == '3' && num[7] > '6')
		|| (num[0] == '2' && num[1] == '1' && num[2] == '4'
			&& num[3] == '7' && num[4] == '4' && num[5] == '8'
			&& num[6] == '3' && num[7] == '6' && num[8] > '4')
		|| (num[0] == '2' && num[1] == '1' && num[2] == '4'
			&& num[3] == '7' && num[4] == '4' && num[5] == '8'
			&& num[6] == '3' && num[7] == '6' && num[8] == '4'
			&& num[9] > '8'))
		return (0);
	return (1);
}

int		w_o_min(char *num)
{
	if (num[0] > '2' || (num[0] == '2' && num[1] > '1') ||
		(num[0] == '2' && num[1] == '1' && num[2] > '4')
		|| (num[0] == '2' && num[1] == '1' && num[2] == '4' && num[3] > '7')
		|| (num[0] == '2' && num[1] == '1' && num[2] == '4'
			&& num[3] == '7' && num[4] > '4')
		|| (num[0] == '2' && num[1] == '1' && num[2] == '4'
			&& num[3] == '7' && num[4] == '4' && num[5] > '8')
		|| (num[0] == '2' && num[1] == '1' && num[2] == '4'
			&& num[3] == '7' && num[4] == '4' && num[5] == '8'
			&& num[6] > '3')
		|| (num[0] == '2' && num[1] == '1' && num[2] == '4'
			&& num[3] == '7' && num[4] == '4' && num[5] == '8'
			&& num[6] == '3' && num[7] > '6')
		|| (num[0] == '2' && num[1] == '1' && num[2] == '4'
			&& num[3] == '7' && num[4] == '4' && num[5] == '8'
			&& num[6] == '3' && num[7] == '6' && num[8] > '4')
		|| (num[0] == '2' && num[1] == '1' && num[2] == '4'
			&& num[3] == '7' && num[4] == '4' && num[5] == '8'
			&& num[6] == '3' && num[7] == '6' && num[8] == '4'
			&& num[9] > '7'))
		return (0);
	return (1);
}

int		biger_then_int(char *num)
{
	size_t len;

	len = ft_strlen(num);
	if (len == 11 && num[0] != '-')
		return (0);
	if (len == 11)
		return (w_min(num));
	else if (len == 10)
		return (w_o_min(num));
	else if (len > 10)
		return (0);
	return (1);
}

int		check_args_in(int a, char ***arr, t_stack **stack_a)
{
	int		i;
	int		j;

	i = a;
	while (--i >= 0)
	{
		j = 0;
		if ((*arr)[i][0] == '-' || (*arr)[i][0] == '+')
			j++;
		while ((*arr)[i][j])
		{
			if (!ft_isdigit((*arr)[i][j]))
				return (not_num_error(arr, stack_a, i));
			j++;
		}
		if (biger_then_int((*arr)[i]) == 0)
			return (bigger_then_int_error(arr, stack_a, i));
		add_new_elem(stack_a, ft_atoi((*arr)[i]));
		free((*arr)[i]);
	}
	return (0);
}

int		check_args_p(int argc, char **argv, t_stack **stack_a)
{
	int		i;
	char	**arr;
	int		a;

	i = argc - 1;
	while (i > 0)
	{
		a = 0;
		arr = ft_strsplit(argv[i], ' ');
		while (arr[a])
			a++;
		if (check_args_in(a, &arr, stack_a) == -1)
			return (-1);
		free(arr);
		i--;
	}
	if (dup_check(stack_a) == -1)
		return (-1);
	return (0);
}
