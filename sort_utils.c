/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsoulas <vsoulas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 10:30:10 by vsoulas           #+#    #+#             */
/*   Updated: 2025/02/20 10:30:11 by vsoulas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// find the max index ()
int	ft_max_index(t_stack **head)
{
	t_stack	*current;
	int		max;

	max = 0;
	current = *head;
	while (current)
	{
		if (current->index > max)
			max = current->index;
		current = current->next;
	}
	return (max);
}

// set the indexes to the nodes according to their value
// first loops through the stack to find unasigned smallest value
// then sets the index of this node at i
// start again
int	ft_set_index_to_nodes(t_stack **head)
{
	t_stack	*current;
	int		min;
	int		i;

	i = 0;
	while (i < ft_stack_size(head))
	{
		min = INT_MAX;
		current = *head;
		while (current)
		{
			if (current->content < min && current->index == -1)
				min = current->content;
			current = current->next;
		}
		current = *head;
		while (current)
		{
			if (current->content == min)
				current->index = i;
			current = current->next;
		}
		i++;
	}
	return (i);
}

// calculate the size of the list/stack
int	ft_stack_size(t_stack **head)
{
	int		size;
	t_stack	*current;

	size = 0;
	current = *head;
	while (current)
	{
		size++;
		current = current->next;
	}
	return (size);
}

// repeatedly shift the max_index to the right until 0
// example 13 = 1101
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
