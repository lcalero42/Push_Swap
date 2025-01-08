/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_moves_b.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcalero <lcalero@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 14:27:26 by lcalero           #+#    #+#             */
/*   Updated: 2025/01/08 17:52:24 by lcalero          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

/*This function applies the right amount of rotation 
to the top of the stack to both stacks when pushing from a to b
to get the number treated in the correct position then push it*/
void	apply_rarb_b(int *stack_a, int *stack_b, int c, t_sizes *sizes)
{
	while (stack_a[0] != c && find_place(stack_b, sizes->b, c) > 0)
		rr(stack_a, stack_b, sizes->a, sizes->b);
	while (stack_a[0] != c)
		ra(stack_a, sizes->a);
	while (find_place(stack_b, sizes->b, c) > 0)
		rb(stack_b, sizes->b);
	pb(stack_a, stack_b, &sizes->a, &sizes->b);
}

/*This function applies the right amount of rotation
to the bottom of the stack to both stacks when pushing from a to b
to get the number treated in the correct position then push it*/
void	apply_rrarrb_b(int *stack_a, int *stack_b, int c, t_sizes *sizes)
{
	while (stack_a[0] != c && find_place(stack_b, sizes->b, c) > 0)
		rrr(stack_a, stack_b, sizes->a, sizes->b);
	while (stack_a[0] != c)
		rra(stack_a, sizes->a);
	while (find_place(stack_b, sizes->b, c) > 0)
		rrb(stack_b, sizes->b);
	pb(stack_a, stack_b, &sizes->a, &sizes->b);
}

/*This function applies the right amount of rotations in both senses to
a and b to get the number treated in the correct position then push it*/
void	apply_rrarb_b(int *stack_a, int *stack_b, int c, t_sizes *sizes)
{
	while (stack_a[0] != c)
	{
		rra(stack_a, sizes->a);
	}
	while (find_place(stack_b, sizes->b, c) > 0)
		rb(stack_b, sizes->b);
	pb(stack_a, stack_b, &sizes->a, &sizes->b);
}

/*This function applies the right amount of rotations in both senses to
a and b to get the number treated in the correct position then push it*/
void	apply_rarrb_b(int *stack_a, int *stack_b, int c, t_sizes *sizes)
{
	while (stack_a[0] != c)
		ra(stack_a, sizes->a);
	while (find_place(stack_b, sizes->b, c) > 0)
		rrb(stack_b, sizes->b);
	pb(stack_a, stack_b, &sizes->a, &sizes->b);
}
