/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungcoh <seungcoh@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/08 13:37:21 by seungcoh          #+#    #+#             */
/*   Updated: 2021/09/08 19:13:37 by seungcoh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	send_signal(int pid, char *str)
{
	int		i;
	int		digit;
	int		flag;
	char	curr;

	i = 0;
	flag = 1;
	while (flag)
	{
		if (str[i] == 0)
			flag = 0;
		digit = 128;
		curr = str[i++];
		while (digit > 0)
		{
			if (curr / digit)
				kill(pid, SIGUSR1);
			else
				kill(pid, SIGUSR2);
			curr %= digit;
			digit /= 2;
			usleep(1000);
		}
	}
}

int	main(int argv, char **argc)
{
	int	flag;
	int	pid;

	flag = 0;
	if (argv != 3)
		flag = 1;
	pid = atoi(argc[1]);
	if (pid < 0)
		flag = 1;
	if (flag)
	{
		write(1, "parameter error\n", 17);
		return (0);
	}
	send_signal(pid, argc[2]);
}
