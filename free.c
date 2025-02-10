#include "push_swap.h"

void	ft_free_stack(t_stack **head)
{
	t_stack	*current;
	t_stack	*next;

	if (*head == NULL)
		return ;
	current = *head;
	while (current)
	{
		next = current->next;
		free(current);
		current = next;
	}
	*head = NULL;
}

void	ft_free_split(char **array)
{
	int	i;

	i = 0;
	if (array == NULL)
		return ;
	while (array[i])
	{
		free(array[i]);
		i++;
	}
	free(array);
	array = NULL;
}
