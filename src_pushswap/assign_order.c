/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assign_order.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atuomine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/23 17:00:14 by atuomine          #+#    #+#             */
/*   Updated: 2020/01/24 13:37:09 by atuomine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** Values given are first sorted, then each value in stack
** a is assigned an order number based on the list. This is
** done to simplify certain things with sorting algorithm.
*/

static int	*sort_numbers(int *numbers, int size)
{
	int i;
	int j;
	int temp;

	i = 0;
	while (i < size)
	{
		j = i + 1;
		while (j < size)
		{
			if (numbers[j] < numbers[i])
			{
				temp = numbers[j];
				numbers[j] = numbers[i];
				numbers[i] = temp;
			}
			j++;
		}
		i++;
	}
	return (numbers);
}

int			assign_order(int *numbers, t_stack *stack_a, int size)
{
	int i;
	int j;
	int median;

	numbers = sort_numbers(numbers, size);
	i = 0;
	while (i < size)
	{
		j = 0;
		while (j < size)
		{
			if (stack_a[j].nbr == numbers[i])
				stack_a[j].order = i;
			j++;
		}
		i++;
	}
	median = size / 2;
	free(numbers);
	return (median);
}
