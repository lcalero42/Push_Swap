/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcalero <lcalero@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 17:27:04 by lcalero           #+#    #+#             */
/*   Updated: 2025/01/07 19:23:13 by lcalero          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include "libft/libft.h"

typedef struct s_sizes
{
	int	a;
	int	b;
}	t_sizes;

int		*parse_input(int ac, char **av, int *size);

void	sa(int *stack_a, int size);

void	sb(int *stack_b, int size);

void	ss(int *stack_a, int *stack_b, int size_a, int size_b);

void	pa(int *stack_a, int *stack_b, int *size_a, int *size_b);

void	pb(int *stack_a, int *stack_b, int *size_a, int *size_b);

void	ra(int *stack_a, int size_a);

void	rra(int *stack_a, int size_a);

void	rrb(int *stack_b, int size_b);

void	rrr(int *stack_a, int *stack_b, int size_a, int size_b);

void	check_duplicates(int *stack_a, int size_a);

int		check_duplicates_minus_str(char *str);

void	print_error(void);

void	print_error_free(int *stack_a);

int		check_wrong_minus(int ac, char **av, int *stack_a);

int		is_sorted(int *stack_a, int size_a);

void	turkish_algorithm(int *stack_a, int *stack_b, t_sizes sizes);

int		find_min(int *stack, int size);

int		find_max(int *stack, int size);

int		find_place(int *stack_b, int size_b, int c);

int		find_index(int *stack, int c);

int		case_rarb(int *stack_a, int *stack_b, t_sizes sizes, int c);

void	reverse_array(int *stack, int size);

void    sort_three(int *stack);

#endif