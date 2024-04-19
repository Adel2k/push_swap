/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adel <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 16:02:11 by adel              #+#    #+#             */
/*   Updated: 2024/04/13 12:45:54 by aeminian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	malloc_check(void *str)
{
	if (!str)
		error_handle();
}

int	check_arguments(char **str)
{
	int	i;
	int	j;

	j = 0;
	while (str[j])
	{
		i = 0;
		if (str[j][i] == '-' || str[j][i] == '+')
			i++;
		while (str[j][i])
		{
			if (!(str[j][i] >= '0' && str[j][i] <= '9'))
				error_handle();
			i++;
		}
		j++;
	}
	return (1);
}

void	repetation_check(t_stack **stack)
{
	t_stack	*current;
	t_stack	*runner;

	current = *stack;
	while (current)
	{
		runner = current->next;
		while (runner)
		{
			if (runner->value == current->value)
			{
				error_handle();
				return ;
			}
			runner = runner->next;
		}
		current = current->next;
	}
}

void	error_handle(void)
{
	write(2, "Error\n", 6);
	exit(EXIT_FAILURE);
}
