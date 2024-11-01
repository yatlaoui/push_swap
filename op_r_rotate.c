/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_r_rotate.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yasmine <yasmine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 14:56:34 by yaatlaou          #+#    #+#             */
/*   Updated: 2024/11/01 12:35:03 by yasmine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	reverse_rotate(t_stack *stack)
{
	t_node	*elem;

	if (stack == NULL)
		return ;
	elem = pop_last(stack);
	push_node(stack, elem);
}

void	op_rra(t_stack *stack_a)
{
	reverse_rotate(stack_a);
	ft_putstr("rra\n");
}

void	op_rrb(t_stack *stack_b)
{
	reverse_rotate(stack_b);
	ft_putstr("rrb\n");
}

void	op_rrr(t_stack *stack_a, t_stack *stack_b)
{
	reverse_rotate(stack_a);
	reverse_rotate(stack_b);
	ft_putstr("rrr\n");
}
