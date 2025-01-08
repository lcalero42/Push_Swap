/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turkish_algorithm.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcalero <lcalero@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 15:51:20 by lcalero           #+#    #+#             */
/*   Updated: 2025/01/08 18:27:21 by lcalero          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

/*This function returns the amount of rotation minimum 
that is needed to put the number we are checking at the top of
the stack_a*/
int	determin_rotations(int *stack_a, int *stack_b, t_sizes sizes, int c)
{
	int	min;

	min = case_rarb(stack_a, stack_b, sizes, c);
	if (case_rarb(stack_a, stack_b, sizes, c) < min)
		min = case_rarb(stack_a, stack_b, sizes, c);
	if (case_rrarrb(stack_a, stack_b, sizes, c) < min)
		min = case_rrarrb(stack_a, stack_b, sizes, c);
	if (case_rarrb(stack_a, stack_b, sizes, c) < min)
		min = case_rarrb(stack_a, stack_b, sizes, c);
	if (case_rrarb(stack_a, stack_b, sizes, c) < min)
		min = case_rrarb(stack_a, stack_b, sizes, c);
	return (min);
}

/* This function calculates all the rotations needed
for each number in stack_a and returns the number that
needs the least amount of operation to set it correctly
in stack_b */
int	count_operations(int *stack_a, int *stack_b, t_sizes sizes)
{
	int	i;
	int	rotate_num;
	int	min;
	int	cpt;
	int	number;

	rotate_num = 0;
	cpt = 0;
	i = 0;
	min = 0;
	number = stack_a[0];
	while (i < sizes.a)
	{
		rotate_num = determin_rotations(stack_a, stack_b, sizes, stack_a[i]);
		cpt += rotate_num;
		cpt = cpt + 1;
		if (i == 0 || cpt < min)
		{
			number = stack_a[i];
			min = cpt;
		}
		//printf("number : %d -- operations : %d\n", stack_a[i], cpt);
		cpt = 0;
		i++;
	}
	//printf("--cheapest-- : %d", number);
	return (number);
}
/*This function will sort all the numbers of stack_a into stack_b
by calculating operations for each number of stack_a to find the 
numbers that requires the least amount of operations*/
void	turkish_algorithm(int *stack_a, int *stack_b, t_sizes *sizes)
{
	int	i;
	int	num;

	i = 0;
	pb(stack_a, stack_b, &sizes->a, &sizes->b);
	pb(stack_a, stack_b, &sizes->a, &sizes->b);
	while (sizes->a > 3)
	{
		num = count_operations(stack_a, stack_b, *sizes);
		printf("num : %d\n", num);
		if (determin_rotations(stack_a, stack_b, *sizes, num) == case_rarb(stack_a, stack_b, *sizes, num))
			apply_rarb_b(stack_a, stack_b, num, sizes);
		else if (determin_rotations(stack_a, stack_b, *sizes, num) == case_rrarrb(stack_a, stack_b, *sizes, num))
			apply_rrarrb_b(stack_a, stack_b, num, sizes);
		else if (determin_rotations(stack_a, stack_b, *sizes, num) == case_rrarb(stack_a, stack_b, *sizes, num))
			apply_rrarb_b(stack_a, stack_b, num, sizes);
		else if (determin_rotations(stack_a, stack_b, *sizes, num) == case_rarrb(stack_a, stack_b, *sizes, num))
			apply_rarrb_b(stack_a, stack_b, num, sizes);
	}
}
