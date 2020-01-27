/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   divide_stack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atuomine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/23 17:30:49 by atuomine          #+#    #+#             */
/*   Updated: 2020/01/23 17:31:25 by atuomine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	divide_stack(t_stack *stack_a, t_stack *stack_b, int size, int median)
{
	int counter;
	int command;

	counter = 0;
	while (counter < median)
	{
		if (stack_a[0].order < median)
			exec_p(stack_a, stack_b, PB, size);
		else
		{
			command = find_under_median(stack_a, 'a', median, size);
			while (stack_a[0].order >= median)
				exec_r(stack_a, stack_b, command, size);
			exec_p(stack_a, stack_b, PB, size);
		}
		counter++;
	}
}
