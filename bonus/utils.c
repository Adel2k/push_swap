/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeminian <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 17:41:43 by aeminian          #+#    #+#             */
/*   Updated: 2024/04/13 13:11:55 by aeminian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	integers_count(char **str)
{
	int	i;

	i = 0;
	if (!str || !str[i])
		return (0);
	while (str[i])
		i++;
	return (i);
}

long long	ft_atol(const char *str)
{
	int			i;
	int			sign;
	long long	numb;

	i = 0;
	numb = 0;
	sign = 1;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if ((str[i] == '+' || str[i] == '-'))
	{
		if (str[i + 1] == 0)
			error_handle();
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
		numb = (numb * 10) + (str[i++] - '0');
	numb = numb * sign;
	if (numb > INT_MAX || numb < INT_MIN)
		error_handle();
	return (numb);
}

void	overflow_check(char *nbr)
{
	int	i;
	int	j;

	i = 0;
	if (nbr[i] == '-' || nbr[i] == '+')
		i++;
	while (nbr[i] == '0')
		i++;
	j = 0;
	while (nbr[i])
	{
		if (nbr[i] == 0)
			break;
		j++;
		i++;
	}
	if (j > 11)
		error_handle();
	else
		return ;
}

size_t	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	if (str == NULL)
		return (0);
	while (str[i])
		i++;
	return (i);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;
	char	*ptr;

	if (!s)
		return (NULL);
	else if ((start >= ft_strlen(s)))
		len = 0;
	else if (len > (ft_strlen(s) - start))
		len = ft_strlen(s) - start;
	str = (char *)malloc(len + 1);
	if (!str)
		return (NULL);
	s += start;
	ptr = str;
	*(str + len) = '\0';
	while (len-- && *s)
		*str++ = *s++;
	return (ptr);
}
