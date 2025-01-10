/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_sorted.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcalero <lcalero@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 12:57:36 by lcalero           #+#    #+#             */
/*   Updated: 2025/01/10 12:39:26 by lcalero          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sorted(int *stack_a, int size_a)
{
	int	i;

	i = size_a - 1;
	while (i > 0)
	{
		if (stack_a[i] < stack_a[i - 1])
			return (0);
		i--;
	}
	return (1);
}
