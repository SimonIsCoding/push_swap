/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement_reverse_rotate.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: simarcha <simarcha@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 13:50:53 by simarcha          #+#    #+#             */
/*   Updated: 2024/03/02 19:27:47 by simarcha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//the last element becomes the first one
void	reverse_rotate(t_list **lst)
{
	t_list	*last;
	t_list	*first;
	t_list	*second_to_last;

	if (*lst == NULL || (*lst)->next == NULL)
	{
		write(1, "useless movement rr\n", 20);//TO REMOVE BEFORE PUSHING
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

void	reverse_rotate_a(t_list **stack_a)
{
	if (*stack_a == NULL || (*stack_a)->next == NULL)
	{
		write(1, "useless movement rra\n", 21);//TO REMOVE BEFORE PUSHING
		return ;
	}
	reverse_rotate(stack_a);
	write(1, "rra\n", 4);
}

void	reverse_rotate_b(t_list **stack_b)
{
	if (*stack_b == NULL || (*stack_b)->next == NULL)
	{
		write(1, "useless movement rrb\n", 21);//TO REMOVE BEFORE PUSHING
		return ;
	}
	reverse_rotate(stack_b);
	write(1, "rrb\n", 4);
}

//the last element becomes the first one for both stacks
void	reverse_rotate_a_and_b(t_list **stack_a, t_list **stack_b)
{
	if (*stack_a == NULL || (*stack_a)->next == NULL
		|| *stack_b == NULL || (*stack_b)->next == NULL)
	{
		write(1, "useless movement rrr\n", 21);//TO REMOVE BEFORE PUSHING
		return ;
	}
	reverse_rotate(stack_a);
	reverse_rotate(stack_b);
	write(1, "rrr\n", 4);
}
