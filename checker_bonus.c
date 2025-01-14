/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcalero <lcalero@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 11:53:53 by lcalero           #+#    #+#             */
/*   Updated: 2025/01/14 12:14:43 by lcalero          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	check_move(char *str, int *a, int *b, t_sizes *sizes)
{
	if (!ft_strncmp("sa", str, 2))
		sa(a, sizes->a);
	else if (!ft_strncmp("sb", str, 2))
		sb(b, sizes->b);
	else if (!ft_strncmp("ss", str, 2))
		ss(a, b, sizes->a, sizes->b);
	else if (!ft_strncmp("ra", str, 2))
		ra(a, sizes->a);
	else if (!ft_strncmp("rb", str, 2))
		rb(b, sizes->b);
	else if (!ft_strncmp("rr", str, 2))
		rr(a, b, sizes->a, sizes->b);
	else if (!ft_strncmp("rra", str, 3))
		rra(a, sizes->a);
	else if (!ft_strncmp("rrb", str, 3))
		rrb(b, sizes->b);
	else if (!ft_strncmp("rrr", str, 3))
		rrr(a, b, sizes->a, sizes->b);
	else if (!ft_strncmp("pb", str, 2))
		pb(a, b, sizes->a, sizes->b);
	else if (!ft_strncmp("pa", str, 2))
		pa(a, b, sizes->a, sizes->b);
	else
		print_error();
}

void	apply_moves(int *a, int *b, t_sizes *sizes)
{
	char *line;

	while (*line)
	{
		line = get_next_line(0);
		check_move(line, a, b, sizes);
	}
	free(line);
}

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
	free(stack_a);
	free(stack_b);
}
