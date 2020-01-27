/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_s.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atuomine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/24 12:07:54 by atuomine          #+#    #+#             */
/*   Updated: 2020/01/24 12:07:58 by atuomine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	swap_places(t_stack *stack)
{
	t_stack tmp;

	if (stack[0].status == NUMBER && stack[1].status == NUMBER)
	{
		tmp.nbr = stack[0].nbr;
		tmp.status = stack[0].status;
		tmp.order = stack[0].order;
		stack[0].nbr = stack[1].nbr;
		stack[0].status = stack[1].status;
		stack[0].order = stack[1].order;
		stack[1].nbr = tmp.nbr;
		stack[1].status = tmp.status;
		stack[1].order = tmp.order;
	}
}

void		exec_s(t_stack *stack_a, t_stack *stack_b, int command, \
		int size)
{
	if (size < 2)
		return ;
	if (command == SA || command == SS)
		swap_places(stack_a);
	if (command == SB || command == SS)
		swap_places(stack_b);
	print_command(command);
}
