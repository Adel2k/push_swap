/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeminian <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 17:28:18 by aeminian          #+#    #+#             */
/*   Updated: 2024/04/22 16:23:36 by aeminian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	t_stack	*stack1;

	stack1 = NULL;
	if (ac <= 1)
		return (0);
	parser(av, &stack1);
	sorting(&stack1);
	dealoc(&stack1);
	free(stack1);
}
