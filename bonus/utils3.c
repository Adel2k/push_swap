/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeminian <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 20:11:54 by aeminian          #+#    #+#             */
/*   Updated: 2024/04/18 20:15:50 by aeminian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_lstsize(t_stack *stack)
{
	int	size;

	size = 0;
	while (stack)
	{
		stack = stack->next;
		size++;
	}
	return (size);
}

t_stack	*ft_lstlast(t_stack *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next != NULL)
		lst = lst->next;
	return (lst);
}

int	min_in_a(t_stack *a, int len)
{
	while (a)
	{
		if (a->index < len - 3)
			return (1);
		a = a->next;
	}
	return (0);
}

int	get_position(t_stack *stack, int max)
{
	int	i;
	int	len;

	len = ft_lstsize(stack);
	i = 0;
	while (i < len)
	{
		if (stack->index == max)
			return (i);
		stack = stack->next;
		i++;
	}
	return (i);
}

void	dealoc(t_stack **stack)
{
	t_stack	*temp;

	while (*stack != NULL)
	{
		temp = *stack;
		*stack = (*stack)->next;
		free(temp);
	}
	*stack = NULL;
}
