/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcalero <lcalero@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 15:59:39 by lcalero           #+#    #+#             */
/*   Updated: 2024/12/19 15:39:41 by lcalero          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

void	print_stack(int *stack, int size)
{
	int i;
	
	i = size - 1;
	printf("----------------\n");
	while (i >= 0)
	{
		printf("%d\n", stack[i]);
		i--;
	}
	printf("----------------\n");
}

void	radix_sort(int *stack_a, int *stack_b, int size_a, int size_b)
{
	int	max_num;
	int	max_bits;
	int	num;
	int	i;
	int	j;
	int	size;

	max_num = size_a - 1;
	max_bits = 0;
	size = size_a;
	while ((max_num >> max_bits) != 0)
		max_bits++;
	i = max_bits - 1;
	while (i >= 0)
	{
		j = 0;
		while (j < size)
		{
			num = stack_a[size_a - 1];
			if (((num >> i) & 1) == 1)
				ra(stack_a, size_a);
			else
				pb(stack_a, stack_b, &size_a, &size_b);
			j++;
		}
		while (size_b > 0)
			pa(stack_a, stack_b, &size_a, &size_b);
		i--;
	}
}
