/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: simarcha <simarcha@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 12:14:06 by simarcha          #+#    #+#             */
/*   Updated: 2024/03/03 12:00:14 by simarcha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
//# include "ft_printf/ft_printf.h"
# include <stdio.h>//WATCH OUT YOU USE A FORBIDDEN LIBRARY

typedef struct s_list
{
	long int		nb;	
	unsigned int	index;
	struct s_list	*next;
	struct s_list	*prev;
}					t_list;

//push_swap_utils
size_t		ft_strlen(const char *str);
long int	ft_atol(const char *str);
char		**free_array(char **array);
char		**ft_split(const char *s, char c);

//list_utils
t_list		*ft_lstnew(long int nb, int i);
void		ft_lstadd_back(t_list **lst, t_list *new);
int			ft_lstsize(t_list *lst);
void		print_list(t_list *stack_a, t_list *stack_b);//TO REMOVE BEFORE PUSHING
void		ft_lstclear(t_list **lst);
t_list		*ft_lstlast(t_list *lst);
t_list		*create_list(int argc, char **argv);

//Sorting
void		sort_2_numbers(t_list **lst);
void		sort_3_numbers(t_list **lst);
//void		sort_4_numbers(t_list **lst);

//Movements
void		swap(t_list **lst);
void		swap_a(t_list **stack_a);
void		swap_b(t_list **stack_b);
void		swap_a_and_b(t_list **stack_a, t_list **stack_b);
void		decrement_index(t_list *stack);
void		increment_index(t_list *stack);
void		rotate(t_list **lst);
void		rotate_a(t_list **stack_a);
void		rotate_b(t_list **stack_b);
void		rotate_a_and_b(t_list **stack_a, t_list **stack_b);
void		reverse_rotate(t_list **lst);
void		reverse_rotate_a(t_list **stack_a);
void		reverse_rotate_b(t_list **stack_b);
void		reverse_rotate_a_and_b(t_list **stack_a, t_list **stack_b);
void		push_a(t_list **stack_b, t_list **stack_a);
void		push_b(t_list **stack_a, t_list **stack_b);

//Error Management
int			write_error(void);
int			ft_isdigit(int c);
void		is_a_number(int argc, char **argv);
void		two_same_numbers(t_list *lst);
int			sorted_check(t_list	*lst);
t_list		*create_list_argc_is_2(char **argv);
void		manage_error_argc_is_2(char **argv);
void		check_if_int(t_list *lst);
void		manage_error(int argc, char **argv);

//find min & max
t_list		*min_list(t_list **lst);
t_list		*max_list(t_list **lst);
int			check_min_and_max_position(t_list *lst);

#endif
