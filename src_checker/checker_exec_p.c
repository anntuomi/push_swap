/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_exec_p.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atuomine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/24 12:09:02 by atuomine          #+#    #+#             */
/*   Updated: 2020/01/24 12:09:05 by atuomine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static void	add_top(t_stack *stack, t_stack elem, int size)
{
	int i;

	i = size;
	if (elem.status == NUMBER)
	{
		if (stack[0].status == NUMBER && size)
		{
			while (i > 0)
			{
				if (stack[i - 1].status == NUMBER)
				{
					stack[i].nbr = stack[i - 1].nbr;
					stack[i].status = NUMBER;
					stack[i].order = stack[i - 1].order;
				}
				i--;
			}
		}
		stack[0].nbr = elem.nbr;
		stack[0].status = NUMBER;
		stack[0].order = elem.order;
	}
}

static void	remove_top(t_stack *stack, int size)
{
	int i;

	i = 0;
	while (stack[i].status == NUMBER && i < size - 1)
	{
		stack[i].nbr = stack[i + 1].nbr;
		stack[i].status = stack[i + 1].status;
		stack[i].order = stack[i + 1].order;
		i++;
	}
	stack[i].nbr = 0;
	stack[i].status = PLACEHOLDER;
	stack[i].order = -1;
}

void		check_exec_p(t_stack *stack_a, t_stack *stack_b, int command, \
		int size)
{
	if (command == PA)
	{
		add_top(stack_a, stack_b[0], size);
		remove_top(stack_b, size);
	}
	if (command == PB)
	{
		add_top(stack_b, stack_a[0], size);
		remove_top(stack_a, size);
	}
}
