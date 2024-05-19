/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeminian <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 16:16:44 by aeminian          #+#    #+#             */
/*   Updated: 2024/04/22 16:23:18 by aeminian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sorted_checker(t_stack *stack)
{
	while (stack->next != NULL)
	{
		if (stack->value < stack->next->value)
			stack = stack->next;
		else
			return (0);
	}
	return (1);
	free(stack);
}

int	ft_strcmp(const char *s1, const char *s2)
{
	while (*s1 && *s2 && *s1 == *s2)
	{
		s1++;
		s2++;
	}
	return ((unsigned char)*s1 - (unsigned char)*s2);
}

void	input_check(char *str, t_stack **a, t_stack **b)
{
	if (str == NULL)
		return ;
	else if (ft_strcmp(str, "ra\n") == 0)
		rotate(a);
	else if (ft_strcmp(str, "rb\n") == 0)
		rotate(b);
	else if (ft_strcmp(str, "rr\n") == 0)
		rrr(a, b, 'B');
	else if (ft_strcmp(str, "pb\n") == 0)
		push(a, b);
	else if (ft_strcmp(str, "pa\n") == 0)
		push(b, a);
	else if (ft_strcmp(str, "rra\n") == 0)
		reverse_rotate(a);
	else if (ft_strcmp(str, "rrb\n") == 0)
		reverse_rotate(b);
	else if (ft_strcmp(str, "rrr\n") == 0)
		rrr(a, b, 'B');
	else if (ft_strcmp(str, "sa\n") == 0)
		swap(*a, 'B');
	else if (ft_strcmp(str, "sb\n") == 0 || ft_strcmp(str, "ss\n") == 0)
		swap(*b, 'B');
	else
		error_handle();
}

void	checker_validation(t_stack **stack_a, t_stack **stack_b)
{
	char	*input;

	while (1)
	{
		input = get_next_line(0);
		input_check(input, stack_a, stack_b);
		if (input == 0)
			break ;
		free(input);
	}
	if (is_sorted_checker(*stack_a) && !*stack_b)
		write(1, "OK\n", 3);
	else
	{
		if (*stack_b)
		{
			dealoc(stack_b);
			free(*stack_b);
		}
		write(1, "KO\n", 3);
	}
}

int	main(int ac, char **av)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	if (ac == 1 || (ac == 2 && !av[1][0]))
		return (0);
	stack_a = NULL;
	stack_b = NULL;
	parser(av, &stack_a);
	checker_validation(&stack_a, &stack_b);
	dealoc(&stack_a);
	free(stack_a);
}
