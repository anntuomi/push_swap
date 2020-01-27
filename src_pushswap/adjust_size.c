/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   adjust_size.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atuomine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/20 15:20:01 by atuomine          #+#    #+#             */
/*   Updated: 2020/01/24 11:23:56 by atuomine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** Checks if the stack is full, and if not,
** adjust the size to be current stack size.
*/

int		adjust_size(t_stack *stack, int size)
{
	if (stack[size - 1].status != NUMBER)
	{
		size = 0;
		while (stack[size].status == NUMBER)
			size++;
	}
	return (size);
}
