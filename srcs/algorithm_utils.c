/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm_utils.c									:+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: simarcha <simarcha@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 13:09:22 by simarcha          #+#    #+#             */
/*   Updated: 2024/03/28 12:16:13 by simarcha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

//We want to find the target node for the whole stack A
//In this case, the target node for stk A is the closest smaller found in stk B
//if the closest smaller doesn't exist, the target node will be the maximum

t_list	*closest_smaller_node(t_list *node_a, t_list *list_b)
{
	t_list	*closest_smaller;

	closest_smaller = NULL;
	while (list_b)
	{
		if (list_b->nb < node_a->nb
			&& (!closest_smaller || list_b->nb > closest_smaller->nb))
			closest_smaller = list_b;
		list_b = list_b->next;
	}
	return (closest_smaller);
}

// Recursive function to find the target node for the whole stack A
void	find_target_node_a(t_list *stack_a, t_list *stack_b)
{
	t_list	*closest_smaller;

	if (!stack_a)
		return ;
	closest_smaller = closest_smaller_node(stack_a, stack_b);
	if (!closest_smaller)
		stack_a->target = max_list_nb(&stack_b);
	else
		stack_a->target = closest_smaller;
	find_target_node_a(stack_a->next, stack_b);
}

//We want to find the target node for the whole stack B
//In this case, the target node for stack B is the closest bigger found in stk A
//if the closest bigger doesn't exist, the target node will be the minimum

t_list	*closest_bigger_node(t_list *stack_b, t_list *stack_a)
{
	t_list	*closest_bigger;

	closest_bigger = NULL;
	while (stack_a)
	{
		if (stack_a->nb > stack_b->nb
			&& (!closest_bigger || stack_a->nb < closest_bigger->nb))
			closest_bigger = stack_a;
		stack_a = stack_a->next;
	}
	return (closest_bigger);
}

// Recursive function to find the target node for the whole stack B
void	find_target_node_b(t_list *stack_b, t_list *stack_a)
{
	t_list	*closest_bigger;

	if (!stack_b)
		return ;
	closest_bigger = closest_bigger_node(stack_b, stack_a);
	if (!closest_bigger)
		stack_b->target = min_list_nb(&stack_a);
	else
		stack_b->target = closest_bigger;
	find_target_node_b(stack_b->next, stack_a);
}
