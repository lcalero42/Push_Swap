/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcalero <lcalero@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 17:29:26 by lcalero           #+#    #+#             */
/*   Updated: 2025/01/07 20:07:20 by lcalero          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

int	main(int ac, char **av)
{
	int		*stack_a;
	int		*stack_b;
	t_sizes	sizes;
	int	i = 0;

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
	reverse_array(stack_a, sizes.a);
	while (i < sizes.a)
	{
		printf("%d\n", stack_a[i]);
		i++;
	}
	i = 0;
	sort_three(stack_a);
	while (i < sizes.a)
	{
		printf("%d\n", stack_a[i]);
		i++;
	}
	free(stack_a);
	free(stack_b);
	return (0);
}
