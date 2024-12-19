/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcalero <lcalero@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 17:29:26 by lcalero           #+#    #+#             */
/*   Updated: 2024/12/19 00:51:20 by lcalero          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

int	main(int ac, char **av)
{
	int	*stack_a;
	int	*stack_b;
	int	size_a;
	int	size_b;

	size_a = 0;
	stack_a = parse_input(ac, av, &size_a);
	if (!stack_a || !check_duplicates(stack_a, size_a) || !size_a
		|| !check_wrong_minus(ac, av))
		print_error();
	if (is_sorted(ac, av))
		return (0);
	stack_b = malloc(size_a * sizeof(int));
	if (!stack_b)
		return (1);
	size_b = 0;
	assign_corresponding_nu(stack_a, size_a);
	radix_sort(stack_a, stack_b, size_a, size_b);
	for (int i = 0; i < size_a; i++)
		printf("%d\n", stack_a[i]);
	free(stack_a);
	free(stack_b);
	return (0);
}
