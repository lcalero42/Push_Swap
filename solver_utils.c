/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcalero <lcalero@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 14:03:06 by lcalero           #+#    #+#             */
/*   Updated: 2025/01/13 12:49:46 by lcalero          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*This function calculates the number of rotations(rarb) needed 
on stack_a and stack_b to be able to push c fro a to b*/
int	case_rarb(int *stack_a, int *stack_b, t_sizes sizes, int c)
{
	int	i;

	i = find_place(stack_b, sizes.b, c);
	if (i < find_index(stack_a, c))
		i = find_index(stack_a, c);
	return (i);
}

/*This function calculates the number of rotations(rrarrb) needed 
on stack_a and stack_b to be able to push c from a to b*/
int	case_rrarrb(int *stack_a, int *stack_b, t_sizes sizes, int c)
{
	int	i;

	i = 0;
	if (find_place(stack_b, sizes.b, c))
		i = sizes.b - find_place(stack_b, sizes.b, c);
	if ((i < (sizes.a - find_index(stack_a, c))) && find_index(stack_a, c))
		i = sizes.a - find_index(stack_a, c);
	return (i);
}

/*This function calculates the number of rotations(rrarb) needed 
on stack_a and stack_b to be able to push c from a to b*/
int	case_rrarb(int *stack_a, int *stack_b, t_sizes sizes, int c)
{
	int	i;

	i = 0;
	if (find_index(stack_a, c))
		i = sizes.a - find_index(stack_a, c);
	i = find_place(stack_b, sizes.b, c) + i;
	return (i);
}

/*This function calculates the number of rotations(rarrb) needed 
on stack_a and stack_b to be able to push c from a to b*/
int	case_rarrb(int *stack_a, int *stack_b, t_sizes sizes, int c)
{
	int	i;

	i = 0;
	if (find_place(stack_b, sizes.b, c))
		i = sizes.b - find_place(stack_b, sizes.b, c);
	i = find_index(stack_a, c) + i;
	return (i);
}
