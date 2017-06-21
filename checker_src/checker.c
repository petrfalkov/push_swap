/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichubare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/01 18:16:43 by ichubare          #+#    #+#             */
/*   Updated: 2017/03/25 14:01:28 by ichubare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int		main(int argc, char **argv)
{
	t_check	*check;
	int		act;

	init_check(&check);
	if (argc == 1)
		write(1, "0 params was transmitted\n", 25);
	else if (check_args(argc, argv, &check->stack_a, check) == -1 ||
			(act = read_acts(check)) == -1)
		return (0);
	else if (act == 1)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	return (0);
}
