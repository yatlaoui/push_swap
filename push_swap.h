/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yasmine <yasmine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 16:43:26 by yaatlaou          #+#    #+#             */
/*   Updated: 2024/11/01 12:54:55 by yasmine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
# include <limits.h>
# include <stddef.h>
# include <stdlib.h>

typedef struct s_node
{
	int				data;
	int				index;
	struct s_node	*next;
}					t_node;

typedef struct s_stack
{
	unsigned int	size;
	t_node			*first;
}					t_stack;

/* Parsing */

int					is_double(t_stack *stack, int nbr);
void				fill_stack(t_stack *stack, char *argv);

/* Initialization */

t_node				*init_node(int value);
t_stack				*init_stack(t_node *n);
void				get_index(t_stack *stack);
void				free_stack(t_stack *stack);

/* Operations */

t_node				*pop_first(t_stack *stack);
t_node				*pop_last(t_stack *stack);
void				add_node(t_stack *stack, t_node *n);
void				push_node(t_stack *stack, t_node *noeud);

void				op_sa(t_stack *stack_a);
void				op_sb(t_stack *stack_b);
void				op_ss(t_stack *stack_a, t_stack *stack_b);
void				op_ra(t_stack *stack_a);
void				op_rb(t_stack *stack_b);
void				op_rr(t_stack *stack_a, t_stack *stack_b);
void				op_rra(t_stack *stack_a);
void				op_rrb(t_stack *stack_b);
void				op_rrr(t_stack *stack_a, t_stack *stack_b);
void				op_pa(t_stack *stack_a, t_stack *stack_b);
void				op_pb(t_stack *stack_a, t_stack *stack_b);

/* Sorting Algorithms */

void				mini_sort(t_stack *stack_a, t_stack *stack_b);
void				push_swap(t_stack *stack_a, t_stack *stack_b);

#endif
