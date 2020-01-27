/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushback.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atuomine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/20 15:12:47 by atuomine          #+#    #+#             */
/*   Updated: 2020/01/24 11:48:23 by atuomine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	find_limits(t_stack *stack_b, t_limits *limits, int size, \
		int median)
{
	int i;

	i = 0;
	limits->min = size;
	limits->min_i = -1;
	limits->max = -1;
	limits->max_i = -1;
	while (i < size && stack_b[i].status == NUMBER)
	{
		if (stack_b[i].order < limits->min)
		{
			limits->min_i = i;
			limits->min = stack_b[i].order;
		}
		if (stack_b[i].order > limits->max)
		{
			limits->max_i = i;
			limits->max = stack_b[i].order;
		}
		i++;
	}
	if (limits->max < median)
		limits->max_i = limits->min_i;
	if (limits->min >= median)
		limits->min_i = limits->max_i;
}

static int	compare_steps(t_stack *stack_b, t_limits limits, int size_b)
{
	int steps_max;
	int steps_min;

	steps_max = 0;
	steps_min = 0;
	if (limits.min_i > (size_b - 1) / 2)
		steps_min = size_b - limits.min_i;
	else
		steps_min = limits.min_i;
	if (limits.max_i > (size_b - 1) / 2)
		steps_max = size_b - limits.max_i;
	else
		steps_max = limits.max_i;
	if (steps_max > steps_min)
		return (stack_b[limits.min_i].order);
	else
		return (stack_b[limits.max_i].order);
}

static void	find_next(t_stack *stack_a, t_stack *stack_b, int next, int size)
{
	int i;
	int command;
	int	b_size;

	i = 0;
	b_size = 0;
	while (stack_b[b_size].status == NUMBER && b_size < size)
		b_size++;
	while (stack_b[i].order != next)
		i++;
	if (i > (b_size - 1) / 2)
		command = RRB;
	else
		command = RB;
	while (stack_b[0].order != next)
		exec_r(stack_a, stack_b, command, size);
}

/*
** Pushes values back from stack b to stack a.
** First we find the indexes of min and max values and compare which one
** is closer to get to.
** Then we check if both values are on one side of the median value.
**  - If both values are over median, we will ignore min value and always
**  push max value first.
**  - If both values are under median, we will ignore max value and always
**  push min value first.
**  This is necessary to preserve order.
**  Then we'll determine if we need to use RB or RRB to reach the value to
**  be pushed next, and rotate the value to first stack slot.
**  Then the number will be pushed either to the top of stack a or to the
**  bottom of stack a depending on on which side of the median it is.
*/

void		push_back(t_stack *stack_a, t_stack *stack_b, int size, int median)
{
	t_limits	limits;
	int			size_b;
	int			next;

	while (stack_b[0].status == NUMBER)
	{
		size_b = 0;
		while (stack_b[size_b].status == NUMBER && size_b < size)
			size_b++;
		find_limits(stack_b, &limits, size, median);
		next = compare_steps(stack_b, limits, size_b);
		find_next(stack_a, stack_b, next, size);
		if (stack_b[0].order < median)
		{
			exec_p(stack_a, stack_b, PA, size);
			exec_r(stack_a, stack_b, RA, size);
		}
		else
			exec_p(stack_a, stack_b, PA, size);
	}
}
