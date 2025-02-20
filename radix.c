/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsoulas <vsoulas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 15:21:58 by vsoulas           #+#    #+#             */
/*   Updated: 2025/02/20 11:15:41 by vsoulas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// sort the nodes by index number using binary sort (bits)
// i has to pass max_bits times to sort the stack (example 13 = 1101 => 4 bits)
//
// (current_val & (1 << i)) == 0 : here & compare each bits of two numbers
// if both are 1 the result of & is 0, otherwise it is 1
//
// i = 1 => 1 = 0001 / shift 1 << 1 => 0010 (aka 2)
// example 0101 = 5 binary / 0010 = 2 bianry
// 0 & 0 = 0 -- 1 & 0 = 0 -- 0 & 1 = 0 -- 1 & 0 = 0
// comparaison = 0 => moved to stack_b
//
// finally move all stack_b back into a;
// actual sorting was done during the indexing
void	ft_radix(t_stack **stack_a, t_stack **stack_b)
{
	int	max_bits;
	int	size;
	int	i;
	int	j;
	int	current_val;

	max_bits = find_bits(ft_max_index(stack_a));
	size = ft_stack_size(stack_a);
	i = 0;
	while (i < max_bits)
	{
		j = 0;
		while (j < size)
		{
			current_val = (*stack_a)->index;
			if ((current_val & (1 << i)) == 0)
				ft_push(stack_a, stack_b, 'b');
			else
				ft_rotate(stack_a, 'a');
			j++;
		}
		while (*stack_b != NULL)
			ft_push(stack_b, stack_a, 'a');
		i++;
	}
}
