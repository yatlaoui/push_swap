/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_algo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yasmine <yasmine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 21:46:32 by yasmine           #+#    #+#             */
/*   Updated: 2024/11/01 12:06:44 by yasmine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_node *find_min(t_stack *stack)
{
    t_node *min;
    t_node *current;

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

static int get_position(t_stack *stack, int index)
{
    int position;
    t_node *current;

    if (stack == NULL)
        return (0);
    position = 0;
    current = stack->first;
    while (current != NULL)
    {
        if (current->index == index)
              break;
        position++;
        current = current->next;
    }
    return (position); 
}

static int is_sorted(t_stack *stack)
{
    t_node *current;

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

static void sort_three(t_stack *stack_a)
{
    int first;
    int second;
    int third;

    // if (stack_a == NULL || stack_a->first == NULL)
    //     return;
	first = stack_a->first->index;
    second = stack_a->first->next->index;
    third = stack_a->first->next->next->index;
    if (first > second && second < third && first < third)
        op_sa(stack_a);
    else if (first > second && second > third)
    {
        op_sa(stack_a);
        op_rra(stack_a);
    }
    else if (first > second && first > third)
        op_ra(stack_a);
    else if (first < second && second > third && first < third)
    {
        op_sa(stack_a);
        op_ra(stack_a);
    }
    else if (first < second && second > third && first > third)
        op_rra(stack_a);
}


static void sort_four(t_stack *stack_a, t_stack *stack_b)
{
    t_node *min;
    int position;
    
    // if (stack_a == NULL || stack_a->first == NULL)
    //     return;
    min = find_min(stack_a);
    position = get_position(stack_a, min->index);
    if (position == 1)
        op_ra(stack_a);
    else if (position == 2)
    {
        op_ra(stack_a);
        op_ra(stack_a);
    }
    else if (position == 3)
    {
        op_rra(stack_a);        
    }
	op_pb(stack_a, stack_b);
    sort_three(stack_a);
    op_pa(stack_a, stack_b);
}

static void sort_five(t_stack *stack_a, t_stack *stack_b)
{
    t_node *min;
    int position;

    // if (stack_a == NULL || stack_a->first == NULL)
    //     return;
    min = find_min(stack_a);
    position = get_position(stack_a, min->index);
    if (position == 1)
        op_ra(stack_a);
    else if (position == 2)
    {
        op_ra(stack_a);
        op_ra(stack_a);
    }
    else if (position == 3)
    {
        op_rra(stack_a);
        op_rra(stack_a);      
    }
    else if (position == 4)
    {
        op_rra(stack_a);
    }
	op_pb(stack_a, stack_b);
    sort_four(stack_a, stack_b);
    op_pa(stack_a, stack_b);
}

void    mini_sort(t_stack *stack_a, t_stack *stack_b)
{
    if (stack_a == NULL)
        return ;
    if (is_sorted(stack_a) == 0)
    {
        if (stack_a->size == 2)
            op_sa(stack_a);
        else if (stack_a->size == 3)
            sort_three(stack_a);
        else if (stack_a->size == 4)
            sort_four(stack_a, stack_b);
        else if (stack_a->size == 5)
            sort_five(stack_a, stack_b); 
    }
}
