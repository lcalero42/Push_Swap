/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcalero <lcalero@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 18:05:50 by lcalero           #+#    #+#             */
/*   Updated: 2024/12/19 01:14:01 by lcalero          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

static int	is_num(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (!(ft_isdigit(str[i]) || (str[i] == '-' || str[i] == '+') || str[i] == ' '))
			return (0);
		i++;
	}
	return (1);
}

static int	av_len(char **av)
{
	int	i;

	i = 0;
	while (av[i])
		i++;
	return (i);
}

static int	*parse_single_str(char **av, int *size)
{
	int	len;
	int	*stack_a;
	
	av = ft_split(av[1], ' ');
	len = av_len(av);
	*size = len;
	stack_a = malloc(len * sizeof(int));
	if (!stack_a)
		return (NULL);
	len--;
	while (len >= 0)
	{
		stack_a[len] = ft_atoi(av[len]);
		len--;
	}
	return stack_a;
}

int	*parse_input(int ac, char **av, int *size)
{
	int	i;
	int	j;
	int	*stack_a;

	if (ac == 2)
		return (parse_single_str(av, size));
	stack_a = malloc((ac - 1) * sizeof(int));
	if (!stack_a)
		return (NULL);
	*size = ac - 1;
	i = ac - 1;
	j = ac - 2;
	while (i > 1)
	{
		if (!is_num(av[i]))
			return (free(stack_a), print_error(), NULL);
		stack_a[j] = ft_atoi(av[i]);
		j--;
		i--;
	}
	return (stack_a);
}
