/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_algo_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yasmine <yasmine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 11:26:03 by yasmine           #+#    #+#             */
/*   Updated: 2024/11/03 23:11:03 by yasmine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	get_median(t_stack *stack)
{
	if (stack->size % 2 == 0)
		return ((stack->size + 1) / 2);
	return (stack->size / 2);
}

static int	is_only_extreme(t_stack *stack, int q1, int q3)
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

void	pre_sort(t_stack *stack_a, t_stack *stack_b)
{
	int	q1;
	int	q3;
	int	median;
	t_node	*current;

	q1 = stack_a->size / 4;
	q3 = (3 * stack_a->size) / 4;
	median = get_median(stack_a);
	current = stack_a->first;
	while (stack_a->size > 0)
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
		{
			if (current->index <= q1)
			{
				op_pb(stack_a, stack_b);
				op_rb(stack_b);
			}
			if (current->index >= q3)
				op_pb(stack_a, stack_b);
		}
		else // if (current->index > q3 || current->index < q1)
			op_ra(stack_a);
	}
}

// static void swap_if_sup(t_stack *stack)
// {
// 	t_node *current;

// 	current = stack->first;
// 	if (current->index < current->next->index)
// 		op_sb(stack);
// }

static void rotate_to_position(t_stack *stack, int position)
{
	int cpt;

	cpt = 0;
	// printf("pos : %d",position);
	while (cpt != position)
	{
		op_rb(stack);
		// printf("in rotate\n");
		// print_stack(stack);
		cpt++;
	}
	// printf("after rotate\n");
	// print_stack(stack);
}

static void r_rotate_to_position(t_stack *stack, int position)
{
	int cpt;

	cpt = stack->size;
	while (cpt > position)
	{	
		op_rrb(stack);
		cpt--;
	}
	// printf("after r rotqte\n");
	// print_stack(stack);
}

void super_push(t_stack *stack_a, t_stack *stack_b)
{
	t_node *current;
	t_node *max;
	unsigned int position;


	while (stack_b->size > 0)
	{
		// printf("Stack A :");
		// print_stack(stack_a);
		// printf("Stack B :");
		// print_stack(stack_b);
		// //swap_if_sup(stack_b);
		// printf("size b : %d ", stack_b->size);
		current = stack_b->first;
		max = find_max(stack_b);
		position = get_position(stack_b, max->index);
		// printf("position %d\n",position);
		if (position == 0 && current->index == max->index)
			op_pa(stack_a, stack_b);
		else
		{
			if (position >= (stack_b->size / 2))
			{
				r_rotate_to_position(stack_b, position);
				op_pa(stack_a, stack_b);
			}
			else
			{
				rotate_to_position(stack_b, position);
				op_pa(stack_a, stack_b);
			}
		}
	}
}
