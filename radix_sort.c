/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcalero <lcalero@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 15:59:39 by lcalero           #+#    #+#             */
/*   Updated: 2024/12/18 16:02:59 by lcalero          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	radix_sort(int *stack_a, int *stack_b, int size_a, int size_b)
{
	int	max_num;
	int	max_bits;

	max_num = size_a - 1;
	max_bits = 0;
	
	while ((max_num >> max_bits) != 0)
		max_bits++;
}