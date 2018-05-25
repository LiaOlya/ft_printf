/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oltkache <oltkache@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/14 12:00:52 by oltkache          #+#    #+#             */
/*   Updated: 2018/02/16 16:03:19 by oltkache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __FT_PRINTF_H
# define __FT_PRINTF_H

# include "libft.h"
# include <stdarg.h>
# include <wchar.h>

# define UNDEF "QwWrRTyYIPHJkKZVbBNmM<>=!$^&(){}[]/–"
# define CONV "sSpdDioOuUxXcC%"

void		ft_d(char *str, long long a, int j, int *k);
void		ft_u(char *str, unsigned long long a, int j, int *k);
void		ft_x(char *str, unsigned long long a, int j, int *s);
void		ft_o(char *str, unsigned long long a, int j, int *s);
void		ft_c(char *str, unsigned int a, int j, int *k);
void		ft_s(char *str, wchar_t *a, int j, int *s);
void		ft_pc(char *str, int j, int *s);
void		ft_p(char *str, unsigned long long a, int j, int *s);
void		ft_un(char y, char *str, int *j);
void		ft_cast_u(unsigned long long *a, char *str, int c, char s);
int			ft_cast(long long *a, char *str, int c);
int			ft_increm_1(int *f, int *i);
void		ft_spaces(int p, int n);
void		ft_putnbr_long_u(unsigned long long n);
void		ft_putnbr_long(long long n);
int			ft_num_len_u(unsigned long long num, unsigned int sys);
int			ft_num_len(long long num, unsigned int sys);
void		ft_putstr_u(wchar_t *str, int *l);
void		ft_putchar_u(unsigned int n, int *s);
char		ft_undef(char str, int *k);
char		*ft_hex(unsigned long long a, int *l, char c);
int			ft_increm_2(char *str, int *f, int *i, int ch);
int			*ft_loop(int p, char *str, int c);
char		ft_hex_ch(int b, int a, char h, int ch);
int			ft_conversions(char *a);
int			ft_flags(char *s, char *r, int *p);
wchar_t		*ft_sub_u(wchar_t *s, int l);
int			ft_strlen_u(wchar_t *l);
int			*ft_intnew(int size);
int			ft_h_d(int a, int *l, int d, int *k);
void		ft_sign(int d);

#endif
