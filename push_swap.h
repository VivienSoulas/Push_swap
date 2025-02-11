#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <limits.h>
# include "ft_printf/ft_printf.h"
# include "libft/libft.h"

// linked list for stack
typedef struct s_stack
{
	int					content;
	struct s_stack		*next;
	struct s_stack		*prev;
}	t_stack;

// possible opertions
void	ft_swap(t_stack **head, char c);
void	ft_push(t_stack **src, t_stack **dest, char c);
void	ft_rotate(t_stack **head, char c);
void	ft_reverse_rotate(t_stack **head, char c);

// adding input to stack
int		ft_string_to_stack(char **argv, t_stack **head, int i);
int		ft_arg_to_stack(char **argv, t_stack **head);
int		ft_add_to_stack(t_stack **head, char *arg);

// checing inputs
int		ft_check_dup(t_stack **head);
int		ft_check_arg(char *arg);
int		ft_check_list(t_stack **head);

// free
void	ft_free_stack(t_stack **head);
void	ft_free_split(char **array);

// sort
void	ft_sort(t_stack **head);
void	ft_sort_2(t_stack **head);
void	ft_sort_3(t_stack **head);

// print
void	ft_print_stack(t_stack **head);

// utils
int		ft_search(char *arg, char c);
t_stack	*ft_last_node(t_stack *head);
void	ft_reverse_stack(t_stack **head);
int		ft_atoi_flag(char *str, int *error);

#endif