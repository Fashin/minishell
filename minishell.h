#ifndef MINISHELL_H
# define MINISHELL_H
# define BUFFSIZE 20
# include "libft/libft.h"
# include <stdlib.h>
# include <stdio.h>

typedef struct			s_env
{
	char			*name;
	struct s_env		*next;
}				t_env;

char			*ft_read_standard_input(void);
char			**search_command(char *str);
int			resolve_command(char **cmds);
#endif
