/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaatlaou <yaatlaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 14:56:42 by yaatlaou          #+#    #+#             */
/*   Updated: 2024/11/04 10:13:59 by yaatlaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	swap(t_stack *stack)
{
	int	tmp;
	int	tmp_index;

	if (stack == NULL || stack->size == 1)
		return ;
	tmp = stack->first->data;
	tmp_index = stack->first->index;
	stack->first->data = stack->first->next->data;
	stack->first->index = stack->first->next->index;
	stack->first->next->data = tmp;
	stack->first->next->index = tmp_index;
}

void	op_sa(t_stack *stack_a)
{
	swap(stack_a);
	ft_putstr_fd("sa\n", 1);
}

void	op_sb(t_stack *stack_b)
{
	swap(stack_b);
	ft_putstr_fd("sb\n", 1);
}

void	op_ss(t_stack *stack_a, t_stack *stack_b)
{
	op_sa(stack_a);
	op_sb(stack_b);
	ft_putstr_fd("ss\n", 1);
}
