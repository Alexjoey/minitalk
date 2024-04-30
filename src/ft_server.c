#include "../inc/minitalk.h"

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
	static int	bit;
	static int	i;
	static int	strlen;
	static char *str;
	static int	j;

	if (!strlen || strlen == 0)
		strlen = ft_receive_strlen(signal);
	else
	{
		if (!str)
			str = ft_calloc(strlen + 1, sizeof(char));
		if (signal == SIGUSR2)
			i |= (0x01 << bit);
		bit++;
		if (bit == 8)
		{
			ft_printf("%c, %d\n", (char)i, strlen);
			str[j] = (char)i;
			j++;
			bit = 0;
			i = 0;
		}
		//ft_printf("current string val: %s	\ncurrent j val: %d\n", str, j);
		if (j == strlen)
		{
			ft_printf("%s", str);
			j = 0;
			strlen = 0;
			free (str);
		}
	}
}

int	main(int argc, char **argv)
{
	int	pid;

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
	signal(SIGUSR1, ft_handler);
	signal(SIGUSR2, ft_handler);
	while (1)
	{
		usleep(WAIT_TIME);
	}
	return (0);
}
