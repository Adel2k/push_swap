/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeminian <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 12:50:23 by aeminian          #+#    #+#             */
/*   Updated: 2024/04/18 20:23:33 by aeminian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	reverse_rotate(t_stack **a)
{
	t_stack	*tmp;
	t_stack	*last;

	if (*a == NULL || a == NULL)
		return ;
	tmp = (*a);
	last = 0;
	while (tmp -> next)
	{
		if (!(tmp -> next -> next))
		{
			last = tmp -> next;
			tmp -> next = 0;
			break ;
		}
		tmp = tmp -> next;
	}
	if (last)
	{
		last -> next = (*a);
		(*a) = last;
	}
}

void	rra(t_stack **stack)
{
	reverse_rotate(stack);
	write(1, "rra\n", 4);
}

void	rrb(t_stack **stack)
{
	if (!stack || (*stack)->next == NULL)
		return ;
	reverse_rotate(stack);
	write(1, "rrb\n", 4);
}

void	rrr(t_stack **stack1, t_stack **stack2)
{
	reverse_rotate(stack1);
	reverse_rotate(stack2);
	write(1, "rrr\n", 4);
}
