/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm_small.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atuomine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/24 12:07:16 by atuomine          #+#    #+#             */
/*   Updated: 2020/01/24 12:07:19 by atuomine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** 3 values can be in 5 wrong orders. This function
** simply checks which order they are in, and executes
** the right commands based on that.
*/

int			solver_3(t_stack *stack, t_stack *stack_b, int size)
{
	if (check_if_sorted(stack, size) == 1)
		return (0);
	if (size >= 3 && stack[1].nbr < stack[2].nbr && \
			stack[1].nbr < stack[0].nbr && stack[0].nbr > stack[2].nbr)
		exec_r(stack, stack_b, RA, size);
	else if ((size >= 3 && stack[0].nbr < stack[1].nbr && \
		stack[0].nbr < stack[2].nbr && stack[1].nbr > stack[2].nbr) || \
		stack[0].nbr > stack[1].nbr)
		exec_s(stack, stack_b, SA, size);
	else if (size >= 3 && stack[1].nbr > stack[2].nbr && \
			stack[1].nbr > stack[0].nbr && stack[0].nbr > stack[2].nbr)
		exec_r(stack, stack_b, RRA, size);
	if (check_if_sorted(stack, size) != 1)
	{
		if (stack[1].nbr > stack[0].nbr)
			exec_r(stack, stack_b, RRA, size);
		else
			exec_r(stack, stack_b, RA, size);
	}
	return (0);
}

static int	check_if_sorted_rev(t_stack *stack_a, int size)
{
	int i;

	i = 1;
	while (i < size && stack_a[i].status == NUMBER)
	{
		if (stack_a[i].nbr > stack_a[i - 1].nbr || \
				stack_a[i].status == PLACEHOLDER)
			return (-1);
		i++;
	}
	return (1);
}

static int	solver_3rev(t_stack *stack_a, t_stack *stack, int size)
{
	if (check_if_sorted_rev(stack, size) == 1)
		return (0);
	if (size >= 3 && stack[1].nbr > stack[2].nbr && \
			stack[1].nbr > stack[0].nbr && stack[0].nbr < stack[2].nbr)
		exec_r(stack_a, stack, RB, size);
	else if ((size >= 3 && stack[0].nbr > stack[1].nbr && \
		stack[0].nbr > stack[2].nbr && stack[1].nbr < stack[2].nbr) || \
		stack[0].nbr < stack[1].nbr)
		exec_s(stack_a, stack, SB, size);
	else if (size >= 3 && stack[1].nbr < stack[2].nbr && \
			stack[1].nbr < stack[0].nbr && stack[0].nbr < stack[2].nbr)
		exec_r(stack_a, stack, RRB, size);
	if (check_if_sorted_rev(stack, size) != 1)
	{
		if (stack[1].nbr < stack[0].nbr)
			exec_r(stack_a, stack, RRB, size);
		else
			exec_r(stack_a, stack, RB, size);
	}
	return (0);
}

static void	find_current(t_stack *stack_a, t_stack *stack_b, int size, \
		int current)
{
	int i;
	int command;
	int s_size;

	s_size = 0;
	while (stack_a[s_size].status == NUMBER)
		s_size++;
	i = 0;
	while (stack_a[i].order != current)
		i++;
	if (i > (s_size - 1) / 2)
		command = RRA;
	else
		command = RA;
	while (stack_a[0].order != current)
		exec_r(stack_a, stack_b, command, size);
}

/*
** Used in case there are 4 to 6 values. Smallest (list size - 3)
** numbers are moved to stack b. Stack a is sorted like with 3 values.
** Then values in stack b are sorted in reverse order, then pushed
** back to stack a.
** For example, in case there are 5 numbers, 2 are moved to stack b.
*/

int			solver_6(t_stack *stack_a, t_stack *stack_b, int size)
{
	int median;
	int current;

	if (size == 6)
		median = 2;
	if (size == 5 || size == 4)
		median = 1;
	current = 0;
	while (current <= median)
	{
		find_current(stack_a, stack_b, size, current);
		exec_p(stack_a, stack_b, PB, size);
		current++;
	}
	solver_3(stack_a, stack_b, size);
	solver_3rev(stack_a, stack_b, size - 3);
	while (stack_b[0].status == NUMBER)
		exec_p(stack_a, stack_b, PA, size);
	return (0);
}
