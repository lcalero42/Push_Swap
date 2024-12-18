/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcalero <lcalero@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 17:27:04 by lcalero           #+#    #+#             */
/*   Updated: 2024/12/18 14:43:11 by lcalero          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include "libft/libft.h"

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

int		check_duplicates(int *stack_a, int size_a);

int		check_duplicates_minus_str(char *str);

void	print_error(void);

int		check_wrong_minus(int ac, char **av);

int		count_num(char *str);

int		is_sorted(int ac, char **av);

void	assign_corresponding_nu(int *stack_a, int size_a);

#endif