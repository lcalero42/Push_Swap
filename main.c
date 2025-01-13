/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcalero <lcalero@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 17:29:26 by lcalero           #+#    #+#             */
/*   Updated: 2025/01/13 14:03:23 by lcalero          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	int		*stack_a;
	int		*stack_b;
	t_sizes	sizes;

	if (ac == 1)
		return (1);
	sizes.a = 0;
	stack_a = parse_input(ac, av, &sizes.a);
	if (!stack_a || !sizes.a)
		return (1);
	if (is_sorted(stack_a, sizes.a))
		return (free(stack_a), 0);
	stack_b = malloc(sizes.a * sizeof(int));
	if (!stack_b)
		return (1);
	sizes.b = 0;
	sort(stack_a, stack_b, &sizes);
	free(stack_a);
	free(stack_b);
	return (0);
}
