/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turkish_algorithm.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcalero <lcalero@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 15:51:20 by lcalero           #+#    #+#             */
/*   Updated: 2025/01/07 20:08:26 by lcalero          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

int	count_operations(int *stack_a, int *stack_b, t_sizes sizes)
{
	int	i;
	int	cpt;

	cpt = 0;
	i = sizes.a - 1;
	printf("%d\n", i);
	while (i >= 3)
	{
		cpt += case_rarb(stack_a, stack_b, sizes, stack_a[i]);
		printf("%d\n", cpt);
		i--;
	}
	return (1);
}

void	turkish_algorithm(int *stack_a, int *stack_b, t_sizes sizes)
{
	pb(stack_a, stack_b, &sizes.a, &sizes.b);
	pb(stack_a, stack_b, &sizes.a, &sizes.b);
	count_operations(stack_a, stack_b, sizes);
}
