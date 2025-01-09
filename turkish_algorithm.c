/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turkish_algorithm.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcalero <lcalero@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 15:51:20 by lcalero           #+#    #+#             */
/*   Updated: 2025/01/09 19:13:35 by lcalero          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*This function returns the amount of rotation minimum 
that is needed to put the number we are checking at the top of
the stack_a*/
static int	determin_rotations_b(int *stack_a, int *stack_b, t_sizes sizes)
{
	int	i;
	int	min;

	i = 0;
	min = case_rrarrb(stack_a, stack_b, sizes, stack_a[i]);
	while (i < sizes.a)
	{
		if (min > case_rarb(stack_a, stack_b, sizes, stack_a[i]))
			min = case_rarb(stack_a, stack_b, sizes, stack_a[i]);
		if (min > case_rrarrb(stack_a, stack_b, sizes, stack_a[i]))
			min = case_rrarrb(stack_a, stack_b, sizes, stack_a[i]);
		if (min > case_rarrb(stack_a, stack_b, sizes, stack_a[i]))
			min = case_rarrb(stack_a, stack_b, sizes, stack_a[i]);
		if (min > case_rrarb(stack_a, stack_b, sizes, stack_a[i]))
			min = case_rrarb(stack_a, stack_b, sizes, stack_a[i]);
		i++;
	}
	return (min);
}

/*This function returns the amount of rotation minimum 
that is needed to put the number we are checking at the top of
the stack_a*/
static int	determin_rotations_a(int *stack_a, int *stack_b, t_sizes sizes)
{
	int	i;
	int	min;

	i = 0;
	min = case_rrarrb_a(stack_a, stack_b, sizes, stack_b[i]);
	while (i < sizes.a)
	{
		if (min > case_rarb_a(stack_a, stack_b, sizes, stack_b[i]))
			min = case_rarb_a(stack_a, stack_b, sizes, stack_b[i]);
		if (min > case_rrarrb_a(stack_a, stack_b, sizes, stack_b[i]))
			min = case_rrarrb_a(stack_a, stack_b, sizes, stack_b[i]);
		if (min > case_rarrb_a(stack_a, stack_b, sizes, stack_b[i]))
			min = case_rarrb_a(stack_a, stack_b, sizes, stack_b[i]);
		if (min > case_rrarb_a(stack_a, stack_b, sizes, stack_b[i]))
			min = case_rrarb_a(stack_a, stack_b, sizes, stack_b[i]);
		i++;
	}
	return (min);
}

/*This function will sort all the numbers of stack_a into stack_b
by calculating operations for each number of stack_a to find the 
number that requires the least amount of operations*/
void	turkish_algorithm_b(int *stack_a, int *stack_b, t_sizes *sizes)
{
	int	i;
	int	j;

	while (sizes->a > 3)
	{
		j = 0;
		i = determin_rotations_b(stack_a, stack_b, *sizes);
		while (i >= 0)
		{
			if (i == case_rarb(stack_a, stack_b, *sizes, stack_a[j]))
				i = apply_rarb_b(stack_a, stack_b, stack_a[j], sizes);
			else if (i == case_rrarrb(stack_a, stack_b, *sizes, stack_a[j]))
				i = apply_rrarrb_b(stack_a, stack_b, stack_a[j], sizes);
			else if (i == case_rrarb(stack_a, stack_b, *sizes, stack_a[j]))
				i = apply_rrarb_b(stack_a, stack_b, stack_a[j], sizes);
			else if (i == case_rarrb(stack_a, stack_b, *sizes, stack_a[j]))
				i = apply_rarrb_b(stack_a, stack_b, stack_a[j], sizes);
			else
				j++;
		}
	}
}

/*This function will sort all the numbers of stack_b into stack_a
by calculating operations for each number of stack_b to find the 
number that requires the least amount of operations*/
void	sort_a(int *stack_a, int *stack_b, t_sizes *sizes)
{
	int	i;
	int	j;

	while (sizes->b > 0)
	{
		j = 0;
		i = determin_rotations_a(stack_a, stack_b, *sizes);
		while (i >= 0)
		{
			if (i == case_rarb_a(stack_a, stack_b, *sizes, stack_b[j]))
				i = apply_rarb_a(stack_a, stack_b, stack_b[j], sizes);
			else if (i == case_rrarrb_a(stack_a, stack_b, *sizes, stack_b[j]))
				i = apply_rrarrb_a(stack_a, stack_b, stack_b[j], sizes);
			else if (i == case_rrarb_a(stack_a, stack_b, *sizes, stack_b[j]))
				i = apply_rrarb_a(stack_a, stack_b, stack_b[j], sizes);
			else if (i == case_rarrb_a(stack_a, stack_b, *sizes, stack_b[j]))
				i = apply_rarrb_a(stack_a, stack_b, stack_b[j], sizes);
			else
				j++;
		}
	}
}

/*This function processes all the sorting algorithms needed 
on stack_b*/
void	sort_b(int *stack_a, int *stack_b, t_sizes *sizes)
{
	if (sizes->a > 3 && !is_sorted(stack_a, sizes->a))
		pb(stack_a, stack_b, &sizes->a, &sizes->b);
	if (sizes->a > 3 && !is_sorted(stack_a, sizes->a))
		pb(stack_a, stack_b, &sizes->a, &sizes->b);
	if (sizes->a > 3 && !is_sorted(stack_a, sizes->a))
		turkish_algorithm_b(stack_a, stack_b, sizes);
	if (sizes->a == 3 && !is_sorted(stack_a, sizes->a))
		sort_three(stack_a);
}
