/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: simarcha <simarcha@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 12:14:06 by simarcha          #+#    #+#             */
/*   Updated: 2024/03/17 20:06:07 by simarcha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>

typedef struct s_list
{
	long int		nb;	
	int				index;
	int				single_cost;
	int				push_cost;
	struct s_list	*target;
	struct s_list	*next;
}					t_list;

//push_swap_utils
size_t		ft_strlen(const char *str);
long int	ft_atol(const char *str);
char		**free_array(char **array);
char		**ft_split(const char *s, char c);
char		*ft_strdup(const char *str);
size_t		itoa_helper(long num);
char		*ft_itoa(long int n);

//list_utils
t_list		*ft_lstnew(long int nb, int i);
void		ft_lstadd_back(t_list **lst, t_list *new);
int			ft_lstsize(t_list *lst);
void		ft_lstclear(t_list **lst);
t_list		*ft_lstlast(t_list *lst);
t_list		*create_list(int argc, char **argv);

//Error Management
int			write_error(void);
int			ft_isdigit(int c);
void		is_a_number(int argc, char **argv);
void		two_same_numbers(t_list *lst);
int			sorted_check(t_list	*lst);
t_list		*create_list_argc_is_2(char **argv);
void		manage_error_argc_is_2(char **argv);
void		check_if_int(t_list *lst);
void		check_u_long_max(char **argv);
void		manage_error(int argc, char **argv);

//Movements
void		swap_a(t_list **stack_a);
void		swap_b(t_list **stack_b);
void		swap_a_and_b(t_list **stack_a, t_list **stack_b);
void		decrement_index(t_list *stack);
void		increment_index(t_list *stack);
void		rotate_a(t_list **stack_a);
void		rotate_b(t_list **stack_b);
void		rotate_a_and_b(t_list **stack_a, t_list **stack_b);
void		reverse_rotate_a(t_list **stack_a);
void		reverse_rotate_b(t_list **stack_b);
void		reverse_rotate_a_and_b(t_list **stack_a, t_list **stack_b);
void		push_a(t_list **stack_b, t_list **stack_a);
void		push_b(t_list **stack_a, t_list **stack_b);

//find min & max elements
t_list		*min_list_nb(t_list **lst);
t_list		*max_list_nb(t_list **lst);
t_list		*min_push_cost(t_list **lst);

//algorithm_utils
void		find_target_node_a(t_list *stack_a, t_list *stack_b);
void		find_target_node_b(t_list *stack_b, t_list *stack_a);
void		rate_single_cost(t_list *stack);
void		push_cost_total(t_list *node);

//find the median
char		**array_numbers(t_list *stack_a);
int			find_the_median(char **array, int lstsize, int median);

//Sorting
void		sort_2_numbers(t_list **lst);
void		sort_3_numbers(t_list **lst);
void		big_sort(t_list **stack_a, t_list **stack_b);

#endif
