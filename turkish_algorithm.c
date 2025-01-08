/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turkish_algorithm.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcalero <lcalero@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 15:51:20 by lcalero           #+#    #+#             */
/*   Updated: 2025/01/08 12:21:51 by lcalero          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

int	determin_rotations(int *stack_a, int *stack_b, t_sizes sizes, int c)
{
	int	i;
	int	min;

	i = 0;
	min = case_rarb(stack_a, stack_b, sizes, c);
	if (case_rarb(stack_a, stack_b, sizes, c) < min)
	{
		printf("chose rarb\n");
		min = case_rarb(stack_a, stack_b, sizes, c);
	}
	if (case_rrarrb(stack_a, stack_b, sizes, c) < min)
	{
		printf("chose rrarrb\n");
		min = case_rrarrb(stack_a, stack_b, sizes, c);
	}
	if (case_rarrb(stack_a, stack_b, sizes, c) < min)
	{
		printf("chose rarrb\n");
		min = case_rarrb(stack_a, stack_b, sizes, c);
	}
	if (case_rrarb(stack_a, stack_b, sizes, c) < min)
	{
		printf("chose rrarb\n");
		min = case_rrarb(stack_a, stack_b, sizes, c);
	}
	i++;
	return (min);
}

int	count_operations(int *stack_a, int *stack_b, t_sizes sizes)
{
	int	i;
	int	rotate_num;
	int	cpt;
	int	min;
	int number;

	rotate_num = 0;
	cpt = 0;
	i = 0;
	min = 0;
	number = stack_a[0];
	while (i < sizes.a)
	{
		rotate_num = determin_rotations(stack_a, stack_b, sizes, stack_a[i]);
		cpt += rotate_num; //counting rotations
		cpt++;
		if (i == 0 || cpt < min)
		{
			number = stack_a[i];
			min = cpt;
		}
		printf("number : %d -- operations : %d\n", stack_a[i], cpt);
		cpt = 0;
		i++;
	}
	printf("--cheapest-- : %d", number);
	return (1);
}

void	turkish_algorithm(int *stack_a, int *stack_b, t_sizes sizes)
{
	pb(stack_a, stack_b, &sizes.a, &sizes.b);
	pb(stack_a, stack_b, &sizes.a, &sizes.b);
	count_operations(stack_a, stack_b, sizes);
}
