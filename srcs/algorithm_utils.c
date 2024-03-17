/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm_utils.c									:+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: simarcha <simarcha@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 13:09:22 by simarcha          #+#    #+#             */
/*   Updated: 2024/03/13 18:14:50 by simarcha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

//We want to find the target node for the whole stack A
//In this case, the target node for stk A is the closest smaller found in stk B
//if the closest smaller doesn't exist, the target node will be the maximum
/*void	find_target_node_a(t_list *stck_a, t_list *stck_b)
{
	t_list	*tmp;

	tmp = stck_b;
	while (stck_a)
	{
		stck_b = tmp;
		while (stck_b)
		{
			if ((stck_b->nb < stck_a->nb && !(stck_a->target))
				|| (stck_b->nb < stck_a->nb && stck_a->target->nb < stck_b->nb))
			{
				stck_a->target = stck_b;
			}
			if (!(stck_b->next) && !(stck_a->target))
			{
				stck_b = tmp;
				stck_a->target = max_list_nb(&stck_b);
				ft_lstlast(stck_b);
			}
			stck_b = stck_b->next;
		}
		stck_a = stck_a->next;
	}
}*/

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
void	find_target_node_a(t_list *stck_a, t_list *stck_b)
{
	t_list	*closest_smaller;

	if (!stck_a)
		return ;
	closest_smaller = closest_smaller_node(stck_a, stck_b);
	if (!closest_smaller)
		stck_a->target = max_list_nb(&stck_b);
	else
		stck_a->target = closest_smaller;
	find_target_node_a(stck_a->next, stck_b);
}

//We want to find the target node for the whole stack B
//In this case, the target node for stack B is the closest bigger found in stk A
//if the closest bigger doesn't exist, the target node will be the minimum
/*void	find_target_node_b(t_list *stck_b, t_list *stck_a)
{
	t_list	*tmp;

	tmp = stck_a;
	while (stck_b)
	{
		stck_a = tmp;
		while (stck_a)
		{
			if ((stck_a->nb > stck_b->nb && !(stck_b->target))
				|| (stck_a->nb > stck_b->nb && stck_a->nb < stck_b->target->nb))
			{
				stck_b->target = stck_a;
			}
//			if (!(stck_a->next) && !(stck_b->target))
//			{
//				stck_a = tmp;
//				stck_b->target = min_list_nb(&stck_a);
//				ft_lstlast(stck_a);
//			}
			stck_a = stck_a->next;
		}
		if (!(stck_a) && !(stck_b->target))
		{
			stck_a = tmp;
			stck_b->target = min_list_nb(&stck_a);
//			ft_lstlast(stck_a);
		}
		stck_b = stck_b->next;
	}
}
*/

t_list	*closest_bigger_node(t_list *node_b, t_list *stack_a)
{
	t_list	*closest_bigger;

	closest_bigger = NULL;
	while (stack_a)
	{
		if (stack_a->nb > node_b->nb
			&& (!closest_bigger || stack_a->nb < closest_bigger->nb))
			closest_bigger = stack_a;
		stack_a = stack_a->next;
	}
	return (closest_bigger);
}

// Recursive function to find the target node for the whole stack B
void	find_target_node_b(t_list *stck_b, t_list *stck_a)
{
	t_list	*closest_bigger;

	if (!stck_b)
		return ;
	closest_bigger = closest_bigger_node(stck_b, stck_a);
	if (!closest_bigger)
		stck_b->target = min_list_nb(&stck_a);
	else
		stck_b->target = closest_bigger;
	find_target_node_b(stck_b->next, stck_a);
}
