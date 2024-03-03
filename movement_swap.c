/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement_swap.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: simarcha <simarcha@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 13:30:06 by simarcha          #+#    #+#             */
/*   Updated: 2024/03/02 19:26:59 by simarcha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//exchange the firsts two elements of the top of the stack
void	swap(t_list **lst)
{
	t_list	*first;
	t_list	*second;
	t_list	*tmp;

	if (*lst == NULL || (*lst)->next == NULL)
	{
		write(1, "useless movement swap\n", 22);//TO REMOVE BEFORE PUSHING
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

void	swap_a(t_list **stack_a)
{
	if (*stack_a == NULL || (*stack_a)->next == NULL)
	{
		write(1, "useless movement sa\n", 20);//TO REMOVE BEFORE PUSHING
		return ;
	}
	swap(stack_a);
	write(1, "sa\n", 3);
}

void	swap_b(t_list **stack_b)
{
	if (*stack_b == NULL || (*stack_b)->next == NULL)
	{
		write(1, "useless movement sb\n", 20);//TO REMOVE BEFORE PUSHING
		return ;
	}
	swap(stack_b);
	write(1, "sb\n", 3);
}

//exchange the firsts two elements for both stacks
void	swap_a_and_b(t_list **stack_a, t_list **stack_b)
{
	if (*stack_a == NULL || (*stack_a)->next == NULL
		|| *stack_b == NULL || (*stack_b)->next == NULL)
	{
		write(1, "useless movement ss\n", 20);//TO REMOVE BEFORE PUSHING
		return ;
	}
	swap(stack_a);
	swap(stack_b);
	write(1, "ss\n", 3);
}
