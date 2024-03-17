/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement_rotate.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: simarcha <simarcha@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 13:19:53 by simarcha          #+#    #+#             */
/*   Updated: 2024/03/17 19:57:51 by simarcha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

//the first element becomes the last one
static void	rotate(t_list **lst)
{
	t_list	*first;
	t_list	*second;
	t_list	*last;

	if (*lst == NULL || (*lst)->next == NULL)
		return ;
	first = *lst;
	second = (*lst)->next;
	last = ft_lstlast(*lst);
	last->next = first;
	first->next = NULL;
	*lst = second;
	first->index = ft_lstsize(*lst);
	decrement_index(*lst);
}

void	rotate_a(t_list **stack_a)
{
	if (*stack_a == NULL || (*stack_a)->next == NULL)
		return ;
	rotate(stack_a);
	if (write(1, "ra\n", 3) == -1)
		exit(1);
}

void	rotate_b(t_list **stack_b)
{
	if (*stack_b == NULL || (*stack_b)->next == NULL)
		return ;
	rotate(stack_b);
	if (write(1, "rb\n", 3) == -1)
		exit(1);
}

//the first element becomes the last one for both stacks
void	rotate_a_and_b(t_list **stack_a, t_list **stack_b)
{
	if (*stack_a == NULL || (*stack_a)->next == NULL
		|| *stack_b == NULL || (*stack_b)->next == NULL)
		return ;
	rotate(stack_a);
	rotate(stack_b);
	if (write(1, "rr\n", 3) == -1)
		exit(1);
}
