/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcalero <lcalero@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 11:53:53 by lcalero           #+#    #+#             */
/*   Updated: 2025/01/17 14:51:11 by lcalero          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*This fuction checks which move has been written and must be
processed for the line in parameter. It also returns the next
line to check*/
static char	*check_move(char *str, int *a, int *b, t_sizes *sizes)
{
	if (!ft_strncmp("sa\n", str, ft_strlen(str)))
		sa_2(a, sizes->a);
	else if (!ft_strncmp("sb\n", str, ft_strlen(str)))
		sb_2(b, sizes->b);
	else if (!ft_strncmp("ss\n", str, ft_strlen(str)))
		ss_2(a, b, sizes->a, sizes->b);
	else if (!ft_strncmp("ra\n", str, ft_strlen(str)))
		ra_2(a, sizes->a);
	else if (!ft_strncmp("rb\n", str, ft_strlen(str)))
		rb_2(b, sizes->b);
	else if (!ft_strncmp("rr\n", str, ft_strlen(str)))
		rr_2(a, b, sizes->a, sizes->b);
	else if (!ft_strncmp("rra\n", str, ft_strlen(str)))
		rra_2(a, sizes->a);
	else if (!ft_strncmp("rrb\n", str, ft_strlen(str)))
		rrb_2(b, sizes->b);
	else if (!ft_strncmp("rrr\n", str, ft_strlen(str)))
		rrr_2(a, b, sizes->a, sizes->b);
	else if (!ft_strncmp("pb\n", str, ft_strlen(str)))
		pb_2(a, b, &sizes->a, &sizes->b);
	else if (!ft_strncmp("pa\n", str, ft_strlen(str)))
		pa_2(a, b, &sizes->a, &sizes->b);
	else
		print_error();
	return (get_next_line(0));
}

/*This function checks each time which move to apply to the line
that is being processed and applies it. It also checks at the end
if the commands sorted the stacks correctly*/
static void	apply_moves(int *a, int *b, t_sizes *sizes)
{
	char	*line;
	char	*tmp;

	line = get_next_line(0);
	while (line && *line != '\n')
	{
		tmp = line;
		line = check_move(line, a, b, sizes);
		free(tmp);
	}
	if (is_sorted(a, sizes->a) && !sizes->b)
		ft_putstr_fd("OK\n", 1);
	else
		ft_putstr_fd("KO\n", 1);
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
	stack_b = malloc(sizes.a * sizeof(int));
	if (!stack_b)
		return (1);
	sizes.b = 0;
	apply_moves(stack_a, stack_b, &sizes);
	free(stack_a);
	free(stack_b);
}
