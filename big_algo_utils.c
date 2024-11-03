/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_algo_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yasmine <yasmine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 11:26:03 by yasmine           #+#    #+#             */
/*   Updated: 2024/11/03 23:57:29 by yasmine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_median(t_stack *stack)
{
	if (stack->size % 2 == 0)
		return ((stack->size + 1) / 2);
	return (stack->size / 2);
}

int	is_only_extreme(t_stack *stack, int q1, int q3)
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

void	rotate_to_position(t_stack *stack, int position)
{
	int	cpt;

	cpt = 0;
	while (cpt != position)
	{
		op_rb(stack);
		cpt++;
	}
}

void	r_rotate_to_position(t_stack *stack, int position)
{
	int	cpt;

	cpt = stack->size;
	while (cpt > position)
	{
		op_rrb(stack);
		cpt--;
	}
}
