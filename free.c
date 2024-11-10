/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yasmine <yasmine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 18:40:24 by yasmine           #+#    #+#             */
/*   Updated: 2024/11/09 19:02:45 by yasmine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

void	display_error_and_exit(t_stack *stack, char **char_nbr)
{
	int	i;

	if (char_nbr)
	{
		i = 0;
		while (char_nbr[i])
		{
			free(char_nbr[i]);
			i++;
		}
		free(char_nbr);
	}
	if (stack)
		free_stack(stack);
	ft_putstr_fd("Error\n", 2);
	exit(EXIT_FAILURE);
}
