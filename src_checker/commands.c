/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atuomine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/23 15:46:55 by atuomine          #+#    #+#             */
/*   Updated: 2020/01/23 16:13:40 by atuomine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static int	execute_command(t_stack *stack_a, t_stack *stack_b, \
		int size, char *line)
{
	if (ft_strcmp(line, "sa") == 0)
		check_exec_s(stack_a, stack_b, SA, size);
	else if (ft_strcmp(line, "sb") == 0)
		check_exec_s(stack_a, stack_b, SB, size);
	else if (ft_strcmp(line, "ss") == 0)
		check_exec_s(stack_a, stack_b, SS, size);
	else if (ft_strcmp(line, "pa") == 0)
		check_exec_p(stack_a, stack_b, PA, size);
	else if (ft_strcmp(line, "pb") == 0)
		check_exec_p(stack_a, stack_b, PB, size);
	else if (ft_strcmp(line, "ra") == 0)
		check_exec_r(stack_a, stack_b, RA, size);
	else if (ft_strcmp(line, "rb") == 0)
		check_exec_r(stack_a, stack_b, RB, size);
	else if (ft_strcmp(line, "rr") == 0)
		check_exec_r(stack_a, stack_b, RR, size);
	else if (ft_strcmp(line, "rra") == 0)
		check_exec_r(stack_a, stack_b, RRA, size);
	else if (ft_strcmp(line, "rrb") == 0)
		check_exec_r(stack_a, stack_b, RRB, size);
	else if (ft_strcmp(line, "rrr") == 0)
		check_exec_r(stack_a, stack_b, RRR, size);
	else
		return (-1);
	return (1);
}

static int	execute(char *command_string, t_stack *stack_a, \
		t_stack *stack_b, int size)
{
	int		i;
	char	*command;
	int		len;
	int		start;
	int		ret;

	ret = 0;
	i = 0;
	while (command_string[i] != '\0')
	{
		len = 0;
		start = i;
		while (command_string[i] != '\n' && command_string[i] != '\0')
		{
			len++;
			i++;
		}
		i = (command_string[i] == '\n' ? i + 1 : i);
		command = ft_strsub(command_string, start, len);
		if (execute_command(stack_a, stack_b, size, command) == -1)
			ret = -1;
		free(command);
	}
	free(command_string);
	return (ret);
}

static char	*append_command(char *commands, char *line, int first)
{
	char *tmp;

	if (first == 1)
		commands = ft_strdup(line);
	else
	{
		tmp = ft_strjoin(commands, "\n");
		free(commands);
		commands = ft_strjoin(tmp, line);
		free(tmp);
	}
	return (commands);
}

int			read_commands(t_stack *stack_a, t_stack *stack_b, int size)
{
	char	*line;
	int		first;
	int		result;
	char	*commands;

	result = 1;
	first = 1;
	commands = NULL;
	while (result != 0)
	{
		result = get_next_line(0, &line);
		if (result != 0)
			commands = append_command(commands, line, first);
		free(line);
		if (first == 1)
			first = 0;
	}
	if (commands != NULL)
		if (execute(commands, stack_a, stack_b, size) < 0)
			return (ft_put_error(5));
	if (checkif_sorted(stack_a, size) == 1 && stack_b[0].status == PLACEHOLDER)
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
	return (0);
}
