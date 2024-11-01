/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_algo_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yasmine <yasmine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 01:09:52 by yasmine           #+#    #+#             */
/*   Updated: 2024/11/01 13:40:43 by yasmine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*find_min(t_stack *stack)
{
	t_node	*min;
	t_node	*current;

	if (stack == NULL || stack->first == NULL)
		return (NULL);
	min = stack->first;
	current = stack->first;
	while (current != NULL)
	{
		if (current->data < min->data)
			min = current;
		current = current->next;
	}
	return (min);
}

int	get_position(t_stack *stack, int index)
{
	int		position;
	t_node	*current;

	if (stack == NULL)
		return (0);
	position = 0;
	current = stack->first;
	while (current != NULL)
	{
		if (current->index == index)
			break ;
		position++;
		current = current->next;
	}
	return (position);
}

int	is_sorted(t_stack *stack)
{
	t_node	*current;

	if (stack == NULL || stack->first == NULL)
		return (0);
	current = stack->first;
	while (current->next != NULL)
	{
		if (current->data > current->next->data)
			return (0);
		current = current->next;
	}
	return (1);
}
