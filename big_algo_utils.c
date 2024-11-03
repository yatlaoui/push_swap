/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_algo_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yasmine <yasmine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 11:26:03 by yasmine           #+#    #+#             */
/*   Updated: 2024/11/03 12:31:50 by yasmine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

static int	is_only_extreme(t_stack *stack, int q1, int q3)
{
	t_node	*current;

	current = stack->first;
	while (current)
	{
		if (current->index >= q1 || current->index <= q3)
			return (1);
		current = current->next;
	}
	return (0);
}

void	pre_sort(t_stack *stack_a, t_stack *stack_b)
{
	int	q1;
	int	q2;
	int	q3;
	t_node	*current;

	q1 = stack_a->size / 4;
	q2 = (stack_a->size / 2) + 1;
	q3 = stack_a->size - q1;
	current = stack_a->first;
	while (stack_a->size >= 3)
	{
		printf("size = %d\n", stack_a->size);
		if (current->data < q2 && current->data > q1)
		{
			op_pa(stack_a, stack_b);
			op_rb(stack_b);
		}
		else if (current->data > q2 && current->data < q3)
			op_pa(stack_a, stack_b);
		else if (current->data < q2 && current->data > q1 && is_only_extreme(stack_a, q1, q3) == 0)
		{
			op_pa(stack_a, stack_b);
			op_rb(stack_b);
		}
		else if (current->data > q2 && current->data < q3 && is_only_extreme(stack_a, q1, q3) == 0)
			op_pa(stack_a, stack_b);
		else // if (current->data > q3 || current->data < q1)
			op_ra(stack_a);
	
	break;
	}
	
}
