/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yasmine <yasmine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 10:20:34 by yasmine           #+#    #+#             */
/*   Updated: 2024/10/18 16:18:47 by yasmine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

