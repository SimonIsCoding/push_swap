/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement_swap.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: simarcha <simarcha@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 13:30:06 by simarcha          #+#    #+#             */
/*   Updated: 2024/06/07 17:37:46 by simarcha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

//exchange the firsts two elements of the top of the stack
static void	swap(t_list **lst)
{
	t_list	*first;
	t_list	*second;

	if (*lst == NULL || (*lst)->next == NULL)
		return ;
	first = *lst;
	second = (*lst)->next;
	first->next = second->next;
	second->next = first;
	first->index++;
	second->index--;
	*lst = second;
}

void	swap_a(t_list **stack_a)
{
	if (*stack_a == NULL || (*stack_a)->next == NULL)
		return ;
	swap(stack_a);
	if (write(1, "sa\n", 3) == -1)
		exit(1);
}

void	swap_b(t_list **stack_b)
{
	if (*stack_b == NULL || (*stack_b)->next == NULL)
		return ;
	swap(stack_b);
	if (write(1, "sb\n", 3) == -1)
		exit(1);
}

//exchange the firsts two elements for both stacks
void	swap_a_and_b(t_list **stack_a, t_list **stack_b)
{
	if (*stack_a == NULL || (*stack_a)->next == NULL
		|| *stack_b == NULL || (*stack_b)->next == NULL)
		return ;
	swap(stack_a);
	swap(stack_b);
	if (write(1, "ss\n", 3) == -1)
		exit(1);
}
