/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcalero <lcalero@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 14:03:06 by lcalero           #+#    #+#             */
/*   Updated: 2025/01/07 15:41:46 by lcalero          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	case_rarb(int *stack_a, int *stack_b, t_sizes sizes, int c)
{
	int	i;

	i = (sizes.b - 1) - find_place(stack_b, sizes.b, c);
	if (sizes.a - find_index(stack_a, c) < i)
		i = sizes.a - find_index(stack_a, c);
	return (i);
}
