/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_valid.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atuomine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/23 16:56:10 by atuomine          #+#    #+#             */
/*   Updated: 2020/01/24 13:26:26 by atuomine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_error_exit(int errorcode)
{
	write(2, "Error\n", 6);
	exit(errorcode);
}

int		check_length(char *nbr)
{
	long long n;

	if (ft_strlen(nbr) > 11)
		return (-1);
	n = ft_atoll(nbr);
	if (n > 2147483647 || n < -2147483648)
		return (-1);
	return (1);
}

int		check_ifnumber(char *nbr)
{
	int i;

	i = 0;
	while (nbr[i])
	{
		if (i == 0 && nbr[i] == '-')
			i++;
		if (ft_isdigit(nbr[i]) == 0)
			return (-1);
		i++;
	}
	return (1);
}

int		check_ifduplicates(t_stack *stack_a, int len, int nb)
{
	int i;

	i = 0;
	while (i < len)
	{
		if (stack_a[i].nbr == nb)
			return (-1);
		i++;
	}
	return (1);
}

int		check_if_sorted(t_stack *stack_a, int size)
{
	int i;

	i = 1;
	while (i < size && stack_a[i].status == NUMBER)
	{
		if (stack_a[i].nbr < stack_a[i - 1].nbr || \
				stack_a[i].status == PLACEHOLDER)
			return (-1);
		i++;
	}
	return (1);
}
