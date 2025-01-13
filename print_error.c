/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcalero <lcalero@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 16:39:00 by lcalero           #+#    #+#             */
/*   Updated: 2025/01/13 12:47:15 by lcalero          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*This function prints an error and exit 
the program*/
void	print_error(void)
{
	ft_putstr_fd("Error\n", 2);
	exit(1);
}

/*This function prints an error, exit
the program and frees the stack passed
in parameter*/
void	print_error_free(int *stack_a)
{
	if (stack_a)
		free(stack_a);
	ft_putstr_fd("Error\n", 2);
	exit(1);
}
