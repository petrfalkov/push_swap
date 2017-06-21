/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_act.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichubare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/20 17:18:15 by ichubare          #+#    #+#             */
/*   Updated: 2017/03/21 17:43:55 by ichubare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int		if_visual(t_check *check, int *i, char **argv, int argc)
{
	*i = argc - 1;
	if (ft_strcmp(argv[argc - 1], "-v") == 0)
	{
		check->v_flag = 1;
		--(*i);
	}
	else if (ft_strcmp(argv[argc - 1], "-c") == 0)
	{
		check->c_flag = 1;
		--(*i);
	}
	return (0);
}

int		not_num_error(char ***arr, t_stack **stack, int pos)
{
	int		i;

	i = 0;
	write(1, "Not a number [", 14);
	write(1, (*arr)[pos], ft_strlen((*arr)[pos]));
	write(1, "].\n", 3);
	while ((*arr)[i])
	{
		free((*arr)[i]);
		i++;
	}
	while (*stack)
		del_elem(stack);
	return (-1);
}

int		bigger_then_int_error(char ***arr, t_stack **stack, int pos)
{
	int i;

	i = 0;
	write(1, "Bigger then INT [", 17);
	write(1, (*arr)[pos], ft_strlen((*arr)[pos]));
	write(1, "].\n", 3);
	while ((*arr)[i])
	{
		free((*arr)[i]);
		i++;
	}
	while (*stack)
		del_elem(stack);
	return (-1);
}

int		check_args_in(int a, char ***arr, t_stack **stack_a)
{
	int i;
	int j;

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

int		check_args(int argc, char **argv, t_stack **stack_a, t_check *check)
{
	int		i;
	char	**arr;
	int		a;
	int		last;

	if (argc == 2 && (ft_strcmp(argv[1], "-v") == 0
				|| ft_strcmp(argv[1], "-c") == 0))
	{
		write(1, "0 params was transmitted\n", 25);
		return (-1);
	}
	last = if_visual(check, &i, argv, argc);
	while (i > last)
	{
		a = 0;
		arr = ft_strsplit(argv[i], ' ');
		while (arr[a])
			a++;
		if (check_args_in(a, &arr, stack_a))
			return (-1);
		i--;
		free(arr);
	}
	return (dup_check(stack_a));
}
