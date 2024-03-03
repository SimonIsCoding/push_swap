/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement_push.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: simarcha <simarcha@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 13:18:00 by simarcha          #+#    #+#             */
/*   Updated: 2024/03/02 13:41:32 by simarcha         ###   ########.fr       */
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

//we put the first element of the stack B at the top of the stack A 
//From B to A
void	push_a(t_list **stack_b, t_list **stack_a)
{
	t_list	*first_b;
	t_list	*first_a;

	if (*stack_b == NULL)
	{
		write(1, "useless movement push A\n", 24);//TO REMOVE BEFORE PUSHING
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
	write(1, "pa\n", 3);
}

//we put the first element of the stack A at the top of the stack B 
//From A to B
void	push_b(t_list **stack_a, t_list **stack_b)
{
	t_list	*first_a;
	t_list	*first_b;

	if (*stack_a == NULL)
	{
		write(1, "useless movement push B\n", 24);//TO REMOVE BEFORE PUSHING
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
	write(1, "pb\n", 3);
}
