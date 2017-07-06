#include "libft.h"

char		*ft_strnchr(char *str, int c)
{
	char		*tmp;
	size_t		length;
	int		i;	

	if (!(str))	
		return (NULL);
	length = ft_strlen(str);
	if (!(tmp = (char *)malloc(sizeof(char) * length + 1)))
		return (NULL);
	ft_bzero(tmp, length);
	i = -1;
	while (str[++i] && str[i] != c)
		tmp[i] = str[i];	
	tmp[i + 1] = '\0';
	return (tmp);
}
