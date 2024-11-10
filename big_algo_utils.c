/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_algo_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yasmine <yasmine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 11:26:03 by yasmine           #+#    #+#             */
/*   Updated: 2024/11/10 10:35:03 by yasmine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_median(t_stack *stack)
{
	if (stack->size % 2 == 0)
		return ((stack->size + 1) / 2);
	return (stack->size / 2);
}

int	is_only_extreme(t_stack *stack, int q1, int q3)
{
	t_node	*current;

	current = stack->first;
	while (current)
	{
		if (current->index > q1 && current->index < q3)
			return (1);
		current = current->next;
	}
	return (0);
}

void	op_extreme(t_stack *stack_a, t_stack *stack_b, int q1, int q3)
{
	t_node	*current;

	current = stack_a->first;
	if (current->index <= q1)
	{
		op_pb(stack_a, stack_b);
		op_rb(stack_b);
	}
	if (current->index >= q3)
		op_pb(stack_a, stack_b);
}

void	rotate_to_position(t_stack *stack, int position, int print_stack_a)
{
	int	cpt;

	cpt = 0;
	while (cpt != position)
	{
		if (print_stack_a)
			op_ra(stack);
		else
			op_rb(stack);
		cpt++;
	}
}

void	r_rotate_to_position(t_stack *stack, int position, int print_stack_a)
{
	int	cpt;

	cpt = stack->size;
	while (cpt > position)
	{
		if (print_stack_a)
			op_rra(stack);
		else
			op_rrb(stack);
		cpt--;
	}
}
