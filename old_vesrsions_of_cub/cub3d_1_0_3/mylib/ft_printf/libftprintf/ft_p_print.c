/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_p_print.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmarva <gmarva@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/02 20:19:23 by gmarva            #+#    #+#             */
/*   Updated: 2020/08/13 21:16:19 by gmarva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	*ft_p_malloc(size_t n)
{
	void *s;

	s = malloc(n);
	if (s == NULL)
		return (NULL);
	else
		ft_bzero(s, n);
	return (s);
}

int		ft_plen(unsigned long long n)
{
	int i;

	i = 0;
	if (n == 0)
		return (1);
	while (n != 0)
	{
		n = n / 16;
		i++;
	}
	return (i);
}

char	*ft_ptoa(void *p, char c)
{
	char				*s;
	unsigned long long	n;
	int					i;

	n = (unsigned long long)p;
	i = ft_plen(n);
	if (!(s = (char*)ft_p_malloc(i + 1)))
		return (NULL);
	if (p == NULL)
		s[0] = '0';
	while (n)
	{
		if (n % 16 > 9)
			s[--i] = n % 16 - 10 + c;
		else
			s[--i] = n % 16 + '0';
		n = n / 16;
	}
	return (s);
}

int		p_flag_print(int len, char *s, t_prdata data)
{
	if (data.flags % 10 == 1)
	{
		len = len + 2;
		if (data.precision > len)
			len = wp_print(0, data.precision, len);
		ft_putstr_fd("0x", 1);
		if (s != 0)
			ft_putstr_fd(s, 1);
		if (data.width > len)
			len = wp_print(data.width, 0, len);
	}
	if (data.flags % 10 == 2)
	{
		len = len + 2;
		len = ft_flagtprint(data.width, len);
		ft_putstr_fd("0x", 1);
		if (s != 0)
			ft_putstr_fd(s, 1);
	}
	return (len);
}

int		ft_p_print(va_list *ap, t_prdata data)
{
	int		len;
	void	*p;
	char	*s;
	int		k;

	k = 0;
	p = va_arg(*ap, void*);
	if (p == NULL && data.flags >= 1000 && data.precision == 0)
		s = 0;
	else
		s = ft_ptoa(p, 'a');
	len = ft_strlen(s);
	len = p_flag_print_one(len, s, k, data);
	free(s);
	return (len);
}
