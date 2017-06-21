/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_mid_qs.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichubare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/19 17:08:34 by ichubare          #+#    #+#             */
/*   Updated: 2017/03/19 19:21:00 by ichubare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		loop_qs(int *arr, int pivot, int *i, int *j)
{
	int		high;

	high = *j;
	while ((arr[*i] <= arr[pivot]) && (*i < high))
		(*i)++;
	while (arr[*j] > arr[pivot])
		(*j)--;
	if (*i < *j)
		return (1);
	return (0);
}

void	qsort_arr(int *arr, int low, int high)
{
	int		pivot;
	int		j;
	int		temp;
	int		i;

	if (low < high)
	{
		pivot = low;
		i = low;
		j = high;
		while (i < j)
		{
			if (loop_qs(arr, pivot, &i, &j))
			{
				temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}
		}
		temp = arr[pivot];
		arr[pivot] = arr[j];
		arr[j] = temp;
		qsort_arr(arr, low, j - 1);
		qsort_arr(arr, j + 1, high);
	}
}

void	find_mid_b(int len, int *mid_num, t_stack *stack_b)
{
	int		i;
	t_stack	*temp;
	int		*arr;

	arr = (int*)malloc(sizeof(int) * len);
	i = 0;
	temp = stack_b;
	while (i < len)
	{
		arr[i] = temp->data;
		temp = temp->next;
		i++;
	}
	qsort_arr(arr, 0, i - 1);
	*mid_num = arr[(i - 1) / 2];
	free(arr);
}
