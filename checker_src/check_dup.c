/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_dup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichubare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/20 16:36:36 by ichubare          #+#    #+#             */
/*   Updated: 2017/03/21 16:29:52 by ichubare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int		arr_check(int **arr, t_stack *stack, int *len)
{
	int i;

	*len = 0;
	len_stack(stack, (size_t*)len);
	*arr = (int*)malloc(sizeof(int) * *len);
	i = 0;
	while (stack)
	{
		(*arr)[i] = stack->data;
		i++;
		stack = stack->next;
	}
	return (-1);
}

int		dup_error(int num, int position, int **arr, t_stack **stack)
{
	char	*nu;
	char	*pos;

	nu = ft_itoa_base(num, 10);
	pos = ft_itoa_base(position + 1, 10);
	write(1, "Duplicate number:[", 18);
	write(1, nu, ft_strlen(nu));
	free(nu);
	write(1, "], on:[", 7);
	write(1, pos, ft_strlen(pos));
	free(pos);
	write(1, "] position.\n", 12);
	free(*arr);
	while (*stack)
		del_elem(stack);
	return (-1);
}

int		before_num(int i, int **arr, t_stack **stack)
{
	int		j;

	j = i - 1;
	while (j >= 0)
	{
		if ((*arr)[i] == (*arr)[j--])
			return (dup_error((*arr)[i], i, arr, stack));
	}
	return (0);
}

int		after_num(int i, int **arr, int len, t_stack **stack)
{
	int		j;

	j = i + 1;
	while (j < len)
	{
		if ((*arr)[i] == (*arr)[j++])
			return (dup_error((*arr)[i], i, arr, stack));
	}
	return (0);
}

int		dup_check(t_stack **stack)
{
	int	*arr;
	int	len;
	int	i;

	i = arr_check(&arr, *stack, &len);
	while (i++ < len && i != len)
	{
		if (i != 0)
		{
			if (before_num(i, &arr, stack) == -1)
				return (-1);
		}
		if (after_num(i, &arr, len, stack) == -1)
			return (-1);
	}
	free(arr);
	return (0);
}
