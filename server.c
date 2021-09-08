/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungcoh <seungcoh@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/08 14:14:09 by seungcoh          #+#    #+#             */
/*   Updated: 2021/09/08 21:44:56 by seungcoh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	signal_handler(int sig)
{
	static int	cnt;
	static char	ch;

	ch *= 2;
	cnt++;
	if (sig == SIGUSR1)
		ch++;
	if (cnt == 8)
	{
		cnt = 0;
		if (ch == 0)
			write(1, "\n", 1);
		else
			write(1, &ch, 1);
		ch = 0;
	}
}

int	main(void)
{
	int		pid;
	char	*c_pid;

	pid = getpid();
	c_pid = ft_itoa(pid);
	if (c_pid == 0)
	{
		write(2, "malloc error\n", 14);
		return (0);
	}
	write(1, "server pid : ", 14);
	write(1, c_pid, ft_strlen(c_pid));
	write(1, "\n", 1);
	free(c_pid);
	while (1)
	{
		if (signal(SIGUSR1, signal_handler) == SIG_ERR)
			exit(1);
		if (signal(SIGUSR2, signal_handler) == SIG_ERR)
			exit(1);
	}
}
