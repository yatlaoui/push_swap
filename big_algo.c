/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_algo.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yasmine <yasmine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 21:10:49 by yasmine           #+#    #+#             */
/*   Updated: 2024/11/08 13:22:23 by yasmine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>
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

// static void	last_push_to_a(t_stack *stack_a, t_stack *stack_b)
// {
// 	t_node			*current;
// 	t_node			*max;
// 	unsigned int	position;

// 	while (stack_b->size > 0)
// 	{
// 		current = stack_b->first;
// 		max = find_max(stack_b);
// 		position = get_position(stack_b, max->index);
// 		if (position == 0 && current->index == max->index)
// 			op_pa(stack_a, stack_b);
// 		else
// 		{
// 			if (position >= (stack_b->size / 2))
// 			{
// 				r_rotate_to_position(stack_b, position);
// 				op_pa(stack_a, stack_b);
// 			}
// 			else
// 			{
// 				rotate_to_position(stack_b, position);
// 				op_pa(stack_a, stack_b);
// 			}
// 		}
// 	}
// }

static void	compute_move_cost(t_stack *stack)
{
	unsigned int i;
	int is_above_median;
	t_node *current;
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


static t_node* find_next_index(t_stack *stack, t_node* target_node){
	t_node *current = stack->first;
	t_node *value = NULL;
	int diff_value = __INT_MAX__;  // Set to a large value initially

	while (current != NULL) {	
		// Check if current node's index is greater than target node's index
		if (current->index > target_node->index) {
			int current_diff = current->index - target_node->index;

			// If this is the closest upper index so far, update `value` and `diff_value`
			if (current_diff < diff_value) {
				value = current;
				diff_value = current_diff;
			}
		}
		current = current->next;
	}
	return value;
}


static t_node* find_cheapest(t_stack *stack)
{
	t_node *current;
	t_node *value;
	current = stack->first;
	value = current;
	while (current != NULL)
	{	
		if(current->move_cost < value->move_cost)
			value = current;
		current = current->next;
	}
	return value;
}

static void	compute_cost(t_stack *stack_a, t_stack *stack_b)
{
	t_node *current_b;
	t_node *next_index;

	current_b = stack_b->first;
	
	compute_move_cost(stack_b);
	compute_move_cost(stack_a);
	while (current_b != NULL)
	{
		next_index = find_next_index(stack_a,current_b);
		current_b->move_cost = current_b->move_cost+next_index->move_cost;
		current_b = current_b->next;
	}
}

static void move_node_to_push_position(t_stack * stack, t_node* target_node)
{
	unsigned int	position;
	
	if (stack == NULL || target_node == NULL || stack->size == 0) 
		return ;	
	
	position = get_position(stack, target_node->index);
	if (position >= (stack->size / 2))
 		r_rotate_to_position(stack, position);
 	else
 		rotate_to_position(stack, position);
	printf("AAAABB \n");
}

static void	optimized_push_to_a(t_stack *stack_a, t_stack *stack_b)
{
	t_node *current_b;
	t_node *upper_index;
	
	
	sort_three(stack_a);
	while (stack_b->size > 0)
	{
		compute_cost(stack_a, stack_b);
		current_b = find_cheapest(stack_b);
		if (current_b == NULL)
			break;
		upper_index = find_next_index(stack_a,current_b);
		
		printf("Current %d :", current_b->index);
		printf("upper_index %d :", upper_index->index);
		printf("stack A: ");
		print_stack(stack_a);
		printf("stack B: ");
		print_stack(stack_b);
		move_node_to_push_position(stack_b, current_b);
		
		move_node_to_push_position(stack_a, upper_index);
		op_pa(stack_a, stack_b);	
	}
	move_node_to_push_position(stack_a, find_min(stack_a));
}

void	big_sort(t_stack *stack_a, t_stack *stack_b)
{
	if (is_sorted(stack_a) == 0)
	{
		pre_sort_to_b(stack_a, stack_b);
		optimized_push_to_a(stack_a, stack_b);
		printf("AAAACC \n");
	}
}
