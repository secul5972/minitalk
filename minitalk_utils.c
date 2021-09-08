/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungcoh <seungcoh@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/08 13:50:13 by seungcoh          #+#    #+#             */
/*   Updated: 2021/09/08 19:17:10 by seungcoh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	ft_atoi(const char *str)
{
	size_t	i;
	long	ret;

	i = 0;
	ret = 0;
	while ('0' <= str[i] && str[i] <= '9')
	{
		ret *= 10;
		ret += str[i] - '0';
		i++;
	}
	if (str[i] != 0 || ret < 100)
		ret = 0;
	return (ret);
}

char	*ft_itoa(int n)
{
	int		size;
	char	*ret;
	int		temp;

	temp = n;
	size = 1;
	while (temp / 10)
	{
		size++;
		temp /= 10;
	}
	ret = (char *)malloc(sizeof(char) * (size + 1));
	if (!ret)
		return (0);
	ret[size--] = 0;
	while (size >= 0)
	{
		ret[size--] = n % 10 + '0';
		n /= 10;
	}
	return (ret);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}
