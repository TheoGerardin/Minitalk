#include "../includes/minitalk.h"

void	send_msg(int pid, char i)
{
	int	bit;

	bit = 0;
	while (bit < 8)
	{
		if ((i & (0x01 << bit)) != 0)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		usleep(1000);
		bit++;
	}
}

int	main(int argc, char **argv)
{
	int	pid;
	int	i;

	(void)argc;
	i = 0;
	if (argc != 3)
	{
		ft_putstr("Use : ./client <PID> <MESSAGE>.\n");
		return (1);
	}
	pid = ft_atoi(argv[1]);
	while (argv[2][i])
	{
		send_msg(pid, argv[2][i]);
		i++;
	}
	send_msg(pid, '\n');
}
