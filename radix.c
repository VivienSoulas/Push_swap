/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsoulas <vsoulas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 15:21:58 by vsoulas           #+#    #+#             */
/*   Updated: 2025/02/13 17:11:03 by vsoulas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//void	ft_radix(t_stack **head)
//{
//	t_stack	*stack_a;
//	//t_stack	*stack_b;
//	int		max;
//	int 	place;

//	stack_a = *head;
//	//stack_b = NULL;
//	max = ft_max(head);
//	place = 1;
//	while (max / place > 0)
//	{
//		ft_count_sort(&stack_a, place);
//		 place *=10;
//	}
//}

//void	ft_count_sort(t_stack **head, int place)
//{
//	t_stack	*stack_a;
//	t_stack	*stack_b;

//	stack_a = *head;
//	stack_b = NULL;
//	place = 0;
//}

void	ft_count_sort(t_stack **head, int bit)
{
    t_stack	*stack_a;
    t_stack	*stack_b;

    stack_a = *head;
    stack_b = NULL;

    // Separate numbers based on the current bit
    while (stack_a)
    {
        if (((stack_a->content >> bit) & 1) == 1)
            ft_rotate(&stack_a, 'a');
        else
            ft_push(&stack_a, &stack_b, 'b');
    }

    // Push all numbers from stack_b back to stack_a
    while (stack_b)
        ft_push(&stack_b, &stack_a, 'a');

    *head = stack_a;
}

void	ft_radix(t_stack **stack_a, t_stack **stack_b)
{
	
}

