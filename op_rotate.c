/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaatlaou <yaatlaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 14:56:39 by yaatlaou          #+#    #+#             */
/*   Updated: 2024/09/30 15:16:54 by yaatlaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rotate(t_stack *stack)
{
	t_node	*elem;

	if (stack == NULL || stack->size == 1)
		return ;
	elem = stack->first;
	stack->first = stack->first->next;
	elem->next = NULL;
	add_node(stack, elem);
}

void	op_ra(t_stack *stack_a)
{
	rotate(stack_a);
	printf("ra\n");
}

void	op_rb(t_stack *stack_b)
{
	rotate(stack_b);
	printf("rb\n");
}

void	op_rr(t_stack *stack_a, t_stack *stack_b)
{
	op_ra(stack_a);
	op_rb(stack_b);
	printf("rr\n");
}
