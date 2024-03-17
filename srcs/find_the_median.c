/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_the_median.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: simarcha <simarcha@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/10 17:23:33 by simarcha          #+#    #+#             */
/*   Updated: 2024/03/17 19:49:09 by simarcha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

char	**array_numbers(t_list *stack_a)
{
	int		lstsize;
	char	**array;
	int		x;

	x = 0;
	lstsize = ft_lstsize(stack_a);
	array = malloc((lstsize + 1) * sizeof(*array));
	if (!array)
		return (exit(1), NULL);
	while (x < lstsize)
	{
		array[x] = ft_itoa(stack_a->nb);
		if (!array[x])
			array = free_array(array);
		x++;
		stack_a = stack_a->next;
	}
	array[x] = NULL;
	return (array);
}

static int	ft_atoi(const char *str)
{
	int		a;
	int		i;
	int		sign;

	i = 0;
	a = 0;
	sign = 1;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-' && sign == 1)
			sign *= -1;
		i++;
	}
	while (str[i] >= 48 && str[i] <= 57)
		a = a * 10 + (str[i++] - 48);
	return (a * sign);
}

//create a function to find the lower value of your array of numbers
static int	find_min(char **array)
{
	int	x;
	int	min;

	x = 0;
	min = ft_atoi(array[x]);
	while (array[x])
	{
		if (ft_atoi(array[x]) < min)
			min = ft_atoi(array[x]);
		x++;
	}
	return (min);
}

//we need a function to find the median
//we will divide the listsize by 2 to know when we stop to look for the min
//each time we found the min, we put the min to the value of 2147483648 
//=> to be sure it can not be the min anymore, until when we found the min 
//for the (listsize / 2)nth value, then it means that we found it.
int	find_the_median(char **array, int lstsize, int median)
{
	int	x;
	int	min;
	int	tmp;

	if (lstsize % 2 == 0)
		median = lstsize / 2;
	else
		median = (lstsize / 2) + 1;
	while (median--)
	{
		min = find_min(array);
		x = 0;
		while (array[x])
		{
			if (ft_atoi(array[x]) == min)
			{
				tmp = ft_atoi(array[x]);
				free(array[x]);
				array[x] = ft_strdup("2147483647");
				break ;
			}
			x++;
		}
	}
	return (tmp);
}
