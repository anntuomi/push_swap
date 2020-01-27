/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atuomine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/21 11:32:50 by atuomine          #+#    #+#             */
/*   Updated: 2020/01/24 12:55:55 by atuomine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	checkif_sorted(t_stack *stack_a, int size)
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

int	check_length(char *nbr)
{
	long long n;

	if (ft_strlen(nbr) > 11)
		return (-1);
	n = ft_atoll(nbr);
	if (n > 2147483647 || n < -2147483648)
		return (-1);
	return (1);
}

int	check_ifnumber(char *nbr)
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

int	check_ifduplicates(t_stack *stack_a, int len, int nb)
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
