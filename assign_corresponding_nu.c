/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assign_corresponding_nu.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcalero <lcalero@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 14:04:32 by lcalero           #+#    #+#             */
/*   Updated: 2024/12/18 15:25:38 by lcalero          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

static void swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

static void	copy_stack(int *stack_a, int size_a, int *cpy)
{
	int i;

	i = 0;
	while (i < size_a)
	{
		cpy[i] = stack_a[i];
		i++;
	}
}

static void sort_stack(int *stack, int size_a)
{
	int i;
	int	j;
	int	min;
	int index;

	i = 0;
	while (i < size_a)
	{
		min = stack[i];
		index = i;
		j = i + 1;
		while (j < size_a)
		{
			if (stack[j] < min)
			{
				min = stack[j];
				index = j;
			}
			j++;
		}
		if (index != i)
			swap(&stack[i], &stack[index]);
		i++;
	}
}

void	assign_corresponding_nu(int *stack_a, int size_a)
{
	int	i;
	int	j;
	int	*cpy;
	
	i = 0;
	cpy = (int*)malloc(sizeof(int) * size_a);
	if (!cpy)
		return ;
	copy_stack(stack_a, size_a, cpy);
	sort_stack(cpy, size_a);
	while (i < size_a)
	{
		j = 0;
		while (j < size_a)
		{
			if (stack_a[i] == cpy[j])
			{
				stack_a[i] = j;
				break ;
			}
			j++;
		}
		i++;
	}
	free(cpy);
}
