/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeminian <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 13:12:14 by aeminian          #+#    #+#             */
/*   Updated: 2024/04/13 13:14:13 by aeminian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	min(t_stack *stack)
{
	int	n;

	n = stack->value;
	while (stack->next != NULL)
	{
		if (n > stack->next->value)
			n = stack->next->value;
		stack = stack->next;
	}
	return (n);
}

int	max(t_stack *stack)
{
	int	n;

	n = stack->value;
	while (stack->next != NULL)
	{
		if (n < stack->next->value)
			n = stack->next->value;
		stack = stack->next;
	}
	return (n);
}

int	max_index(t_stack *stack)
{
	int	n;

	n = stack->index;
	while (stack->next != NULL)
	{
		if (n < stack->next->index)
			n = stack->next->index;
		stack = stack->next;
	}
	return (n);
}

int	offset(int size)
{
	int	root;
	int	log;
	int	step;

	log = 1;
	root = 1;
	step = 0;
	while (root * root <= size)
	{
		root++;
		step++;
	}
	while (log * 2 <= size)
	{
		log *= 2;
		step++;
	}
	return (step);
}
