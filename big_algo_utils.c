/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_algo_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yasmine <yasmine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 11:26:03 by yasmine           #+#    #+#             */
/*   Updated: 2024/11/03 16:36:37 by yasmine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

static int get_median(t_stack *stack)
{
	if (stack->size % 2 == 0)
		return ((stack->size + 1) / 2 );
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
		printf("size = %d\n", stack_a->size);
		printf("Stack A :");
		print_stack(stack_a);
		printf("Stack B :");
		print_stack(stack_b);
		printf("q1 : %d\n", q1);
		printf("median : %d\n", median);
		printf("q3 : %d\n", q3);
		current = stack_a->first;
		if (current->index < median && current->index >= q1)
		{
			op_pb(stack_a, stack_b);
			op_rb(stack_b);
		}
		else if (current->index >= median && current->index <= q3)
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
