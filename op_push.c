/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yasmine <yasmine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 14:56:28 by yaatlaou          #+#    #+#             */
/*   Updated: 2024/11/01 12:34:45 by yasmine          ###   ########.fr       */
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
	push(stack_b, stack_a);
	ft_putstr("pa\n");
}

void	op_pb(t_stack *stack_a, t_stack *stack_b)
{
	push(stack_a, stack_b);
	ft_putstr("pb\n");
}
