
#include "../include/minitalk_bonus.h"

void	confirm(int signal)
{	
	if (signal == SIGUSR2)
		ft_printf("message recieved\n");
}

int	ft_atoi(const char *str)
{
	int					i;
	int					m;
	unsigned long int	res;

	i = 0;
	m = 1;
	res = 0;
	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			m = -m;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		res *= 10;
		res += str[i] - '0';
		i++;
	}
	return (res * m);
}

void	ft_ctob(int pid, char c)
{
	int	bit;

	bit = 0;
	while (bit < 8)
	{
		if ((c & (0x01 << bit)))
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		usleep(500);
		bit++;
	}
}

int	main(int ac, char **av)
{	
	int	pid;
	int	i;

	i = 0;
	if (ac == 3)
	{	
		signal(SIGUSR2, &confirm);
		pid = ft_atoi(av[1]);
		while (av[2][i])
		{
			ft_ctob(pid, av[2][i]);
			i++;
		}
		ft_ctob(pid, '\n');
		ft_ctob(pid, '\0');
	}
	else
	{
		ft_printf("Error\n");
		return (1);
	}
	return (0);
}
