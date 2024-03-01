/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: simarcha <simarcha@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 14:06:14 by simarcha          #+#    #+#             */
/*   Updated: 2024/02/26 14:11:42 by simarcha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//We need a function for counting the words
//We need a function to draw our matrix with the good numbers of cells
//we need a function to copy the exact same letters in our matrix
//we need a function to free everything if it fails
//we need a function to gather everything

int	countwords(const char *s, char c)
{
	int	wc;
	int	i;
	int	check;

	wc = 0;
	i = 0;
	check = 0;
	while (s[i])
	{
		if (s[i] == c && check != 0)
		{
			wc++;
			check = 0;
		}
		else if (s[i] != c)
			check++;
		i++;
	}
	if (check > 0)
		wc++;
	return (wc);
}

char	**draw_array(char **array, const char *s, char c)
{
	int		i;
	int		x;
	int		count;

	i = 0;
	count = 0;
	x = 0;
	while (s[i])
	{
		if (s[i] != c)
			count++;
		if ((s[i] == c && count > 0) || (s[i] != c && s[i + 1] == '\0'))
		{
			array[x] = malloc((count + 1) * sizeof(char));
			if (!array[x])
				return (NULL);
			x++;
			count = 0;
		}
		i++;
	}
	return (array);
}

char	**complete_array(char **array, const char *s, char c)
{
	int	i;
	int	x;
	int	y;

	i = 0;
	x = 0;
	y = 0;
	while (s[i])
	{
		if (s[i] != c)
			array[x][y++] = s[i];
		if ((s[i] == c && i > 0 && s[i - 1] != c)
			|| (s[i] != c && s[i + 1] == 0))
		{
			array[x][y] = '\0';
			x++;
			y = 0;
		}
		i++;
	}
	return (array);
}

char	**free_array(char **array)
{
	int	x;

	x = 0;
	while (array[x])
	{
		free(array[x]);
		array[x] = NULL;
		x++;
	}
	free(array);
	array = NULL;
	return (array);
}

char	**ft_split(const char *s, char c)
{
	char	**array;
	int		wc;

	wc = countwords(s, c);
	array = malloc((wc + 1) * sizeof(*array));
	if (!array)
		return (NULL);
	if (draw_array(array, s, c))
	{
		complete_array(array, s, c);
		array[wc] = NULL;
	}
	else
		array = free_array(array);
	return (array);
}

/*
#include <stdio.h>
#include <string.h>
int main(void)
{
	char	str[90] = "";
	char	**array;
	int		x;

//	printf("%zu\n", strlen(str));
//	printf("%i\n", countwords(str, ' '));
	x = 0;
	array = ft_split(str, ' ');
	while (array[x])
	{
		printf("%s\n", array[x]);
		x++;
	}
	return (0);
}*/
