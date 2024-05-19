/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adel <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 16:02:11 by adel              #+#    #+#             */
/*   Updated: 2024/04/18 20:38:22 by aeminian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	index_alt(t_stack **stack, int len)
{
	t_stack	*temp;
	int		minimum;
	int		i;
	int		secmin;

	temp = *stack;
	i = 1;
	minimum = min(*stack);
	while (len--)
	{
		secmin = INT_MAX;
		*stack = temp;
		while ((*stack))
		{
			if ((*stack)->value < secmin && (*stack)->value > minimum)
			{
				secmin = (*stack)->value;
				(*stack)->index = i;
			}
			*stack = (*stack)->next;
		}
		i++;
		minimum = secmin;
	}
	*stack = temp;
}

void	init_stack(t_stack **stack1, int nbr)
{
	t_stack	*stack_a;
	t_stack	*last_node;

	stack_a = malloc(sizeof(t_stack));
	malloc_check(stack_a);
	stack_a->value = nbr;
	stack_a->next = NULL;
	stack_a->index = 0;
	if (*stack1 == NULL)
	{
		*stack1 = stack_a;
	}
	else
	{
		last_node = ft_lstlast(*stack1);
		last_node->next = stack_a;
	}
}

t_stack	**validation(char **stack, t_stack **stack1)
{
	int	nbr;
	int	len;

	if (!stack || !*stack)
		return (NULL);
	while (*stack)
	{
		if (!check_arguments(stack))
		{
			free(*stack);
			exit(1);
		}
		overflow_check(*stack);
		nbr = ft_atol(*stack);
		init_stack(stack1, nbr);
		stack++;
	}
	free(*stack);
	len = ft_lstsize(*stack1);
	index_alt(stack1, len);
	return (stack1);
}

void	parser(char **av, t_stack **stack1)
{
	char	**stack_a;
	t_stack	**stack;
	int		i;
	int		k;

	i = 1;
	while (av[i])
	{
		stack_a = ft_split(av[i]);
		if (!(stack_a))
			error_handle();
		stack = validation(stack_a, stack1);
		k = 0;
		while (stack_a[k])
		{
			free(stack_a[k]);
			k++;
		}
		free(stack_a);
		repetation_check(stack);
		i++;
	}
}
