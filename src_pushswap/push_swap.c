/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atuomine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/24 12:06:23 by atuomine          #+#    #+#             */
/*   Updated: 2020/01/24 13:26:07 by atuomine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_stack	new_elem(int nbr, int status)
{
	t_stack new;

	new.nbr = nbr;
	new.status = status;
	new.order = -1;
	return (new);
}

static int		*initialize_stacks(t_stack *stack_a, t_stack *stack_b, \
		int size, char **argv)
{
	int i;
	int *numbers;
	int nbr;

	if ((numbers = (int *)malloc(sizeof(int) * size)) == NULL)
	{
		write(2, "Error\n", 6);
		exit(1);
	}
	i = 0;
	while (i < size)
	{
		if (check_ifnumber(argv[i]) == -1)
			ft_error_exit(2);
		if (check_length(argv[i]) == -1)
			ft_error_exit(3);
		nbr = ft_atoi(argv[i]);
		if (check_ifduplicates(stack_a, i, nbr) == -1)
			ft_error_exit(4);
		stack_a[i] = new_elem(nbr, NUMBER);
		numbers[i] = stack_a[i].nbr;
		stack_b[i] = new_elem(0, PLACEHOLDER);
		i++;
	}
	return (numbers);
}

static int		solver(t_stack *stack_a, t_stack *stack_b, int size, \
		int median)
{
	if (size <= 3)
		return (solver_3(stack_a, stack_b, size));
	else if (size <= 6)
		return (solver_6(stack_a, stack_b, size));
	else
		return (solver_big(stack_a, stack_b, size, median));
}

/*
**	Initializes the stacks. Stack a is filled with the given numbers,
**	stack b is filled with placeholders.
**	Values in stack a are also given an order number based
**	on the sorted list to simplify certain things with the sorting
**	algorithm.
**	If given list is not sorted already, solver is run.
*/

static int		initialize(char **arguments, int size)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	int		i;
	int		*numbers;
	int		median;

	stack_a = (t_stack *)malloc(sizeof(t_stack) * (size));
	stack_b = (t_stack *)malloc(sizeof(t_stack) * (size));
	if (stack_a == NULL || stack_b == NULL)
	{
		write(2, "Error\n", 6);
		exit(1);
	}
	i = 0;
	numbers = initialize_stacks(stack_a, stack_b, size, arguments);
	median = assign_order(numbers, stack_a, size);
	if (check_if_sorted(stack_a, size) != 1)
		solver(stack_a, stack_b, size, median);
	free(stack_a);
	free(stack_b);
	return (0);
}

/*
**	Program needs to work with either multiple arguments of one number
**	or 1 argument that is a string of numbers.
**	If former, size is determined from argc and a list of numbers starting
**	from argv[1].
**	If latter, the list of numbers is taken from the first argument and size
**	is based on the list gotten this way.
**	Program returns a value depending on errors.
**		0 - program ran successfully
**		1 - malloc fail
**		2 - some of the arguments weren't numbers
**		3 - one of the values given was over or under integer limits
**		4 - list contained duplicate numbers
*/

int				main(int argc, char **argv)
{
	char	**arguments;
	int		size;
	int		ret;

	if (argc == 1)
		return (0);
	if (argc == 2)
	{
		if (argv[1][0] == '\0')
			ft_error_exit(2);
		arguments = ft_strsplit(argv[1], ' ');
		if (arguments == NULL)
		{
			write(2, "Error\n", 6);
			exit(1);
		}
		size = 0;
		while (arguments[size] != NULL)
			size++;
		ret = initialize(arguments, size);
		ft_2ddel(arguments);
		return (ret);
	}
	else
		return (initialize(&argv[1], argc - 1));
}
