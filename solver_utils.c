/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcalero <lcalero@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 14:03:06 by lcalero           #+#    #+#             */
/*   Updated: 2025/01/09 15:30:57 by lcalero          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	case_rarb(int *stack_a, int *stack_b, t_sizes sizes, int c)
{
	int	i;

	i = find_place(stack_b, sizes.b, c);
	if (i < find_index(stack_a, c))
		i = find_index(stack_a, c);
	return (i);
}

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

int	case_rrarb(int *stack_a, int *stack_b, t_sizes sizes, int c)
{
	int	i;

	i = 0;
	if (find_index(stack_a, c))
		i = sizes.a - find_index(stack_a, c);
	i = find_place(stack_b, sizes.b, c) + i;
	return (i);
}

int	case_rarrb(int *stack_a, int *stack_b, t_sizes sizes, int c)
{
	int	i;

	i = 0;
	if (find_place(stack_b, sizes.b, c))
		i = sizes.b - find_place(stack_b, sizes.b, c);
	i = find_index(stack_a, c) + i;
	return (i);
}
