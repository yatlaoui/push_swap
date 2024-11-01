/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yasmine <yasmine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 14:56:39 by yaatlaou          #+#    #+#             */
/*   Updated: 2024/11/01 12:35:16 by yasmine          ###   ########.fr       */
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
	ft_putstr("ra\n");
}

void	op_rb(t_stack *stack_b)
{
	rotate(stack_b);
	ft_putstr("rb\n");
}

void	op_rr(t_stack *stack_a, t_stack *stack_b)
{
	op_ra(stack_a);
	op_rb(stack_b);
	ft_putstr("rr\n");
}
