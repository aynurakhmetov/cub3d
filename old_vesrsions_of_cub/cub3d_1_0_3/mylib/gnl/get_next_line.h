/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmarva <gmarva@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/03 01:29:21 by gmarva            #+#    #+#             */
/*   Updated: 2020/08/08 21:46:41 by gmarva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>
# include <string.h>

int		get_next_line(int fd, char **line);
size_t	ft_strlen(const char *str);
char	*ft_strdup(const char *str);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strchr(const char *str, int ch);
void	*ft_memmove(void *des, const void *src, size_t n);
int		ft_get_i(char *src);
char	*ft_newline(char *src);
char	*ft_newmem(char *src);

#endif
