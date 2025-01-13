/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcalero <lcalero@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 13:41:26 by lcalero           #+#    #+#             */
/*   Updated: 2025/01/13 14:02:36 by lcalero          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*This function finds the minimum number in a 
given stack and return this number*/
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

/*This function finds the maximum number in a 
given stack and return this number*/
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

/*This function returns the index of a 
given number in a stack*/
int	find_index(int *stack, int c)
{
	int	i;

	i = 0;
	while (stack[i] != c)
		i++;
	return (i);
}

/*This function finds the place where the nbrpushed should
be in stack_b (above the maximum in stack_b if the number
is a minimum or maximum and between a smaller and bigger
number for a regular number)*/
int	find_place(int *array_b, int size_b, int nbrpushed)
{
	int	i;
	int	index;

	i = 0;
	index = 1;
	if (size_b <= 0)
		return (0);
	if (nbrpushed > array_b[i] && nbrpushed < array_b[size_b - 1])
		index = 0;
	else if (nbrpushed > find_max(array_b, size_b)
		|| nbrpushed < find_min(array_b, size_b))
		index = find_index(array_b, find_max(array_b, size_b));
	else
	{
		while (array_b[i] < nbrpushed || array_b[i + 1] > nbrpushed)
		{
			index++;
			i++;
		}
	}
	return (index);
}

/*This function finds the place where the nbrpushed should
be in stack_a (above the minimum in stack_a if the number
is a minimum or maximum and between a smaller and bigger
number for a regular number)*/
int	find_place_a(int *array_a, int size_a, int nbrpushed)
{
	int	i;
	int	index;

	i = 0;
	index = 1;
	if (size_a <= 0)
		return (0);
	if (nbrpushed < array_a[i] && nbrpushed > array_a[size_a - 1])
		index = 0;
	else if (nbrpushed > find_max(array_a, size_a)
		|| nbrpushed < find_min(array_a, size_a))
		index = find_index(array_a, find_min(array_a, size_a));
	else
	{
		while (array_a[i] > nbrpushed || array_a[i + 1] < nbrpushed)
		{
			index++;
			i++;
		}
	}
	return (index);
}
