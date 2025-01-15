/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcalero <lcalero@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 17:27:04 by lcalero           #+#    #+#             */
/*   Updated: 2025/01/15 13:41:10 by lcalero          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"

//struct for sizes of stacks
typedef struct s_sizes
{
	int	a;
	int	b;
}	t_sizes;

//operations
void	sa(int *stack_a, int size);

void	sb(int *stack_b, int size);

void	ss(int *stack_a, int *stack_b, int size_a, int size_b);

void	pa(int *stack_a, int *stack_b, int *size_a, int *size_b);

void	pb(int *stack_a, int *stack_b, int *size_a, int *size_b);

void	ra(int *stack_a, int size_a);

void	rb(int *stack_b, int size_b);

void	rra(int *stack_a, int size_a);

void	rrb(int *stack_b, int size_b);

void	rr(int *stack_a, int *stack_b, int size_a, int size_b);

void	rrr(int *stack_a, int *stack_b, int size_a, int size_b);

//parsing functions
int		*parse_input(int ac, char **av, int *size);

void	check_duplicates(int *stack_a, int size_a);

int		check_duplicates_minus_str(char *str);

void	print_error(void);

void	print_error_free(int *stack_a);

int		check_wrong_minus(int ac, char **av, int *stack_a, int single);

void	ft_free(char **av, int size);

int		countnum(char *argv);

//algorithm utils
int		is_sorted(int *stack_a, int size_a);

void	turkish_algorithm(int *stack_a, int *stack_b, t_sizes *sizes);

int		find_min(int *stack, int size);

int		find_max(int *stack, int size);

int		find_place(int *array_b, int size_b, int nbrpushed);

int		find_place_a(int *array_a, int size_a, int nbrpushed);

int		find_index(int *stack, int c);

//rotation cases
int		case_rarb(int *stack_a, int *stack_b, t_sizes sizes, int c);

int		case_rrarrb(int *stack_a, int *stack_b, t_sizes sizes, int c);

int		case_rrarb(int *stack_a, int *stack_b, t_sizes sizes, int c);

int		case_rarrb(int *stack_a, int *stack_b, t_sizes sizes, int c);

int		case_rarb_a(int *stack_a, int *stack_b, t_sizes sizes, int c);

int		case_rrarrb_a(int *stack_a, int *stack_b, t_sizes sizes, int c);

int		case_rrarb_a(int *stack_a, int *stack_b, t_sizes sizes, int c);

int		case_rarrb_a(int *stack_a, int *stack_b, t_sizes sizes, int c);

//applying operations functions
int		apply_rarb_b(int *stack_a, int *stack_b, int c, t_sizes *sizes);

int		apply_rrarrb_b(int *stack_a, int *stack_b, int c, t_sizes *sizes);

int		apply_rrarb_b(int *stack_a, int *stack_b, int c, t_sizes *sizes);

int		apply_rarrb_b(int *stack_a, int *stack_b, int c, t_sizes *sizes);

int		apply_rarb_a(int *stack_a, int *stack_b, int c, t_sizes *sizes);

int		apply_rrarrb_a(int *stack_a, int *stack_b, int c, t_sizes *sizes);

int		apply_rrarb_a(int *stack_a, int *stack_b, int c, t_sizes *sizes);

int		apply_rarrb_a(int *stack_a, int *stack_b, int c, t_sizes *sizes);

//main sorting functions
void	sort_b(int *stack_a, int *stack_b, t_sizes *sizes);

void	sort_a(int *stack_a, int *stack_b, t_sizes *sizes);

void	sort(int *stack_a, int *stack_b, t_sizes *sizes);

void	sort_three(int *stack);

//checker operations (not printing command)
void	sa_2(int *stack_a, int size);

void	sb_2(int *stack_b, int size);

void	ss_2(int *stack_a, int *stack_b, int size_a, int size_b);

void	pa_2(int *stack_a, int *stack_b, int *size_a, int *size_b);

void	pb_2(int *stack_a, int *stack_b, int *size_a, int *size_b);

void	ra_2(int *stack_a, int size_a);

void	rb_2(int *stack_b, int size_b);

void	rra_2(int *stack_a, int size_a);

void	rrb_2(int *stack_b, int size_b);

void	rr_2(int *stack_a, int *stack_b, int size_a, int size_b);

void	rrr_2(int *stack_a, int *stack_b, int size_a, int size_b);

#endif