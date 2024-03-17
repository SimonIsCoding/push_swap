/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement_reverse_rotate.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: simarcha <simarcha@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 13:50:53 by simarcha          #+#    #+#             */
/*   Updated: 2024/03/17 19:57:44 by simarcha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

//the last element becomes the first one
static void	reverse_rotate(t_list **lst)
{
	t_list	*last;
	t_list	*second_last;

	last = *lst;
	second_last = NULL;
	if (*lst == NULL || (*lst)->next == NULL)
		return ;
	while (last->next != NULL)
	{
		second_last = last;
		last = last->next;
	}
	last->next = (*lst)->next;
	last->next = *lst;
	*lst = last;
	second_last->next = NULL;
	increment_index(*lst);
	last->index = 0;
}

void	reverse_rotate_a(t_list **stack_a)
{
	if (*stack_a == NULL || (*stack_a)->next == NULL)
		return ;
	reverse_rotate(stack_a);
	if (write(1, "rra\n", 4) == -1)
		exit(1);
}

void	reverse_rotate_b(t_list **stack_b)
{
	if (*stack_b == NULL || (*stack_b)->next == NULL)
		return ;
	reverse_rotate(stack_b);
	if (write(1, "rrb\n", 4) == -1)
		exit(1);
}

//the last element becomes the first one for both stacks
void	reverse_rotate_a_and_b(t_list **stack_a, t_list **stack_b)
{
	if (*stack_a == NULL || (*stack_a)->next == NULL
		|| *stack_b == NULL || (*stack_b)->next == NULL)
		return ;
	reverse_rotate(stack_a);
	reverse_rotate(stack_b);
	if (write(1, "rrr\n", 4) == -1)
		exit(1);
}
