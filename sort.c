/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsoulas <vsoulas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 15:13:22 by vsoulas           #+#    #+#             */
/*   Updated: 2025/02/13 17:03:39 by vsoulas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sort(t_stack **head)
{
	int		i;
	t_stack	*current;
	t_stack	*stack_b;

	i = 0;
	stack_b = NULL;
	current = *head;
	while (current)
	{
		i++;
		current = current->next;
	}
	if (i == 2)
		ft_sort_2(head);
	else if (i == 3)
		ft_sort_3(head);
	else
	ft_radix(head, &stack_b);
}

void	ft_sort_2(t_stack **head)
{
	t_stack	*current;
	t_stack	*next;

	current = *head;
	next = current->next;
	if (current->content > next->content)
	{
		ft_rotate(head, 'a');
	}
}

void	ft_sort_3(t_stack **head)
{
	t_stack	*current;
	t_stack	*next;
	t_stack	*last;

	current = *head;
	next = current->next;
	last = ft_last_node(*head);
	if (current->content > next->content && current->content > last->content)
	{
		ft_rotate(head, 'a');
		current = *head;
		next = current->next;
		if (current->content > next->content)
			ft_swap(head, 'a');
	}
	else if (current->content > next->content)
		ft_swap(head, 'a');
	else if (next->content > last->content)
	{
		ft_reverse_rotate(head, 'a');
		current = *head;
		next = current->next;
		if (current->content > next->content)
			ft_swap(head, 'a');
	}
}
