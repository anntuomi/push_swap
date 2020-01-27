/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_r.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atuomine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/24 12:08:08 by atuomine          #+#    #+#             */
/*   Updated: 2020/01/24 12:08:11 by atuomine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rotate_up(t_stack *stack, int size)
{
	int		i;
	t_stack	tmp;

	tmp.nbr = stack[0].nbr;
	tmp.status = stack[0].status;
	tmp.order = stack[0].order;
	i = 0;
	while (i < size - 1 && stack[i + 1].status == NUMBER)
	{
		stack[i].nbr = stack[i + 1].nbr;
		stack[i].status = stack[i + 1].status;
		stack[i].order = stack[i + 1].order;
		i++;
	}
	stack[i].nbr = tmp.nbr;
	stack[i].status = tmp.status;
	stack[i].order = tmp.order;
}

static void	rotate_down(t_stack *stack, int size)
{
	int		i;
	t_stack	tmp;

	i = 0;
	if (stack[0].status == PLACEHOLDER)
		return ;
	while (i < size && stack[i + 1].status == NUMBER)
		i++;
	tmp.nbr = stack[i].nbr;
	tmp.status = stack[i].status;
	tmp.order = stack[i].order;
	while (i > 0)
	{
		stack[i].nbr = stack[i - 1].nbr;
		stack[i].status = stack[i - 1].status;
		stack[i].order = stack[i - 1].order;
		i--;
	}
	stack[0].nbr = tmp.nbr;
	stack[0].status = tmp.status;
	stack[0].order = tmp.order;
}

void		exec_r(t_stack *stack_a, t_stack *stack_b, int command, \
		int size)
{
	if (command == RA || command == RR)
		rotate_up(stack_a, size);
	if (command == RB || command == RR)
		rotate_up(stack_b, size);
	if (command == RRA || command == RRR)
		rotate_down(stack_a, size);
	if (command == RRB || command == RRR)
		rotate_down(stack_b, size);
	print_command(command);
}
