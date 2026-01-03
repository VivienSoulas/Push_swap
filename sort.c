/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsoulas <vsoulas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 15:13:22 by vsoulas           #+#    #+#             */
/*   Updated: 2025/02/20 15:57:25 by vsoulas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sort(t_stack **head)
{
	int		i;
	t_stack	*stack_b;

	stack_b = NULL;
	i = ft_set_index_to_nodes(head);
	if (i == 2)
		ft_sort_2(head);
	else if (i == 3)
		ft_sort_3(head);
	else if (i == 4)
		ft_sort_4(head, &stack_b);
	else if (i == 5)
		ft_sort_5(head, &stack_b);
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
		ft_rotate(head, 'a');
	else if (next->content > last->content)
		ft_reverse_rotate(head, 'a');
	current = *head;
	next = current->next;
	if (current->content > next->content)
		ft_swap(head, 'a');
}

void	ft_sort_4(t_stack **stack_a, t_stack **stack_b)
{
	int	i;

	i = 4;
	while (i > 0)
	{
		if ((*stack_a)->index == 0)
			ft_push(stack_a, stack_b, 'b');
		else
			ft_rotate(stack_a, 'a');
		i--;
	}
	ft_sort_3(stack_a);
	ft_push(stack_b, stack_a, 'a');
}

void	ft_sort_5(t_stack **stack_a, t_stack **stack_b)
{
	int	i;

	i = 5;
	while (i > 0)
	{
		if ((*stack_a)->index == 0 || (*stack_a)->index == 1)
			ft_push(stack_a, stack_b, 'b');
		else
			ft_rotate(stack_a, 'a');
		i--;
	}
	ft_sort_3(stack_a);
	ft_push(stack_b, stack_a, 'a');
	ft_push(stack_b, stack_a, 'a');
	if ((*stack_a)->index > (*stack_a)->next->index)
		ft_swap(stack_a, 'a');
}
