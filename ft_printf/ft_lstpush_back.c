/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstpush_back.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichubare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/02 14:31:16 by ichubare          #+#    #+#             */
/*   Updated: 2016/12/02 14:33:20 by ichubare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstpush_back(t_list **start, t_list *new_node)
{
	t_list	*node_start;

	if (start)
	{
		if (*start)
		{
			node_start = *start;
			while (node_start->next)
				node_start = node_start->next;
			node_start->next = new_node;
		}
		else
			*start = new_node;
	}
}
