/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   butterfly.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeminian <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 20:09:11 by aeminian          #+#    #+#             */
/*   Updated: 2024/04/18 20:45:01 by aeminian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	butterfly(t_stack **stack_a)
{
	t_stack	*stack_b;
	int		min;
	int		h;

	stack_b = NULL;
	min = 0;
	h = offset(ft_lstsize(*stack_a) - 1);
	while ((*stack_a) != NULL)
	{
		if ((*stack_a)->index <= min)
		{
			pb(stack_a, &stack_b);
			rb(&stack_b);
			min++;
		}
		else if ((*stack_a)->index <= min + h)
		{
			pb(stack_a, &stack_b);
			min++;
		}
		else
			ra(stack_a);
	}
	sort_in_a(stack_a, stack_b, 0, 0);
}

void	sort_in_a(t_stack **stack_a, t_stack *stack_b, int maxn, int n)
{
	maxn = max_index(stack_b);
	while (stack_b != NULL)
	{
		n = get_position(stack_b, maxn);
		if (n < ft_lstsize(stack_b) / 2)
		{
			while (n > 0)
			{
				rb(&stack_b);
				n--;
			}
			pa(&stack_b, stack_a);
			maxn--;
		}
		else
		{
			while (n < ft_lstsize(stack_b))
			{
				rrb(&stack_b);
				n++;
			}
			pa(&stack_b, stack_a);
			maxn--;
		}
	}
}
