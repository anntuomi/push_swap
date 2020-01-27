/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm_big.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atuomine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/20 13:29:46 by atuomine          #+#    #+#             */
/*   Updated: 2020/01/24 11:30:43 by atuomine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	push_smallest(t_stack *stack_a, t_stack *stack_b, int min, int size)
{
	exec_p(stack_a, stack_b, PA, size);
	exec_r(stack_a, stack_b, RA, size);
	return (min + 1);
}

static int	solve_lower_part1(t_stack *stack_a, t_stack *stack_b, int size, \
		int b_size)
{
	int counter;
	int command;
	int min;
	int median;

	median = determine_median(stack_b, size);
	counter = 0;
	min = 0;
	while (counter < (b_size - 1) / 2)
	{
		if (stack_b[0].order <= median)
		{
			command = find_over_median(stack_b, 'b', median, size);
			while (stack_b[0].order <= median)
			{
				if (stack_b[0].order == min)
					min = push_smallest(stack_a, stack_b, min, size);
				else
					exec_r(stack_a, stack_b, command, size);
			}
		}
		exec_p(stack_a, stack_b, PA, size);
		counter++;
	}
	return (median);
}

static void	solve_lower_part2(t_stack *stack_a, t_stack *stack_b, int size, \
		int median)
{
	while (stack_a[0].order < median)
		exec_p(stack_a, stack_b, PB, size);
	push_back(stack_a, stack_b, size, median);
	while (stack_a[0].order < median)
		exec_r(stack_a, stack_b, RA, size);
}

static void	solve_higher(t_stack *stack_a, t_stack *stack_b, int median, \
		int size)
{
	int i;

	i = 0;
	while (stack_a[0].order > 0)
	{
		if (stack_a[0].order > median)
			exec_r(stack_a, stack_b, RA, size);
		else
			exec_p(stack_a, stack_b, PB, size);
	}
	while (stack_a[i + 1].status == NUMBER)
		i++;
	while (stack_a[i].order > median)
	{
		if (stack_b[0].order != median)
			exec_r(stack_a, stack_b, RRR, size);
		else
			exec_r(stack_a, stack_b, RRA, size);
	}
	median = determine_median(stack_b, size);
	push_back(stack_a, stack_b, size, median);
}

/*
**	This algorithm is used in case the list has more than 6 numbers.
**	1. divide_stack - values under median are pushed to stack b.
**	2. solve_lower_part1 - Median of stack b is determined, and values
**	over that median are pushed back to stack a. Values under b median
**	are pushed in next in numerical order (check comment in pushback.c).
**	3. Stack a is rotated until the newly sorted numbers are all at the
**	bottom of the stack.
**	4. solve_lower_part2 - The remaining numbers under the original median
**	in stack a are pushed to stack b and sorted back in a with pushback like
**	before.
**	5. Median is redefined to be the median of the remaining unsorted values.
**	6. solve_higher - Pushes values under or equal to median to b, and other
**	values to the bottom of a. Then stacks are rotated until median value
**	(or current stack b max value) is at the stop of stack b and all values in
**	stack a that are over median are at the top of stack a. Then pushback is
**	used again to sort b based on b median.
**	7. Sorted numbers are rotated at the bottom of stack a again and the
**	remaining unsorted values are pushed to stack b.
**	8. The remaining unsorted list median is determined and push back is used
**	to sort them back in a.
**	9. Stack a is rotated until the first number is at the top of the list.
*/

int			solver_big(t_stack *stack_a, t_stack *stack_b, int size, int median)
{
	int b_size;
	int l_median;

	divide_stack(stack_a, stack_b, size, median);
	b_size = adjust_size(stack_b, size);
	l_median = solve_lower_part1(stack_a, stack_b, size, b_size);
	push_back(stack_a, stack_b, size, l_median / 2);
	while (stack_a[0].order <= l_median)
		exec_r(stack_a, stack_b, RA, size);
	solve_lower_part2(stack_a, stack_b, size, median);
	median = median + (median / 2);
	solve_higher(stack_a, stack_b, median, size);
	while (stack_a[0].order <= median)
		exec_r(stack_a, stack_b, RA, size);
	median = find_median_partial(stack_a);
	solve_higher(stack_a, stack_b, median, size);
	while (stack_a[0].order <= median)
		exec_r(stack_a, stack_b, RA, size);
	while (stack_a[0].order > 0)
		exec_p(stack_a, stack_b, PB, size);
	median = determine_median(stack_b, size);
	push_back(stack_a, stack_b, size, median);
	while (stack_a[0].order != 0)
		exec_r(stack_a, stack_b, RA, size);
	return (0);
}
