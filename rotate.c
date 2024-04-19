/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeminian <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 12:49:22 by aeminian          #+#    #+#             */
/*   Updated: 2024/04/18 20:22:06 by aeminian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate(t_stack **stack)
{
	t_stack	*last_node;
	t_stack	*temp;

	temp = *stack;
	*stack = (*stack)->next;
	last_node = ft_lstlast(temp);
	last_node->next = malloc(sizeof(t_stack));
	malloc_check(last_node->next);
	last_node->next->value = temp->value;
	last_node->next->index = temp->index;
	last_node->next->next = NULL;
	free(temp);
}

void	ra(t_stack **stack1)
{
	if (!stack1 || (*stack1)->next == NULL)
		return ;
	rotate(stack1);
	write(1, "ra\n", 3);
}

void	rb(t_stack **stack1)
{
	if (!stack1 || (*stack1)->next == NULL)
		return ;
	rotate(stack1);
	write(1, "rb\n", 3);
}

void	rr(t_stack **stack1, t_stack **stack2)
{
	rotate(stack1);
	rotate(stack2);
	write(1, "rr\n", 3);
}
