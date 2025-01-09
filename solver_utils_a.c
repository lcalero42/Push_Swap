/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver_utils_a.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcalero <lcalero@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 15:52:35 by lcalero           #+#    #+#             */
/*   Updated: 2025/01/09 16:50:07 by lcalero          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*This function calculates the number of rotations(rarb) needed 
on stack_a and stack_b to be able to push c*/
int case_rarb_a(int *stack_a, int *stack_b, t_sizes sizes, int c)
{
	int	i;

	i = find_place_a(stack_a, sizes.a, c);
	if (i < find_index(stack_b, c))
		i = find_index(stack_b, c);
	return (i);
}

/*This function calculates the number of rotations(rrarrb) needed 
on stack_a and stack_b to be able to push c*/
int	case_rrarrb_a(int *stack_a, int *stack_b, t_sizes sizes, int c)
{
	int	i;

	i = 0;
	if (find_place_a(stack_a, sizes.a, c))
		i = sizes.a - find_place_a(stack_a, sizes.a, c);
	if ((i < (sizes.b - find_index(stack_b, c))) && find_index(stack_b, c))
		i = sizes.b - find_index(stack_b, c);
	return (i);
}

/*This function calculates the number of rotations(rrarb) needed 
on stack_a and stack_b to be able to push c*/
int	case_rrarb_a(int *stack_a, int *stack_b, t_sizes sizes, int c)
{
	int	i;

	i = 0;
	if (find_index(stack_b, c))
		i = sizes.b - find_index(stack_b, c);
	i = find_place_a(stack_a, sizes.a, c) + i;
	return (i);
}

/*This function calculates the number of rotations(rarrb) needed 
on stack_a and stack_b to be able to push c*/
int	case_rarrb_a(int *stack_a, int *stack_b, t_sizes sizes, int c)
{
	int	i;

	i = 0;
	if (find_place_a(stack_a, sizes.a, c))
		i = sizes.a - find_place_a(stack_a, sizes.a, c);
	i = find_index(stack_b, c) + i;
	return (i);
}
