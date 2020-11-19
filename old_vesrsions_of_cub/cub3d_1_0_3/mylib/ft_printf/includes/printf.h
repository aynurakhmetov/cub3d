/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmarva <gmarva@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/11 05:25:25 by gmarva            #+#    #+#             */
/*   Updated: 2020/08/13 21:45:14 by gmarva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_H
# define PRINTF_H
# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <inttypes.h>
# include "libft.h"

typedef struct	s_prdata
{
	int		flags;
	int		width;
	int		precision;
	char	type;
	int		length;
}				t_prdata;

int				di_pr_two_two(int num, t_prdata data, int m, int k);
int				p_flag_print(int len, char *s, t_prdata data);
int				p_flag_print_one(int len, char *s, int k, t_prdata data);
int				ft_percent_print(t_prdata data);
int				x_flag_two_print(int len,
		int k, unsigned int num, t_prdata data);
int				ft_u_two(int len, unsigned int num, int k, t_prdata data);
int				ft_proc_two(va_list *ap, t_prdata data, int k);
int				ft_xtest(unsigned int num, int flags, int pr);
int				ft_utest(unsigned int num, int flags, int pr);
int				di_pr_three(int num, t_prdata data, int m, int k);
int				minus_print(int num, t_prdata data);
int				di_pr_two(int num, t_prdata data, int m, int k);
int				di_pr_one(int num, t_prdata data, int m, int k);
int				ft_ditest(int num, int flags, int pr);
int				ft_putdi(int num, int fd, int flags, int pr);
int				ft_flagnprint(int w, int p, int len);
int				ft_flagtprint(int w, int len);
void			*ft_memalloc(size_t size);
int				places(unsigned long long n);
char			*ft_ptoa(void *p, char c);
int				ft_p_print(va_list *ap, t_prdata data);
int				ft_x_print(va_list *ap, t_prdata data);
int				x_print(unsigned int num, char type);
int				ft_u_print(va_list *ap, t_prdata data);
int				ft_s_print(va_list *ap, t_prdata data);
void			s_print(char *s, int n);
int				ft_c_print(va_list *ap, t_prdata data);
int				null_print(int n);
int				wp_print(int n, int k, int len);
int				ft_di_print(va_list *ap, t_prdata data);
int				ft_typeprint(va_list *ap, t_prdata data);
int				ft_process(va_list *ap, t_prdata data);
char			ft_type(const char *fmt, int i);
int				ft_flags(const char *fmt, int i, char type);
int				ft_length(const char *fmt, int i, char type);
int				ft_width(const char *fmt, int i, char type);
int				ft_precision(const char *fmt, int i, char type);
t_prdata		ft_parser(const char *fmt, int i);
int				ft_printf(const char *format, ...);

#endif
