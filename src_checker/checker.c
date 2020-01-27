/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atuomine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/21 10:54:04 by atuomine          #+#    #+#             */
/*   Updated: 2020/01/24 13:26:01 by atuomine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int				ft_put_error(int errorcode)
{
	write(2, "Error\n", 6);
	return (errorcode);
}

static t_stack	new_elem(int nbr, int status)
{
	t_stack new;

	new.nbr = nbr;
	new.status = status;
	new.order = -1;
	return (new);
}

static int		initialize_stacks(t_stack *stack_a, t_stack *stack_b, \
		int size, char **argv)
{
	int i;
	int ret;
	int nbr;

	i = 0;
	while (i < size)
	{
		ret = check_ifnumber(argv[i]);
		if (ret == -1)
			return (2);
		ret = check_length(argv[i]);
		if (ret == -1)
			return (3);
		nbr = ft_atoi(argv[i]);
		ret = check_ifduplicates(stack_a, i, nbr);
		if (ret == -1)
			return (4);
		stack_a[i] = new_elem(nbr, NUMBER);
		stack_b[i] = new_elem(0, PLACEHOLDER);
		i++;
	}
	return (0);
}

static int		initialize(char **arguments, int size)
{
	t_stack *stack_a;
	t_stack *stack_b;
	int		ret;
	int		i;

	stack_a = (t_stack *)malloc(sizeof(t_stack) * (size));
	stack_b = (t_stack *)malloc(sizeof(t_stack) * (size));
	if (stack_a == NULL || stack_b == NULL)
		return (ft_put_error(1));
	ret = initialize_stacks(stack_a, stack_b, size, arguments);
	if (ret > 0)
	{
		free(stack_a);
		free(stack_b);
		return (ft_put_error(ret));
	}
	ret = read_commands(stack_a, stack_b, size);
	free(stack_a);
	free(stack_b);
	i = 0;
	return (ret);
}

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
			return (ft_put_error(2));
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
