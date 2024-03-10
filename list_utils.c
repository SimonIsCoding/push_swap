/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: simarcha <simarcha@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 19:16:33 by simarcha          #+#    #+#             */
/*   Updated: 2024/03/05 19:22:03 by simarcha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*ft_lstnew(long int nb, int i)
{
	t_list	*node;

	node = malloc(sizeof(t_list));
	if (!node)
		return (NULL);
	node->nb = nb;
	node->index = i;
	node->push_cost = 0;
	node->target = NULL;
	node->prev = NULL;
	node->next = NULL;
	return (node);
}

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*tmp;

	if (!lst || !new)
		return ;
	else if (!(*lst))
	{
		*lst = new;
		return ;
	}
	tmp = *lst;
	while (tmp->next != NULL)
		tmp = tmp->next;
	tmp->next = new;
	new->prev = tmp;
}

int	ft_lstsize(t_list *lst)
{
	int	i;

	i = 0;
	while (lst != NULL)
	{
		i++;
		lst = lst->next;
	}
	return (i);
}

void ft_lstclear(t_list **lst)
{
	t_list	*tmp;

    if (!lst)
        return;
    while (*lst != NULL)
	{
        tmp = *lst;
        *lst = (*lst)->next;
        free(tmp);
		tmp = NULL;
    }
	lst = NULL;
}

t_list	*ft_lstlast(t_list *lst)
{
	if (lst)
	{
		while (lst->next != NULL)
			lst = lst->next;
		return (lst);
	}
	return (NULL);
}

t_list	*ft_lstbegin(t_list *lst)
{
	if (lst)
	{
		while (lst->prev)
			lst = lst->prev;
		return (lst);
	}
	return (NULL);
}
