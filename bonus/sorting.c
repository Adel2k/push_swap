/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeminian <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 18:00:32 by aeminian          #+#    #+#             */
/*   Updated: 2024/04/18 20:19:13 by aeminian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sorted(t_stack *stack)
{
	while (stack->next != NULL)
	{
		if (stack->value < stack->next->value)
			stack = stack->next;
		else
			return (0);
	}
	free(stack);
	exit (0);
}

void	sort_a3(t_stack **a, int len_b)
{
	if ((*a)->index == len_b + 2)
	{
		ra(a);
		if ((*a)->index > (*a)->next->index)
			swap(*a, 'a');
	}
	else if ((*a)->index == len_b
		&& (*a)->next->index > (*a)->next->next->index)
	{
		rra(a);
		swap(*a, 'a');
	}
	else if ((*a)->index == len_b + 1)
	{
		if ((*a)->next->index > (*a)->next->next->index)
			rra(a);
		else
			swap(*a, 'a');
	}
}

void	sort_b3(t_stack **b)
{
	if ((*b)->index == 1)
	{
		if ((*b)->next->index > (*b)->next->next->index)
			swap(*b, 'b');
		else
			rrb(b);
	}
	else if ((*b)->index == 2
		&& (*b)->next->index < (*b)->next->next->index)
	{
		rrb(b);
		if ((*b)->index < (*b)->next->index)
			swap(*b, 'b');
	}
	else if ((*b)->index == 0)
	{
		rb(b);
		if ((*b)->index < (*b)->next->index)
			swap(*b, 'b');
	}
}

void	simple_sort(t_stack **a, t_stack **b)
{
	int	len;

	len = ft_lstsize(*a);
	while (ft_lstsize(*a) > 3 || min_in_a(*a, len))
	{
		if ((*a)->index >= len / 2)
			ra(a);
		else
			pb(a, b);
	}
	if (ft_lstsize(*a) == 2 && (*a)->index > (*a)->next->index)
		swap(*a, 'a');
	else if (ft_lstsize(*a) == 3)
		sort_a3(a, ft_lstsize(*b));
	if (ft_lstsize(*b) == 2 && (*b)->index < (*b)->next->index)
		swap(*b, 'b');
	else if (ft_lstsize(*b) == 3)
		sort_b3(b);
	while (ft_lstsize(*b) > 0)
		pa(b, a);
}

void	sorting(t_stack **stack)
{
	t_stack	*b;

	b = NULL;
	if (!stack)
		return ;
	is_sorted(*stack);
	if (ft_lstsize(*stack) <= 5)
		simple_sort(stack, &b);
	else
		butterfly(stack);
}
