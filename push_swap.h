/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yasmine <yasmine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 16:43:26 by yaatlaou          #+#    #+#             */
/*   Updated: 2024/11/10 02:21:14 by yasmine          ###   ########.fr       */
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
	int				move_cost;
	struct s_node	*next;
}					t_node;

typedef struct s_stack
{
	unsigned int	size;
	t_node			*first;
}					t_stack;

/* Parsing */

void				parse_and_fill(t_stack *stack, char *argv);
void				display_error_and_exit(t_stack *stack, char **char_nbr);

/* Initialization */

t_node				*init_node(int value);
t_stack				*init_stack(t_node *n);
void				get_index(t_stack *stack);
void				free_stack(t_stack *stack);
void				add_node(t_stack *stack, t_node *n);

/* Operations */

t_node				*pop_first(t_stack *stack);
t_node				*pop_last(t_stack *stack);
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

/* Sorting Algorithms utils */

t_node				*find_min(t_stack *stack);
t_node				*find_max(t_stack *stack);
void				sort_three(t_stack *stack_a);
int					is_sorted(t_stack *stack);
int					get_position(t_stack *stack, int index);

int					get_median(t_stack *stack);
int					is_only_extreme(t_stack *stack, int q1, int q3);
void				compute_move_cost(t_stack *stack);
void				compute_cost(t_stack *stack_a, t_stack *stack_b);
void				rotate_to_position(t_stack *stack, int position, int is_a);
void				r_rotate_to_position(t_stack *stack, int position,
						int is_a);
void				op_extreme(t_stack *stack_a, t_stack *stack_b, int q1,
						int q3);
t_node				*find_cheapest(t_stack *stack);
t_node				*find_next_index(t_stack *stack, t_node *target_node,
						int diff_value);

void				mini_sort(t_stack *stack_a, t_stack *stack_b);
void				big_sort(t_stack *stack_a, t_stack *stack_b);

#endif
