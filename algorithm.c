/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: simarcha <simarcha@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 13:09:22 by simarcha          #+#    #+#             */
/*   Updated: 2024/03/04 21:35:56 by simarcha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//We want to find the target node for the whole stack A
//In this case, the target node for stack A is the closer smaller found in stack B
//if the closest smaller doesn't exist, the target node will be the maximum
void	find_target_node_a(t_list *stck_a, t_list *stck_b)
{
	t_list	*tmp;

	tmp = stck_b;
	while (stck_a)
	{
		stck_b = tmp;
		while (stck_b)
		{
			if ((stck_b->nb < stck_a->nb && !(stck_a->target))
				|| (stck_b->nb < stck_a->nb
				&& stck_a->nb - stck_b->nb < stck_b->nb - stck_a->target->nb))
			{
				stck_a->target = stck_b;
			}
			if (!(stck_b->next) && !(stck_a->target))
				stck_a->target = max_list(&stck_b);
			stck_b = stck_b->next;
		}
		stck_a = stck_a->next;
	}
}

//We want to find the target node for the whole stack B
//In this case, the target node for stack B is the closet bigger found in stack A
//if the closest bigger doesn't exist, the target node will be the minimum
void	find_target_node_b(t_list *stck_b, t_list *stck_a)
{
	t_list	*tmp;

	tmp = stck_a;
	while (stck_b)
	{
		stck_a = tmp;
		while (stck_a)
		{
			if ((stck_a->nb > stck_b->nb && !(stck_b->target))
			|| (stck_a->nb > stck_b->nb
			&& stck_a->nb - stck_b->nb < stck_b->nb - stck_b->target->nb))
			{
				stck_b->target = stck_a;
			}
			if (!(stck_a->next) && !(stck_b->target))
				stck_b->target = min_list(&stck_a);
			stck_a = stck_a->next;
		}
		stck_b = stck_b->next;
	}
}
