/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yasmine <yasmine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 22:37:50 by yasmine           #+#    #+#             */
/*   Updated: 2024/11/08 08:21:54 by yasmine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*init_node(int value)
{
	t_node	*noeud;

	noeud = malloc(sizeof(t_node));
	if (noeud == NULL)
		return (NULL);
	noeud->data = value;
	noeud->index = 0;
	noeud->move_cost = -1;
	noeud->next = NULL;
	return (noeud);
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

t_stack	*init_stack(t_node *n)
{
	t_stack	*stack;

	stack = malloc(sizeof(t_stack));
	if (stack == NULL)
		return (NULL);
	stack->size = 0;
	stack->first = n;
	return (stack);
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

void	free_stack(t_stack *stack)
{
	t_node	*next;

	next = NULL;
	while (stack->first != NULL)
	{
		next = stack->first->next;
		free(stack->first);
		stack->first = next;
	}
	free(stack);
}
