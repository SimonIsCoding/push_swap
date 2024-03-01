/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: simarcha <simarcha@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/25 19:46:44 by simarcha          #+#    #+#             */
/*   Updated: 2024/02/29 23:02:04 by simarcha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	increment_index(t_list *stack)
{
	t_list	*tmp;

	tmp = stack->next;
	while (tmp != NULL)
	{
		tmp->index++;
		tmp = tmp->next;
	}
}

void	decrement_index(t_list *stack)
{
	t_list	*tmp;

	tmp = stack;
	while (tmp != NULL)
	{
		tmp->index--;
		tmp = tmp->next;
	}
}

//exchange the firsts two elements of the top of the stack
void	swap(t_list **lst)
{
	t_list	*first;
	t_list	*second;
	t_list	*tmp;

	if (*lst == NULL || (*lst)->next == NULL)
	{
		write(1, "useless movement swap\n", 22);
		return ;
	}
	first = *lst;
	second = (*lst)->next;
	tmp = first;
	first->next = second->next;
	second->prev = first->prev;
	first->prev = second;
	second->next = first;
	first->index++;
	second->index--;
	*lst = second;
}

//the first element becomes the last one
void	rotate(t_list **lst)
{
	t_list	*first;
	t_list	*second;
	t_list	*last;

	if (*lst == NULL || (*lst)->next == NULL)
	{
		write(1, "useless movement rotate\n", 23);
		return ;
	}
	first = *lst;
	second = (*lst)->next;
	last = ft_lstlast(*lst);

	last->next = first;
	first->prev = last;//repetition
	first->next = NULL;
	*lst = second;
	first->index = ft_lstsize(*lst);
	decrement_index(*lst);
}

//the last element becomes the first one
void	reverse_rotate(t_list **lst)
{
	t_list	*last;
	t_list	*first;
	t_list	*second_to_last;

	if (*lst == NULL || (*lst)->next == NULL)
	{
		write(1, "useless movement rr\n", 20);
		return ;
	}
	last = ft_lstlast(*lst);
	first = *lst;
	second_to_last = last->prev;

	first->prev = last;
	last->next = first;
	last->prev = NULL;
	second_to_last->next = NULL;
	*lst = last;
	increment_index(*lst);
	last->index = 0;
}

//we put the first element of the stack B at the top of the stack A 
//From B to A
void	push_a(t_list **stack_b, t_list **stack_a)
{
	t_list	*first_b;
	t_list	*first_a;

	if (*stack_b == NULL)
	{
		write(1, "useless movement push A\n", 24);
		return ;
	}
	first_b = *stack_b;
	if ((*stack_b)->next)
	{
		*stack_b = (*stack_b)->next;
		decrement_index(*stack_b);
	}
	else
		*stack_b = NULL;
	first_a = first_b;
	first_a->next = *stack_a;
	*stack_a = first_a;
	increment_index(*stack_a);
}

//we put the first element of the stack A at the top of the stack B 
//From A to B
void	push_b(t_list **stack_a, t_list **stack_b)
{
	t_list	*first_a;
	t_list	*first_b;

	if (*stack_a == NULL)
	{
		write(1, "useless movement push B\n", 24);
		return ;
	}
	first_a = *stack_a;
	if ((*stack_a)->next)
	{
		*stack_a = (*stack_a)->next;
		decrement_index(*stack_a);
	}
	else
		*stack_a = NULL;
	first_b = first_a;
	first_b->next = *stack_b;
	*stack_b = first_b;
	increment_index(*stack_b);
}
