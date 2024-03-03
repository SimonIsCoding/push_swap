/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   min_max.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: simarcha <simarcha@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 19:47:19 by simarcha          #+#    #+#             */
/*   Updated: 2024/03/02 18:40:25 by simarcha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//function that finds the min node in the list
t_list	*min_list(t_list **lst)
{
	t_list		*tmp;
	t_list		*min;

	tmp = *lst;
	min = *lst;
	while (tmp != NULL)
	{
		if (tmp->nb < min->nb)
			min = tmp;
		tmp = tmp->next;
	}
	return (min);
}

//function that finds the max node in the list
t_list	*max_list(t_list **lst)
{
	t_list		*tmp;
	t_list		*max;

	tmp = *lst;
	max = *lst;
	while (tmp != NULL)
	{
		if (tmp->nb > max->nb)
			max = tmp;
		tmp = tmp->next;
	}
	return (max);
}

int	check_min_and_max_position(t_list *lst)
{
	if (min_list(&lst)->index == 0 && max_list(&lst)->index == 1)
		return (1);
	else if (max_list(&lst)->index == 0)
		return (1);
	else
		return (0);
}
