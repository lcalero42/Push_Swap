/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcalero <lcalero@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 18:05:50 by lcalero           #+#    #+#             */
/*   Updated: 2025/01/14 16:42:58 by lcalero          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*This function checks if the string in
input is a number or not*/
static int	is_num(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (!(ft_isdigit(str[i]) || (str[i] == '-'
					|| str[i] == '+') || str[i] == ' '))
			return (0);
		i++;
	}
	return (1);
}

/*This function returns the length of a 2D
string*/
static int	av_len(char **av)
{
	int	i;

	i = 0;
	while (av[i])
		i++;
	return (i);
}

/*This function correctly frees all the elements
of a 2D string*/
void	ft_free(char **av, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		free(av[i]);
		i++;
	}
	free(av);
}

/*This function processes all the parsing logic
when the parameter is only on string by running
through the string and storing in stack_a the value
that atoi returns when we cross a number*/
static int	*parse_single_str(char **av, int *size)
{
	int	i;
	int	*stack_a;

	av = ft_split(av[1], ' ');
	if (!av)
		return (NULL);
	*size = av_len(av);
	stack_a = malloc(*size * sizeof(int));
	if (!stack_a)
		return (ft_free(av, *size), NULL);
	if (!(*size))
		return (free(stack_a), ft_free(av, *size), print_error(), NULL);
	i = 0;
	while (i < *size)
	{
		if (!is_num(av[i]) || !av[i][0])
			return (free(stack_a), ft_free(av, *size), print_error(), NULL);
		stack_a[i] = ft_atoi(av[i], stack_a);
		i++;
	}
	check_wrong_minus(*size, av, stack_a, 1);
	ft_free(av, *size);
	check_duplicates(stack_a, *size);
	return (stack_a);
}

/*This function processes all the parsing logic
by running through all the arguments and storing in
stack_a the value that atoi returns*/
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
	i = 1;
	j = 0;
	while (i < ac)
	{
		if (!is_num(av[i]))
			return (free(stack_a), print_error(), NULL);
		stack_a[j] = ft_atoi(av[i], stack_a);
		j++;
		i++;
	}
	check_wrong_minus(ac, av, stack_a, 0);
	check_duplicates(stack_a, *size);
	return (stack_a);
}
