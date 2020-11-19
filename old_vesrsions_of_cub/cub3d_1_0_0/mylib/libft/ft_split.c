/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmarva <gmarva@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/20 13:11:17 by gmarva            #+#    #+#             */
/*   Updated: 2020/05/30 15:16:38 by gmarva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_numofline(char const *s, char c, size_t lens)
{
	int		numl;
	size_t	i;

	numl = 0;
	i = 0;
	while (i <= lens)
	{
		if (s[i] != c && s[i] != '\0')
		{
			while (s[i] != c && s[i] != '\0')
				i++;
			numl++;
			continue ;
		}
		i++;
	}
	return (numl);
}

static char	**ft_makestr(char **str, char const *s, char c, size_t lens)
{
	int		j;
	int		k;
	size_t	i;

	i = 0;
	j = 0;
	k = 0;
	while (i <= lens)
	{
		j = 0;
		if (s[i] != c && s[i] != '\0')
		{
			while (s[i] != c && s[i] != '\0')
			{
				str[k][j] = s[i];
				j++;
				i++;
			}
			str[k][j] = '\0';
			k++;
			continue ;
		}
		i++;
	}
	return (str);
}

static char	**ft_free(char **str, int k)
{
	int	i;

	i = 0;
	while (i <= k)
	{
		free(str[i]);
		i++;
	}
	free(str);
	return (NULL);
}

static void	ft_numofch(char const *s, char **str, size_t lens, char c)
{
	int		j;
	int		k;
	size_t	i;

	i = 0;
	k = 0;
	while (i <= lens)
	{
		j = 0;
		if (s[i] != c && s[i] != '\0')
		{
			while (s[i] != c && s[i] != '\0')
			{
				i++;
				j++;
			}
			if (!(str[k] = (char *)malloc((j + 1) * sizeof(char))))
				str = ft_free(str, k);
			k++;
		}
		i++;
	}
	str[k] = 0;
}

char		**ft_split(char const *s, char c)
{
	char	**str;
	int		numl;
	size_t	lens;

	if (!s)
		return (NULL);
	lens = ft_strlen(s);
	numl = ft_numofline(s, c, lens);
	if (!(str = (char **)malloc((numl + 1) * sizeof(char *))))
		return (NULL);
	ft_numofch(s, str, lens, c);
	return (ft_makestr(str, s, c, lens));
}
