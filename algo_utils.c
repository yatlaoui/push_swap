/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yasmine <yasmine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 01:09:52 by yasmine           #+#    #+#             */
/*   Updated: 2024/11/09 21:40:23 by yasmine          ###   ########.fr       */
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

t_node	*find_max(t_stack *stack)
{
	t_node	*max;
	t_node	*current;

	if (stack == NULL || stack->first == NULL)
		return (NULL);
	max = stack->first;
	current = stack->first;
	while (current != NULL)
	{
		if (current->data > max->data)
			max = current;
		current = current->next;
	}
	return (max);
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

void	get_index(t_stack *stack)
{
	int		index;
	t_node	*i;
	t_node	*j;

	if (stack == NULL || stack->first == NULL)
		return ;
	i = stack->first;
	while (i != NULL)
	{
		index = 0;
		j = stack->first;
		while (j != NULL)
		{
			if (i->data > j->data)
				index = index + 1;
			j = j->next;
		}
		i->index = index;
		i = i->next;
	}
}
