/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcalero <lcalero@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 18:05:50 by lcalero           #+#    #+#             */
/*   Updated: 2024/12/13 11:31:28 by lcalero          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

static int	count_num(char *str)
{
	int		i;
	int		cpt;

	i = 0;
	cpt = 0;
	while (str[i])
	{
		while (str[i] == ' ' && str[i])
			i++;
		if (str[i] == '\0')
			break ;
		cpt++;
		while (str[i] != ' ' && str[i])
			i++;
	}
	return (cpt);
}

static int	is_num(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (!((str[i] >= '0' && str[i] <= '9')
				|| (str[i] == '-' || str[i] == '+')))
			return (0);
		i++;
	}
	return (1);
}

static int	is_num_space(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (!((str[i] >= '0' && str[i] <= '9')
				|| (str[i] == '-' || str[i] == '+') || str[i] == ' '))
			return (0);
		i++;
	}
	return (1);
}

static int	*parse_single_string(char *str, int *size)
{
	int	i;
	int	j;
	int	*stack_a;

	if (!is_num_space(str))
		return (ft_putstr_fd("Error", 2), NULL);
	stack_a = malloc(count_num(str) * sizeof(int));
	if (!stack_a)
		return (NULL);
	*size = count_num(str);
	i = 0;
	j = 0;
	while (str[i])
	{
		while (str[i] == ' ')
			i++;
		if (!str[i])
			break ;
		stack_a[j] = ft_atoi(str + i);
		j++;
		while (str[i] && str[i] != ' ')
			i++;
	}
	return (stack_a);
}

int	*parse_input(int ac, char **av, int *size)
{
	int	i;
	int	j;
	int	*stack_a;

	if (ac == 2)
		return (parse_single_string(av[1], size));
	if (ac < 2)
		return (NULL);
	stack_a = malloc((ac - 1) * sizeof(int));
	if (!stack_a)
		return (NULL);
	*size = ac - 1;
	i = 1;
	j = 0;
	while (i < ac)
	{
		if (!is_num(av[i]))
			return (ft_putstr_fd("Error", 2), free(stack_a), NULL);
		stack_a[j] = ft_atoi(av[i]);
		j++;
		i++;
	}
	return (stack_a);
}
