/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcalero <lcalero@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 17:29:26 by lcalero           #+#    #+#             */
/*   Updated: 2025/01/06 13:46:54 by lcalero          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

int	main(int ac, char **av)
{
	int	*stack_a;
	int	*stack_b;
	int	size_a;

	size_a = 0;
	stack_a = parse_input(ac, av, &size_a);
	if (!stack_a || !size_a)
		return (1);
	if (is_sorted(stack_a, size_a))
		return (free(stack_a), 0);
	stack_b = malloc(size_a * sizeof(int));
	if (!stack_b)
		return (1);
	printf("%d\n", find_max(stack_a, size_a));
	free(stack_a);
	free(stack_b);
	return (0);
}
