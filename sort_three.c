/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcalero <lcalero@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 19:17:02 by lcalero           #+#    #+#             */
/*   Updated: 2025/01/09 19:20:14 by lcalero          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*This function sorts the stack_a when its size is
3, because the maximum amount of operation for 3
numbers in a stack is 2, so no need to apply
the turkish logic there*/
void	sort_three(int *stack)
{
	if (find_min(stack, 3) == stack[0])
	{
		rra(stack, 3);
		sa(stack, 3);
	}
	else if (find_max(stack, 3) == stack[0])
	{
		ra(stack, 3);
		if (!is_sorted(stack, 3))
			sa(stack, 3);
	}
	else
	{
		if (find_index(stack, find_max(stack, 3)) == 1)
			rra(stack, 3);
		else
			sa(stack, 3);
	}
}
