/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_client.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amylle <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 17:10:46 by amylle            #+#    #+#             */
/*   Updated: 2024/05/04 17:10:48 by amylle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static bool	is_input_valid(int argc, char **argv)
{
	int	i;

	if (argc != 3)
		return (false);
	i = -1;
	while (argv[1][++i])
		if (!ft_strchr("0123456789", argv[1][i]))
			return (false);
	return (true);
}

static void	ft_send_char(unsigned char c, int pid)
{
	int	bit;

	bit = -1;
	while (++bit < 8)
	{
		if (c & 1)
			kill(pid, SIGUSR2);
		else
			kill(pid, SIGUSR1);
		c = c >> 1;
		usleep(WAIT_TIME);
	}
}

int	main(int argc, char **argv)
{
	int		pid;
	int		i;

	if (is_input_valid(argc, argv) == false)
	{
		ft_printf("Wrong input, should be ./client pid message\n");
		return (-1);
	}
	pid = ft_atoi(argv[1]);
	if (pid <= 0)
	{
		ft_printf("Invalid process id\n");
		return (-1);
	}
	i = -1;
	while (argv[2][++i])
		ft_send_char(argv[2][i], pid);
	ft_send_char(argv[2][i], pid);
}
