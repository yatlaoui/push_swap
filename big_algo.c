/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_algo.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yasmine <yasmine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 21:10:49 by yasmine           #+#    #+#             */
/*   Updated: 2024/11/09 16:59:56 by yasmine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	op_extreme(t_stack *stack_a, t_stack *stack_b, int q1, int q3)
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

static void	pre_sort_to_b(t_stack *stack_a, t_stack *stack_b)
{
	int		q1;
	int		q3;
	int		median;
	t_node	*current;

	q1 = stack_a->size / 4;
	q3 = (3 * stack_a->size) / 4;
	median = get_median(stack_a);
	while (stack_a->size > 3)
	{
		current = stack_a->first;
		if (current->index <= median && current->index >= q1)
		{
			op_pb(stack_a, stack_b);
			op_rb(stack_b);
		}
		else if (current->index > median && current->index <= q3)
			op_pb(stack_a, stack_b);
		else if (is_only_extreme(stack_a, q1, q3) == 0)
			op_extreme(stack_a, stack_b, q1, q3);
		else
			op_ra(stack_a);
	}
}

static void	compute_move_cost(t_stack *stack)
{
	unsigned int	i;
	int				is_above_median;
	t_node			*current;

	i = 1;
	is_above_median = 1;
	current = stack->first;
	while (current != NULL)
	{
		if (i > stack->size / 2 || is_above_median == 0)
		{
			current->move_cost = i;
			i--;
			is_above_median = 0;
		}
		else
		{
			current->move_cost = i;
			i++;
		}
		current = current->next;
	}
}

static t_node	*find_next_index(t_stack *stack, t_node *target_node)
{
	t_node	*current;
	t_node	*value;
	int		diff_value;
	int		current_diff;

	// if (stack == NULL || target_node == NULL || stack->size == 0)
	// 	return (NULL);
	current = stack->first;
	diff_value = __INT_MAX__;
	value = find_max(stack);
	if (value->index < target_node->index)
		return (value);
	else
		value = NULL;
	while (current != NULL)
	{
		if (current->index > target_node->index)
		{
			current_diff = current->index - target_node->index;
			if (current_diff < diff_value)
			{
				value = current;
				diff_value = current_diff;
			}
		}
		current = current->next;
	}
	return (value);
}

static t_node	*find_cheapest(t_stack *stack)
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

static void	compute_cost(t_stack *stack_a, t_stack *stack_b)
{
	t_node	*current_b;
	t_node	*next_index;

	current_b = stack_b->first;
	compute_move_cost(stack_b);
	compute_move_cost(stack_a);
	while (current_b != NULL)
	{
		next_index = find_next_index(stack_a, current_b);
		if (next_index == NULL)
			next_index = find_max(stack_a);
		current_b->move_cost = current_b->move_cost + next_index->move_cost;
		current_b = current_b->next;
	}
}

static void	move_node_to_push_position(t_stack *stack, t_node *target_node,
		t_node *node_to_place, int is_a)
{
	unsigned int	position;

	if (stack == NULL || target_node == NULL || stack->size == 0)
		return ;
	position = get_position(stack, target_node->index);
	if (node_to_place != NULL)
	{
		if (node_to_place->index > target_node->index)
			position = position + 1;
	}
	if (position >= (stack->size / 2))
		r_rotate_to_position(stack, position,is_a);
	else
		rotate_to_position(stack, position,is_a);
}

static void	optimized_push_to_a(t_stack *stack_a, t_stack *stack_b)
{
	t_node	*current_b;
	t_node	*upper_index;

	sort_three(stack_a);
	while (stack_b->size > 0)
	{
		compute_cost(stack_a, stack_b);
		current_b = find_cheapest(stack_b);
		if (current_b == NULL)
			break ;
		upper_index = find_next_index(stack_a, current_b);
		move_node_to_push_position(stack_b, current_b, NULL, 0);
		move_node_to_push_position(stack_a, upper_index, current_b,1);
		op_pa(stack_a, stack_b);
	}
	move_node_to_push_position(stack_a, find_min(stack_a), NULL,1);
}

void	big_sort(t_stack *stack_a, t_stack *stack_b)
{
	if (is_sorted(stack_a) == 0)
	{
		pre_sort_to_b(stack_a, stack_b);
		optimized_push_to_a(stack_a, stack_b);
	}
}
