#include "../inc/minitalk.h"

int	g_timer;

int	ft_receive_strlen(int signal)
{
	static int	i;
	static int	bit;
	int			temp;

	if (!i)
		i = 0;
	if (signal == SIGUSR2)
		i |= (1 << bit);
	bit++;
	if (bit == 32)
	{
		temp = i;
		i = 0;
		return (temp);
	}
	return (0);
}

void	ft_handler(int signal)
{
	static int	i;
	static int	bit;

	if (g_timer > 1)
	{
		bit = 0;
		i = 0;
	}
	if (signal == SIGUSR2)
		i |= (0x01 << bit);
	bit++;
	if (bit == 8)
	{
		write(1, &i, 1);
		bit = 0;
		i = 0;
	}
	timer = 0;
}

int	main(int argc, char **argv)
{
	int					pid;
	struct sigaction	sa;

	sa.sa_handler = ft_handler;
	sigemptyset(&sa.sa_mask);
	sa.sa_flags = SA_RESTART;
	(void)argv;
	if (argc != 1)
	{
		ft_printf("\033[91mError: wrong format.\033[0m\n");
		ft_printf("\033[33mTry: ./server\033[0m\n");
		return (0);
	}
	pid = getpid();
	ft_printf("\033[94mPID\033[0m \033[96m->\033[0m %d\n", pid);
	ft_printf("\033[90mWaiting for a message...\033[0m\n");
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1)
	{
		sleep(1);
		g_timer++;
	}
	return (0);
}
