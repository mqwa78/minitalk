
#include "../include/minitalk_bonus.h"

void	ft_btoc(int sig, siginfo_t *info, void *context)
{
	static int	bit;
	static int	c;

    (void)context;
	if (sig == SIGUSR1)
		c |= (0x01 << bit);
	bit++;
	if (bit == 8)
	{   
        if (c == 0)	
            kill(info->si_pid, SIGUSR2);
		ft_printf("%c", c);
		bit = 0;
		c = 0;
	}

}

int	main(int ac, char **av)
{
	int	pid;
	struct sigaction	act;

	(void)av;
	if (ac != 1)
	{
		ft_printf("Error\n");
		return (1);
	}
	pid = getpid();
	ft_printf("%d\n", pid);
	act.sa_sigaction = ft_btoc;
	sigemptyset(&act.sa_mask);
	act.sa_flags = SA_SIGINFO;
	while (ac == 1)
	{
		sigaction(SIGUSR1, &act, NULL);
		sigaction(SIGUSR2, &act, NULL);
		pause();
	}
	return (0);
}
