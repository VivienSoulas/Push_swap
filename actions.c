/* -------------------------------
stack a; full of random numbers
stack b; empty
ss = sa + sb;
rr = ra + rb;
rrr = rra + rrb;
---------------------------------- */
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
	t_stack	*first_a;
	t_stack	*second_a;
	t_stack	*first_b;

	if (*src == NULL)
		return ;
	first_a = *src;
	second_a = first_a->next;
	first_b = *dest;
	*src = second_a;
	if (second_a != NULL)
		second_a->prev = NULL;
	first_a->next = first_b;
	if (first_b != NULL)
		first_b->prev = first_a;
	first_a->prev = NULL;
	*dest = first_a;
	ft_printf("p%c\n", c);
}

// ra = all elements of a go one up; //first element becomes last
// rb = all elements of b go one up; //first element becomes last
void	ft_one_up(t_stack **head, char c)
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
void	ft_one_down(t_stack **head, char c)
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
