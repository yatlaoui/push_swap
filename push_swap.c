/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yasmine <yasmine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 21:10:49 by yasmine           #+#    #+#             */
/*   Updated: 2024/10/18 22:28:50 by yasmine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void push_swap(t_stack * stack_a,  t_stack * stack_b)
{
    if (stack_a->size <= 5)
       mini_sort(stack_a,stack_b);
    
}