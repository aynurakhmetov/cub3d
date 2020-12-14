#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	size_t counter;

	counter = 0;
	if (!str)
		return (0);
	while (str[counter] != '\0')
		counter++;
	return (counter);
}

void	*ft_memmove(void *des, const void *src, size_t n)
{
	unsigned char	*to;
	unsigned char	*from;
	size_t			i;

	i = 0;
	if (!des && !src)
		return (NULL);
	to = (unsigned char *)des;
	from = (unsigned char *)src;
	if (to < from)
	{
		while (i < n)
		{
			to[i] = from[i];
			i++;
		}
	}
	if (to > from)
	{
		while (n-- > 0)
			to[n] = from[n];
	}
	return (des);
}

char	*ft_strdup(const char *str)
{
	size_t	len;
	size_t	j;
	char	*dup;

	j = 0;
	len = ft_strlen(str);
	if (!(dup = (char *)malloc((len + 1) * sizeof(char))))
		return (0);
	while (j < len)
	{
		dup[j] = str[j];
		j++;
	}
	dup[j] = '\0';
	return (dup);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	size_t	i;
	size_t	j;
	size_t	s1len;
	size_t	s2len;

	j = 0;
	if (!s1 && !s2)
		return (0);
	s1len = ft_strlen(s1);
	s2len = ft_strlen(s2);
	if (!(str = (char *)malloc((s1len + s2len + 1) * sizeof(char))))
	{
		free((char *)s1);
		return (0);
	}
	i = -1;
	while (++i < s1len)
		str[i] = s1[i];
	while (j < s2len)
		str[i++] = s2[j++];
	str[i] = '\0';
	free((char *)s1);
	return (str);
}

char	*ft_strchr(const char *str, int ch)
{
	int	i;

	i = 0;
	while (str[i] != ch)
	{
		if (str[i] == '\0')
			return (NULL);
		i++;
	}
	if (str[i] == ch)
		return ((char *)&str[i]);
	return (NULL);
}
