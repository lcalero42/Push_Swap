/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_functions.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcalero <lcalero@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 15:26:26 by lcalero           #+#    #+#             */
/*   Updated: 2025/01/13 14:03:00 by lcalero          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*This function checks if the input contains duplicate
numbers, if it does, it frees the stack and returns an
error*/
void	check_duplicates(int *stack_a, int size_a)
{
	int	i;
	int	j;

	i = 0;
	j = i + 1;
	while (i < size_a)
	{
		while (j < size_a)
		{
			if (stack_a[i] == stack_a[j])
			{
				free(stack_a);
				print_error();
			}
			j++;
		}
		i++;
		j = i + 1;
	}
}

/*This function checks if the minus and plus 
are valid in the input (example : no single minus in
the input)*/
int	check_duplicates_minus_str(char *str)
{
	int	i;

	i = 0;
	if (!ft_strncmp(str, "-", ft_strlen(str))
		|| !ft_strncmp(str, "+", ft_strlen(str)))
		return (0);
	while (str[i])
	{
		if (str[i] == '-' || str[i] == '+')
			if (!ft_isdigit(str[i + 1]))
				return (0);
		if (ft_isdigit(str[i]) && (str[i + 1] == '-' || str[i + 1] == '+'))
			return (0);
		i++;
	}
	return (1);
}

/*This function processes the minus/plus checkings for
every arguments in entry*/
int	check_wrong_minus(int ac, char **av, int *stack_a)
{
	int	i;

	i = 0;
	while (i < ac)
	{
		if (!check_duplicates_minus_str(av[i]))
		{
			free(stack_a);
			print_error();
			return (0);
		}
		i++;
	}
	return (1);
}
