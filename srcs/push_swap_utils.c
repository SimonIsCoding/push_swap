/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: simarcha <simarcha@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 18:47:44 by simarcha          #+#    #+#             */
/*   Updated: 2024/03/13 18:15:37 by simarcha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

long int	ft_atol(const char *str)
{
	long int	a;
	int			i;
	long int	sign;

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

char	*ft_strdup(const char *str)
{
	char	*dst;
	size_t	i;

	i = -1;
	dst = (char *)malloc((ft_strlen(str) + 1) * sizeof(char));
	if (!dst)
		return (NULL);
	while (str[++i] != '\0')
		dst[i] = str[i];
	dst[i] = '\0';
	return (dst);
}

size_t	itoa_helper(long num)
{
	size_t	ctr;

	ctr = 0;
	while (num < 0)
	{
		num *= -1;
		ctr++;
	}
	while (num > 0)
	{
		num /= 10;
		ctr++;
	}
	return (ctr);
}

char	*ft_itoa(long int n)
{
	char	*str;
	long	tmp;
	size_t	len;

	tmp = n;
	len = itoa_helper(tmp);
	if (n == 0)
		return (ft_strdup("0"));
	str = malloc((len + 1) * (sizeof(char)));
	if (!str)
		return (NULL);
	str[len--] = '\0';
	if (tmp < 0)
	{
		tmp *= -1;
		str[0] = '-';
	}
	while (tmp > 0)
	{
		str[len--] = (tmp % 10) + '0';
		tmp /= 10;
	}
	return (str);
}
