/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atuomine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/13 08:14:56 by atuomine          #+#    #+#             */
/*   Updated: 2020/01/24 12:49:38 by atuomine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "../libft/includes/ft_printf.h"
# include "../libft/includes/libft.h"

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

typedef struct	s_limits
{
	int			min;
	int			min_i;
	int			max;
	int			max_i;

}				t_limits;

void			exec_s(t_stack *stack_a, t_stack *stack_b, int command, \
				int size);
void			exec_p(t_stack *stack_a, t_stack *stack_b, int command, \
				int size);
void			exec_r(t_stack *stack_a, t_stack *stack_b, int command, \
				int size);
void			push_back(t_stack *stack_a, t_stack *stack_b, int size, \
				int median);
void			ft_error_exit(int errorcode);
void			print_command(int command);
void			divide_stack(t_stack *stack_a, t_stack *stack_b, int size, \
				int median);

int				assign_order(int *numbers, t_stack *stack_a, int size);
int				check_if_sorted(t_stack *stack_a, int size);
int				check_ifduplicates(t_stack *stack_a, int len, int nb);
int				check_ifnumber(char *nbr);
int				check_length(char *nbr);
int				solver_3(t_stack *stack_a, t_stack *stack_b, int size);
int				solver_6(t_stack *stack_a, t_stack *stack_b, int size);
int				solver_big(t_stack *stack_a, t_stack *stack_b, int size, \
				int median);
int				determine_median(t_stack *stack, int size);
int				find_median_partial(t_stack *stack_a);
int				find_over_median(t_stack *stack, char stack_type, int median, \
				int size);
int				find_under_median(t_stack *stack, char stack_type, \
				int median, int size);
int				adjust_size(t_stack *stack, int size);

#endif
