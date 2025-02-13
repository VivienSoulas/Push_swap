/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsoulas <vsoulas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 15:21:58 by vsoulas           #+#    #+#             */
/*   Updated: 2025/02/13 17:35:35 by vsoulas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_bits(int max_index)
{
	int	max_bits;

	max_bits = 0;
	while (max_index > 0)
	{
		max_index = max_index >> 1;
		max_bits++;
	}
	return (max_bits);
}

void	ft_radix(t_stack **stack_a, t_stack **stack_b)
{
	int	max_index;
	int	max_bits;
	int	i;
	int	j;

	max_bits = 0;
	max_index = ft_max(stack_a);
	max_bits = find_bits(max_index);
	i = 0;
	while (i < max_bits)
	{
		j = 0;
		while (j <= max_index)
		{
			if (((*stack_a)->keys >> i) & 1)
				ft_rotate(stack_a, 'a');
			else
				ft_push(stack_a, stack_b, 'b');
			j++;
		}
		while (*stack_b != NULL)
			ft_push(stack_b, stack_a, 'a');
		i++;
	}
}
