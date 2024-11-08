/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yasmine <yasmine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 14:46:39 by yaatlaou          #+#    #+#             */
/*   Updated: 2024/11/08 12:37:58 by yasmine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

void	print_stack(t_stack *stack)
{
	t_node	*current;

	if (stack == NULL)
		return ;
	current = stack->first;
	fprintf(stderr,"[");
	while (current != NULL)
	{
		//printf(" (v: %d, c: %d, i:%d) ", current->data,current->move_cost, current->index);
		fprintf(stderr," (%d) ", current->index);
		current = current->next;
	}
	fprintf(stderr,"]");
	fprintf(stderr,"\n");
}

int	main(int argc, char **argv)
{
	int		i;
	t_stack	*stack_a;
	t_stack	*stack_b;

	if (argc < 2)
		return (0);
	i = 1;
	stack_a = init_stack(NULL);
	
	while (i < argc)
		parse_and_fill(stack_a, argv[i++]);
	
	stack_b = init_stack(NULL);
	get_index(stack_a);
	if (stack_a->size <= 5)
		mini_sort(stack_a, stack_b);
	if (stack_a->size > 5)
	{
		// do a print on error
		print_stack(stack_a);
		big_sort(stack_a, stack_b);
		print_stack(stack_a);
		print_stack(stack_b);
		
	}
	free_stack(stack_a);
	free_stack(stack_b);
	return (0);
}
