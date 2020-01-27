/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   median.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atuomine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/24 12:08:21 by atuomine          #+#    #+#             */
/*   Updated: 2020/01/24 12:08:25 by atuomine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	determine_median(t_stack *stack, int size)
{
	int min;
	int stack_size;
	int median;

	stack_size = 0;
	min = size;
	while (stack[stack_size].status == NUMBER)
	{
		if (stack[stack_size].order < min)
			min = stack[stack_size].order;
		stack_size++;
	}
	median = ((stack_size - 1) / 2) + min;
	return (median);
}

/*
** Finds the median value of a partially sorted stack.
** Assumes that the top part of the stack has unsorted
** values, and bottom part of the stack sorted, smallest
** values on the list.
*/

int	find_median_partial(t_stack *stack_a)
{
	int min;
	int max;
	int steps;
	int median;
	int i;

	min = 2147483647;
	max = 0;
	i = 0;
	while (stack_a[i].order > 0)
	{
		if (stack_a[i].order < min)
			min = stack_a[i].order;
		if (stack_a[i].order > max)
			max = stack_a[i].order;
		i++;
	}
	steps = max - min;
	median = min + (steps / 2);
	return (median);
}

/*
** Finds the closest value that is over median and returns
** a command needed to reach it.
*/

int	find_over_median(t_stack *stack, char stack_type, int median, int size)
{
	int i;
	int i_rev;
	int steps_top;
	int steps_bottom;

	size = adjust_size(stack, size);
	i = 0;
	steps_top = 0;
	steps_bottom = 0;
	while (stack[i].order <= median)
	{
		i++;
		steps_top++;
	}
	i_rev = size - 1;
	while (stack[i_rev].order <= median)
	{
		i_rev--;
		steps_bottom++;
	}
	if (steps_top < steps_bottom)
		return (stack_type == 'a' ? RA : RB);
	else
		return (stack_type == 'a' ? RRA : RRB);
}

/*
** Finds the closest value that is under median and returns
** a command needed to reach it.
*/

int	find_under_median(t_stack *stack, char stack_type, int median, int size)
{
	int i;
	int i_rev;
	int steps_top;
	int steps_bottom;

	size = adjust_size(stack, size);
	i = 0;
	steps_top = 0;
	steps_bottom = 0;
	while (stack[i].order >= median)
	{
		i++;
		steps_top++;
	}
	i_rev = size - 1;
	while (stack[i_rev].order >= median)
	{
		i_rev--;
		steps_bottom++;
	}
	if (steps_top < steps_bottom)
		return (stack_type == 'a' ? RA : RB);
	else
		return (stack_type == 'a' ? RRA : RRB);
}
