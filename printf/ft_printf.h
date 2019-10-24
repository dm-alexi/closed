/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sscarecr <sscarecr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/05 16:19:30 by sscarecr          #+#    #+#             */
/*   Updated: 2019/10/24 22:13:23 by sscarecr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include "ft_bigint.h"
# include "libft/libft.h"

typedef struct	s_format
{
	int		width;
	int		prec;
	char	length;
	char	type;
	char	sign;
	char	rpad;
	char	sharp;
	char	fill;
	char	apost;
}				t_format;

int				ft_printf(const char *format, ...);
int				ft_printf_pad(int fd, char c, int n);
int				ft_printf_percent(t_format *format);
int				ft_printf_string(t_format *format, va_list *va);
int				ft_printf_char(t_format *format, va_list *va);
int				ft_printf_int(t_format *format, va_list *va);
int				ft_printf_uint(t_format *format, va_list *va);
int				ft_printf_ptr(t_format *format, va_list *va);
int				ft_printf_float(t_format *format, va_list *va);
void			printbin(void *p, int n);
int				ft_printf_efg(t_format *format, t_bigint *t, int exp, char **s);
int				ft_printf_n(va_list *va, int n);
int				ft_printf_r(t_format *format, va_list *va);
int				ft_utoa(uintmax_t n, char **s, t_format *format);
int				ft_otoa(uintmax_t n, char **s, t_format *format);
int				ft_xtoa(uintmax_t n, char **s, t_format *format);
int				ft_round(char *s, int len, int hollow);
int		ft_process_e(char **s, int exp, int len, t_format *format);
int		ft_printf_e(t_format *format, int len, char *str, char **s);
int		ft_process_ge(char **s, int exp, int len, t_format *format);
int			ft_printf_ge(t_format *format, int len, char *str, char **s);

#endif
