/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yasmine <yasmine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 16:43:33 by yaatlaou          #+#    #+#             */
/*   Updated: 2024/11/01 22:39:33 by yasmine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	display_error_and_exit(void)
{
	ft_putstr_fd("Error\n", 2);
	exit(EXIT_FAILURE);
}

static int	is_number(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
	if (str[i] == '\0')
		return (0);
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (1);
		i++;
	}
	return (0);
}

static long	ft_atoi_long(const char *str)
{
	int		i;
	long	nb;
	int		signe;

	i = 0;
	nb = 0;
	signe = 1;
	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			signe = signe * (-1);
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		nb = (nb * 10) + str[i] - 48;
		i++;
	}
	return (nb * signe);
}

static int	is_double(t_stack *stack, int nbr)
{
	t_node	*current;

	if (stack == NULL || stack->first == NULL)
		return (0);
	current = stack->first;
	while (current != NULL)
	{
		if (current->data == nbr)
			return (1);
		current = current->next;
	}
	return (0);
}

void	parse_and_fill(t_stack *stack, char *argv)
{
	int		i;
	char	**char_nbr;
	long	nbr;

	i = 0;
	if (stack == NULL || argv == NULL)
		return ;
	char_nbr = ft_split(argv, ' ');
	while (char_nbr[i] != 0)
	{
		if (is_number(char_nbr[i]) == 1)
			display_error_and_exit();
		nbr = ft_atoi_long(char_nbr[i]);
		if (nbr < INT_MIN || nbr > INT_MAX)
			display_error_and_exit();
		if (is_double(stack, nbr) == 0)
			add_node(stack, init_node(nbr));
		else
		{
			free_stack(stack);
			display_error_and_exit();
		}
		i++;
	}
}
