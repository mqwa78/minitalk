
#include "../include/minitalk.h"

void	ft_btoc(int sig)
{
	static int	bit;
	static int	c;

	if (sig == SIGUSR1)
		c |= (0x01 << bit);
	bit++;
	if (bit == 8)
	{
		ft_printf("%c", c);
		bit = 0;
		c = 0;
	}
}

int	main(int ac, char **av)
{	
	int	pid;

	(void)av;
	if (ac != 1)
	{
		ft_printf("Error\n");
		return (1);
	}
	pid = getpid();
	ft_printf("%d\n", pid);
	while (ac == 1)
	{
		signal(SIGUSR1, ft_btoc);
		signal(SIGUSR2, ft_btoc);
		pause();
	}
	return (0);
}