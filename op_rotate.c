/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaatlaou <yaatlaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 14:56:39 by yaatlaou          #+#    #+#             */
/*   Updated: 2024/11/04 10:13:30 by yaatlaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rotate(t_stack *stack)
{
	t_node	*elem;

	if (stack == NULL || stack->size == 1)
		return ;
	elem = pop_first(stack);
	add_node(stack, elem);
}

void	op_ra(t_stack *stack_a)
{
	rotate(stack_a);
	ft_putstr_fd("ra\n", 1);
}

void	op_rb(t_stack *stack_b)
{
	rotate(stack_b);
	ft_putstr_fd("rb\n", 1);
}

void	op_rr(t_stack *stack_a, t_stack *stack_b)
{
	op_ra(stack_a);
	op_rb(stack_b);
	ft_putstr_fd("rr\n", 1);
}
