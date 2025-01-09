/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcalero <lcalero@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 16:51:06 by lcalero           #+#    #+#             */
/*   Updated: 2025/01/09 17:26:30 by lcalero          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

/*This function does all the sorting process and sort the min
if it does not end in the right position*/
void	sort(int *stack_a, int *stack_b, t_sizes *sizes)
{
	int	i;
	
	i = 0;
	if (sizes->a == 2)
		sa(stack_a, sizes->a);
	else
	{
		sort_b(stack_a, stack_b, sizes);
		sort_a(stack_a, stack_b, sizes);
		i = find_index(stack_a, find_min(stack_a, sizes->a));
		if (i < sizes->a - i)
		{
			while (stack_a[0] != find_min(stack_a, sizes->a))
				ra(stack_a, sizes->a);
		}
		else
		{
			while (stack_a[0] != find_min(stack_a, sizes->a))
				rra(stack_a, sizes->a);
		}
	}
}
