#include "../minishell.h"

int	main(int ac, char **av, char **env)
{
	char		*cmd;
	(void)ac;
	(void)av;
	(void)env;
	while (1)
	{
		ft_putstr("$ > ");
		cmd = ft_read_standard_input();
		resolve_command(search_command(cmd));
	}
}
