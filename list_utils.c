/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: simarcha <simarcha@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 19:16:33 by simarcha          #+#    #+#             */
/*   Updated: 2024/03/02 19:30:43 by simarcha         ###   ########.fr       */
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

#include <stdio.h>//WATCH OUT YOU USE A FORBIDDEN FUNCTION
void print_list(t_list *stack_a, t_list *stack_b)
{
    while (stack_a != NULL || stack_b != NULL)
	{
//		printf("Entered in while\n");
		if (stack_b && stack_a)
		{
//			write(1, "Entered in stack_a && stack_b\n", 31);
//			printf("(%li:%u)	(%li:%u)\n", stack_a->nb, stack_a->index, stack_b->nb, stack_b->index);//WATCH OUT YOU USE A FORBIDDEN FUNCTION
			printf("| %li  :  %u |     | %li  :  %u |\n", stack_a->nb, stack_a->index, stack_b->nb, stack_b->index);//WATCH OUT YOU USE A FORBIDDEN FUNCTION
			stack_a = stack_a->next;
			stack_b = stack_b->next;
		}
		else if (stack_a)
		{
//			write(1, "Entered in stack_a\n", 19); 
//			printf("(%li:%u)\n", stack_a->nb, stack_a->index);//WATCH OUT YOU USE A FORBIDDEN FUNCTION
			printf("| %li  :  %u |\n", stack_a->nb, stack_a->index);//WATCH OUT YOU USE A FORBIDDEN FUNCTION
			stack_a = stack_a->next;
		}
		else if (stack_b)
		{
			//printf("Entered in stack_b"); 
//			write(1, "Entered in stack_b\n", 19); 
//			printf(" 	(%li:%u)\n", stack_b->nb, stack_b->index);//WATCH OUT YOU USE A FORBIDDEN FUNCTION
			printf("                | %li  :  %u |\n", stack_b->nb, stack_b->index);//WATCH OUT YOU USE A FORBIDDEN FUNCTION
			stack_b = stack_b->next;
		}
    }
}
