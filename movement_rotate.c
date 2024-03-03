/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement_rotate.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: simarcha <simarcha@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 13:19:53 by simarcha          #+#    #+#             */
/*   Updated: 2024/03/02 19:27:36 by simarcha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//the first element becomes the last one
void	rotate(t_list **lst)
{
	t_list	*first;
	t_list	*second;
	t_list	*last;

	if (*lst == NULL || (*lst)->next == NULL)
	{
		write(1, "useless movement rotate\n", 23);//TO REMOVE BEFORE PUSHING
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

void	rotate_a(t_list **stack_a)
{
	if (*stack_a == NULL || (*stack_a)->next == NULL)
	{
		write(1, "useless movement ra\n", 20);//TO REMOVE BEFORE PUSHING
		return ;
	}
	rotate(stack_a);
	write(1, "ra\n", 3);
}

void	rotate_b(t_list **stack_b)
{
	if (*stack_b == NULL || (*stack_b)->next == NULL)
	{
		write(1, "useless movement rb\n", 20);//TO REMOVE BEFORE PUSHING
		return ;
	}
	rotate(stack_b);
	write(1, "rb\n", 3);
}

//the first element becomes the last one for both stacks
void	rotate_a_and_b(t_list **stack_a, t_list **stack_b)
{
	if (*stack_a == NULL || (*stack_a)->next == NULL
		|| *stack_b == NULL || (*stack_b)->next == NULL)
	{
		write(1, "useless movement rr\n", 20);//TO REMOVE BEFORE PUSHING
		return ;
	}
	rotate(stack_a);
	rotate(stack_b);
	write(1, "rr\n", 3);
}
