/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_algo.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yasmine <yasmine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 21:10:49 by yasmine           #+#    #+#             */
/*   Updated: 2024/11/03 23:10:58 by yasmine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

void	big_sort(t_stack *stack_a, t_stack *stack_b)
{
    if (is_sorted(stack_a) == 0)
    {
        pre_sort(stack_a, stack_b);
        super_push(stack_a, stack_b);
    }
}
