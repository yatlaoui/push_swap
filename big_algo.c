/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_algo.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaatlaou <yaatlaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 21:10:49 by yasmine           #+#    #+#             */
/*   Updated: 2024/11/04 11:15:35 by yaatlaou         ###   ########.fr       */
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
			op_extreme(stack_a, stack_b, q1, q3);
		else
			op_ra(stack_a);
	}
}

static void	last_push_to_a(t_stack *stack_a, t_stack *stack_b)
{
	t_node			*current;
	t_node			*max;
	unsigned int	position;

	while (stack_b->size > 0)
	{
		current = stack_b->first;
		max = find_max(stack_b);
		position = get_position(stack_b, max->index);
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

void	big_sort(t_stack *stack_a, t_stack *stack_b)
{
	if (is_sorted(stack_a) == 0)
	{
		pre_sort_to_b(stack_a, stack_b);
		last_push_to_a(stack_a, stack_b);
	}
}
