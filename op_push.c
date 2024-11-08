/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaatlaou <yaatlaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 14:56:28 by yaatlaou          #+#    #+#             */
/*   Updated: 2024/11/04 10:14:49 by yaatlaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	push(t_stack *src, t_stack *dest)
{
	if (src == NULL || src->first == NULL)
		return ;
	push_node(dest, pop_first(src));
}

void	op_pa(t_stack *stack_a, t_stack *stack_b)
{
	if (stack_b->size == 0)
		return ;
	push(stack_b, stack_a);
	ft_putstr_fd("pa\n", 1);
}

void	op_pb(t_stack *stack_a, t_stack *stack_b)
{
	push(stack_a, stack_b);
	ft_putstr_fd("pb\n", 1);
}
