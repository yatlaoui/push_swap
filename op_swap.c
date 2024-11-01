/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yasmine <yasmine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 14:56:42 by yaatlaou          #+#    #+#             */
/*   Updated: 2024/11/01 12:35:34 by yasmine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	swap(t_stack *stack)
{
	int	tmp;

	if (stack == NULL || stack->size == 1)
		return ;
	tmp = stack->first->data;
	stack->first->data = stack->first->next->data;
	stack->first->next->data = tmp;
}

void	op_sa(t_stack *stack_a)
{
	swap(stack_a);
	ft_putstr("sa\n");
}

void	op_sb(t_stack *stack_b)
{
	swap(stack_b);
	ft_putstr("sb\n");
}

void	op_ss(t_stack *stack_a, t_stack *stack_b)
{
	op_sa(stack_a);
	op_sb(stack_b);
	ft_putstr("ss\n");
}
