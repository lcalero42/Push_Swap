/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcalero <lcalero@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 13:41:26 by lcalero           #+#    #+#             */
/*   Updated: 2025/01/07 20:16:45 by lcalero          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_min(int *stack, int size)
{
	int	i;
	int	min;

	i = 1;
	min = stack[0];
	while (i < size)
	{
		if (stack[i] < min)
			min = stack[i];
		i++;
	}
	return (min);
}

int	find_max(int *stack, int size)
{
	int	i;
	int	max;

	i = 1;
	max = stack[0];
	while (i < size)
	{
		if (stack[i] > max)
			max = stack[i];
		i++;
	}
	return (max);
}

int	find_index(int *stack, int c)
{
	int	i;

	i = 0;
	while (stack[i] != c)
		i++;
	return (i);
}

int	find_place(int *stack_b, int size_b, int c)
{
	int	i;

	i = size_b - 1;
	if (c > find_max(stack_b, size_b))
		return (find_index(stack_b, find_max(stack_b, size_b)) + 1);
	if (c < find_min(stack_b, size_b))
		return (find_index(stack_b, find_min(stack_b, size_b)));
	while (i > 0)
	{
		if (c > stack_b[i - 1] && c < stack_b[i])
			return (i);
		i--;
	}
	return (-1);
}

void	reverse_array(int *stack, int size)
{
	int	i;
	int	tmp;

	i = 0;
	while (i < size / 2)
	{
		tmp = stack[i];
		stack[i] = stack[size - i - 1];
		stack[size - i - 1] = tmp;
		i++;
	}
}
