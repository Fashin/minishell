#include "../minishell.h"

static char		*clean_up_tabs(char *str)
{
	int		i;
	size_t		length;
	char		*tmp;

	length = ft_strlen(str) + 1;
	i = -1;
	if (!(tmp = (char *)malloc(sizeof(char) * length)))
		return (NULL);
	ft_bzero(tmp, length);
	while (str[++i])
		tmp[i] = (str[i] == '\t') ? ' ' : str[i];
	ft_strcpy(str, tmp);
	free(tmp);
	return (str);
}

char			**search_command(char *cmd)
{
	char	**ret;
	int	i;

	i = -1;
	ret = NULL;
	clean_up_tabs(cmd);
	ret = ft_strsplit(cmd, ' ');
	while (ret[++i])
	{
		printf("ret = %s\n", ret[i]);		
	}
	return (ret);
}
