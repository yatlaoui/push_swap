/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yasmine <yasmine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 22:42:58 by yasmine           #+#    #+#             */
/*   Updated: 2024/11/10 10:27:34 by yasmine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	compute_move_cost(t_stack *stack)
{
	unsigned int	i;
	int				is_above_mid_stack;
	t_node			*current;

	i = 1;
	is_above_mid_stack = 1;
	current = stack->first;
	while (current != NULL)
	{
		if (i > stack->size / 2 || is_above_mid_stack == 0)
		{
			current->move_cost = i;
			i--;
			is_above_mid_stack = 0;
		}
		else
		{
			current->move_cost = i;
			i++;
		}
		current = current->next;
	}
}

t_node	*find_cheapest(t_stack *stack)
{
	t_node	*current;
	t_node	*value;

	current = stack->first;
	value = current;
	while (current != NULL)
	{
		if (current->move_cost < value->move_cost)
			value = current;
		current = current->next;
	}
	return (value);
}

void	compute_cost(t_stack *stack_a, t_stack *stack_b)
{
	t_node	*current_b;
	t_node	*next_index;

	current_b = stack_b->first;
	compute_move_cost(stack_b);
	compute_move_cost(stack_a);
	while (current_b != NULL)
	{
		next_index = find_next_index(stack_a, current_b, __INT_MAX__);
		// if (next_index == NULL)
		// 	next_index = find_max(stack_a);
		current_b->move_cost = current_b->move_cost + next_index->move_cost;
		current_b = current_b->next;
	}
}
