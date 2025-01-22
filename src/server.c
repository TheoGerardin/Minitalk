#include "../includes/minitalk.h"

void	cat_msg(int msg, int j, int act)
{
	static char		*c = NULL;
	static int		i = 0;

	c = (char *)ft_realloc(c, i + 1, j + 2);
	if (c == NULL)
		exit(1);
	c[i] = (char)msg;
	i++;
	if (act == 1)
	{
		c[i] = '\0';
		ft_putstr(c);
		free(c);
		c = NULL;
		i = 0;
	}
}

void	ft_handler(int signal)
{
	static int	bit;
	static int	i;
	static int	j;

	if (signal == SIGUSR1)
		i |= (0x01 << bit);
	bit++;
	if (bit == 8)
	{
		if (i == 0x0A)
		{
			cat_msg(i, j, 1);
		}
		j++;
		cat_msg(i, j, 0);
		bit = 0;
		i = 0;
	}
}

int	main(void)
{
	int		pid;

	pid = getpid();
	ft_putstr("PID : ");
	ft_putnbr(pid);
	ft_putchar('\n');
	while (1)
	{
		signal(SIGUSR1, ft_handler);
		signal(SIGUSR2, ft_handler);
		pause();
	}
	return (0);
}
