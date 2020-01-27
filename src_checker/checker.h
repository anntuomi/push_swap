/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atuomine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/24 12:11:25 by atuomine          #+#    #+#             */
/*   Updated: 2020/01/24 12:11:27 by atuomine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H
# include "../libft/includes/ft_printf.h"
# include "../libft/includes/libft.h"
# include "../libft/includes/get_next_line.h"

# define SA 11
# define SB 12
# define SS 10
# define PA 21
# define PB 22
# define RA 31
# define RB 32
# define RR 30
# define RRA 41
# define RRB 42
# define RRR 40
# define NUMBER 1
# define PLACEHOLDER 0
# define BUFF_SIZE 8

typedef struct	s_stack
{
	int			nbr;
	int			status;
	int			order;

}				t_stack;

int				checkif_sorted(t_stack *stack_a, int size);
int				ft_put_error(int errorcode);
int				read_commands(t_stack *stack_a, t_stack *stack_b, int size);
int				check_length(char *nbr);
int				check_ifnumber(char *nbr);
int				check_ifduplicates(t_stack *stack_a, int len, int nb);

void			check_exec_s(t_stack *stack_a, t_stack *stack_b, \
				int command, int size);
void			check_exec_p(t_stack *stack_a, t_stack *stack_b, \
				int command, int size);
void			check_exec_r(t_stack *stack_a, t_stack *stack_b, \
				int command, int size);
#endif
