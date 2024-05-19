/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeminian <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 17:39:13 by aeminian          #+#    #+#             */
/*   Updated: 2024/04/22 16:24:29 by aeminian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdio.h>
# include <string.h>
# include <limits.h>
# include <unistd.h>
# include <stdlib.h>
# include "get_next_line.h"

/////////////////////////////STRUCT/////////////////////////////
typedef struct n_stack
{
	int				value;
	int				index;
	struct n_stack	*next;
}	t_stack;
////////////////////////////UTILS///////////////////////////////
long long	ft_atol(const char *str);
char		**ft_split(char const *s);
char		*ft_substr(char const *s, unsigned int start, size_t len);
void		malloc_check(void *str);
void		repetation_check(t_stack **stack);
void		init_stack(t_stack **stack1, int nbr);
void		parser(char **av, t_stack **stack1);
void		index_alt(t_stack **stack, int len);
void		error_handle(void);
int			integers_count(char **str);
int			check_arguments(char **str);
int			ft_lstsize(t_stack *stack);
int			max(t_stack *stack);
int			min(t_stack *stack);
int			max_index(t_stack *stack);
int			get_position(t_stack *stack, int max);
int			offset(int size);
size_t		ft_strlen(const char *s);
t_stack		*ft_lstlast(t_stack *stack);
t_stack		**validation(char **stack, t_stack **stack1);
void		dealoc(t_stack **stack);
void		overflow_check(char *nbr);
/////////////////////////////OPERATIONS/////////////////////////
void		rotate(t_stack **stack);
void		ra(t_stack **stack1);
void		rb(t_stack **stack1);
void		rr(t_stack **stack1, t_stack **stack2, char s);
void		swap(t_stack *stack, char specifier);
void		swap_both(t_stack *stack_a, t_stack *stack_b);
void		push(t_stack **stack_a, t_stack **stack_b);
void		pb(t_stack **stack_a, t_stack **stack_b);
void		pa(t_stack **stack_a, t_stack **stack_b);
void		reverse_rotate(t_stack **stack);
void		rrb(t_stack **stack);
void		rra(t_stack **stack);
void		rrr(t_stack **stack1, t_stack **stack2, char s);
/////////////////////////////SORTING////////////////////////////
void		sorting(t_stack **stack);
void		sort_in_a(t_stack **stack_a, t_stack *stack_b, int maxn, int n);
void		butterfly(t_stack **stack_a);
void		sort_a3(t_stack **a, int len_b);
void		sort_b3(t_stack **b);
void		simple_sort(t_stack **a, t_stack **b);
int			is_sorted(t_stack *stack);
int			min_in_a(t_stack *a, int len);
void		reverse_rotate(t_stack **a);
////////////////////////////BONUS///////////////////////////////
void		input_check(char *str, t_stack **a, t_stack **b);
int			ft_strcmp(const char *s1, const char *s2);
void		checker_validation(t_stack **stack_a, t_stack **stack_b);
int			is_sorted_checker(t_stack *stack);

#endif
