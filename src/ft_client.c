#include "minitalk.h"

static void	ft_input_error(int argc, char **argv)
{
	int	i;

	if (argc != 3)
		return (false);
	i = 0;
	while (argv[1][++i])
		if (!ft_strchr("0123456789", argv[1][i]))
			return (false);
	return (true);
}

static void	ft_send_strlen(int len, int pid)
{
	int	i;

	i = -1;
	while (++i < 32)
	{
		if (len & 0x01)
			kill(pid, SIGUSR2);
		else
			kill(pid, SIGUSR1);
		len = len >> 1;
		usleep(WAIT_TIME);
	}
}

static void	ft_send_char(unsigned char c, int pid)
{
	int	bit;

	i = -1;
	while (++bit < 8)
	{
		if (c & 0x01)
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
	int		len;
	int		i;

	if (ft_inputerror(argc, argv) == false)
		return (-1);
	pid = ft_atoi(argv[1]);
	if (pid <= 0)
		return (-1);
	len = ft_strlen(argv[2]);
	i = -1;
	ft_send_strlen_bit_by_bit(len, pid);
	while (argv[2][++i])
		ft_send_next_char_bit_by_bit(argv[2][i], pid);
	ft_send_next_char_bit_by_bit(argv[2][i], pid);
}
