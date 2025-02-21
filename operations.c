/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsoulas <vsoulas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 15:12:49 by vsoulas           #+#    #+#             */
/*   Updated: 2025/02/20 15:52:38 by vsoulas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* -------------------------------------*/
/*	operation counts add at the end : 	*/
/*	increment_operation_count(); 		*/
/* -------------------------------------*/
#include "push_swap.h"
// use of double pointer in order to be able to change the head of the list

// sa = swap 2 first elements of a; //does nothing if a has 1 or less elements
// sb = swap 2 first elements of b; //does nothing if b has 1 or less elements
void	ft_swap(t_stack **head, char c)
{
	t_stack	*first;
	t_stack	*second;
	t_stack	*third;

	if (*head == NULL || (*head)->next == NULL)
		return ;
	first = *head;
	second = first->next;
	third = second->next;
	*head = second;
	second->prev = NULL;
	second->next = first;
	first->prev = second;
	first->next = third;
	if (third-> next != NULL)
		third->prev = first;
	ft_printf("s%c\n", c);
}

// pa = first element top of b goes top of a; //does nothing is b is empty;
// pb = first element top of a goes top of b; //does nothing is a is empty;
void	ft_push(t_stack **src, t_stack **dest, char c)
{
	t_stack	*first_b;
	t_stack	*second_b;
	t_stack	*first_a;

	if (*src == NULL)
		return ;
	first_b = *src;
	second_b = first_b->next;
	first_a = *dest;
	*dest = first_b;
	if (first_a != NULL)
	{
		first_a->prev = first_b;
		first_b->next = first_a;
	}
	else
		first_b->next = NULL;
	if (second_b != NULL)
	{
		*src = second_b;
		second_b->prev = NULL;
	}
	else
		*src = NULL;
	ft_printf("p%c\n", c);
}

// ra = all elements of a go one up; //first element becomes last
// rb = all elements of b go one up; //first element becomes last
void	ft_rotate(t_stack **head, char c)
{
	t_stack	*first;
	t_stack	*second;
	t_stack	*last;

	if (*head == NULL || (*head)->next == NULL)
		return ;
	first = *head;
	second = first->next;
	last = ft_last_node(*head);
	*head = second;
	second->prev = NULL;
	last->next = first;
	first->next = NULL;
	first->prev = last;
	ft_printf("r%c\n", c);
}

// rra = all elements of a go one down; //last become first
// rrb = all elements of b go one down; //last become first
void	ft_reverse_rotate(t_stack **head, char c)
{
	t_stack	*first;
	t_stack	*last;
	t_stack	*second_last;

	if (*head == NULL || (*head)->next == NULL)
		return ;
	first = *head;
	last = ft_last_node(*head);
	second_last = last->prev;
	second_last->next = NULL;
	last->next = first;
	last->prev = NULL;
	first->prev = last;
	*head = last;
	ft_printf("rr%c\n", c);
}
