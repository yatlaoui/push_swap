/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yasmine <yasmine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 14:46:39 by yaatlaou          #+#    #+#             */
/*   Updated: 2024/11/01 22:23:53 by yasmine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

void	print_stack(t_stack *stack)
{
	t_node *current;

	if (stack == NULL)
		return ;
	current = stack->first;
	while (current != NULL)
	{
		printf("%d\n", current->data);
		current = current->next;
	}
	printf("\n");
}

int	main(int argc, char **argv)
{
	int i;
	t_stack *stack_a;
	t_stack *stack_b;

	i = 1;
	stack_a = init_stack(NULL);
	stack_b = init_stack(NULL);
	while (i < argc)
		fill_stack(stack_a, argv[i++]);
	get_index(stack_a);
	
	printf("stack avant : \n");
	print_stack(stack_a);
	printf("stack après : \n");
	mini_sort(stack_a, stack_b);
	print_stack(stack_a);

	free_stack(stack_a);
	free_stack(stack_b);

	return (0);
}

