/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeminian <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 12:46:08 by aeminian          #+#    #+#             */
/*   Updated: 2024/04/18 20:38:46 by aeminian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*temp_a;

	if (*stack_a == NULL)
		return ;
	temp_a = *stack_a;
	*stack_a = (*stack_a)->next;
	temp_a->next = *stack_b;
	*stack_b = temp_a;
}

void	pa(t_stack **stack_a, t_stack **stack_b)
{
	if (*stack_a == NULL)
		return ;
	push(stack_a, stack_b);
	write(1, "pa\n", 3);
}

void	pb(t_stack **stack_a, t_stack **stack_b)
{
	if (*stack_a == NULL)
		return ;
	push(stack_a, stack_b);
	write(1, "pb\n", 3);
}
