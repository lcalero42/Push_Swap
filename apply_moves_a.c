/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_moves_a.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcalero <lcalero@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 16:35:45 by lcalero           #+#    #+#             */
/*   Updated: 2025/01/09 16:47:28 by lcalero          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "push_swap.h"
#include <stdio.h>

/*This function applies the right amount of rotation 
to the top of the stack to both stacks when pushing from b to a
to get the number treated in the correct position then push it*/
int	apply_rarb_a(int *stack_a, int *stack_b, int c, t_sizes *sizes)
{
	while (stack_b[0] != c && find_place_a(stack_a, sizes->a, c) > 0)
		rr(stack_a, stack_b, sizes->a, sizes->b);
	while (stack_b[0] != c)
		rb(stack_b, sizes->b);
	while (find_place_a(stack_a, sizes->a, c) > 0)
		ra(stack_a, sizes->a);
	pa(stack_a, stack_b, &sizes->a, &sizes->b);
	return (-1);
}

/*This function applies the right amount of rotation
to the bottom of the stack to both stacks when pushing from b to a
to get the number treated in the correct position then push it*/
int	apply_rrarrb_a(int *stack_a, int *stack_b, int c, t_sizes *sizes)
{
	while (stack_b[0] != c && find_place_a(stack_a, sizes->a, c) > 0)
		rrr(stack_a, stack_b, sizes->a, sizes->b);
	while (stack_b[0] != c)
		rrb(stack_b, sizes->b);
	while (find_place_a(stack_a, sizes->a, c) > 0)
		rra(stack_a, sizes->a);
	pa(stack_a, stack_b, &sizes->a, &sizes->b);
	return (-1);
}

/*This function applies the right amount of rotations in both senses to
a and b to get the number treated in the correct position then push it*/
int	apply_rrarb_a(int *stack_a, int *stack_b, int c, t_sizes *sizes)
{
	while (find_place_a(stack_a, sizes->a, c) > 0)
		rra(stack_a, sizes->a);
	while (stack_b[0] != c)
		rb(stack_b, sizes->b);
	pa(stack_a, stack_b, &sizes->a, &sizes->b);
	return (-1);
}

/*This function applies the right amount of rotations in both senses to
a and b to get the number treated in the correct position then push it*/
int	apply_rarrb_a(int *stack_a, int *stack_b, int c, t_sizes *sizes)
{
	while (find_place_a(stack_a, sizes->a, c) > 0)
		ra(stack_a, sizes->a);
	while (stack_b[0] != c)
		rrb(stack_b, sizes->b);
	pa(stack_a, stack_b, &sizes->a, &sizes->b);
	return (-1);
}
