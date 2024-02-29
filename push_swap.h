/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: simarcha <simarcha@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 12:14:06 by simarcha          #+#    #+#             */
/*   Updated: 2024/02/28 20:13:29 by simarcha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <unistd.h>
#include <stdlib.h>
#include "ft_printf/ft_printf.h"
#include <stdio.h>//WATCH OUT YOU USE A FORBIDDEN FUNCTION

typedef struct s_list
{
	int				nb;	
	unsigned int	index;
	struct s_list	*next;
	struct s_list	*prev;
}					t_list;

//push_swap_utils
size_t		ft_strlen(const char *str);
long int	ft_atol(const char *str);
char		*ft_strdup(const char *str);

//list_utils
//t_list		*ft_lstnew(int nb);
t_list		*ft_lstnew(int nb, int i);
void		ft_lstadd_back(t_list **lst, t_list *new);
int			ft_lstsize(t_list *lst);
void print_list(t_list *stack_a, t_list *stack_b);
//void		print_list(t_list *lst);
void		ft_lstclear(t_list **lst);
t_list		*ft_lstlast(t_list *lst);

//Movements
//void		swap_a(void);
void		swap_b(void);
void		swap_ab(void);
//void		push_a(void);
//void		push_b(void);
void		rotate_a(void);
void		rotate_b(void);
void		rotate_ab(void);
void		reverse_rotate_a(void);
void		reverse_rotate_b(void);
void		reverse_rotate_ab(void);
void		write_error(void);

void		sort_2_numbers(t_list *lst);

//movements
void		swap(t_list **lst);
void		rotate(t_list **lst);
void		reverse_rotate(t_list **lst);
void		push_a(t_list **stack_b, t_list **stack_a);
void		push_b(t_list **stack_a, t_list **stack_b);

#endif
