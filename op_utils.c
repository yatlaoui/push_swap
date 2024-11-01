/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yasmine <yasmine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 12:41:28 by yasmine           #+#    #+#             */
/*   Updated: 2024/11/01 12:54:41 by yasmine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_node(t_stack *stack, t_node *noeud)
{
	if (stack == NULL || noeud == NULL)
		return ;
	noeud->next = stack->first;
	stack->first = noeud;
	stack->size = stack->size + 1;
}

void	add_node(t_stack *stack, t_node *noeud)
{
	t_node	*current;

	if (stack == NULL || noeud == NULL)
		return ;
	if (stack->first == NULL)
		stack->first = noeud;
	else
	{
		current = stack->first;
		while (current->next != NULL)
			current = current->next;
		current->next = noeud;
	}
	stack->size = stack->size + 1;
}

t_node	*pop_first(t_stack *stack)
{
	t_node	*first_elem;

	if (stack == NULL || stack->first == NULL)
		return (NULL);
	first_elem = stack->first;
	stack->first = stack->first->next;
	return (first_elem);
}

t_node	*pop_last(t_stack *stack)
{
	t_node	*last_elem;
	t_node	*current;

	if (stack == NULL || stack->first == NULL)
		return (NULL);
	if (stack->first->next == NULL)
	{
		last_elem = stack->first;
		stack->first = NULL;
		return (last_elem);
	}
	current = stack->first;
	while (current->next->next != NULL)
		current = current->next;
	last_elem = current->next;
	current->next = NULL;
	return (last_elem);
}
