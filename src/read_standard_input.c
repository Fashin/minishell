#include "../minishell.h"

char			*read_standard_input(void)
{
	char		buff[BUFFSIZE];
	char		*ret;
	
	if (!(ret = (char *)malloc(sizeof(char) * BUFFSIZE)))
		return (NULL);
	ft_bzero(ret, 1);
	ft_bzero(buff, BUFFSIZE);
	while (read(0, buff, BUFFSIZE - 1) > -1)
	{
		ret = ft_strjoin(ret, buff);
		ft_strclr(buff);
		if (ft_strchr(ret, '\n'))
			return (ret);
	}
	return (NULL);
}
