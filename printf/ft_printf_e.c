/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_e.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sscarecr <sscarecr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/24 21:34:06 by sscarecr          #+#    #+#             */
/*   Updated: 2019/10/25 23:22:23 by sscarecr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	explen(int exp)
{
	int		i;

	i = 1;
	while ((exp /= 10) && ++i)
		;
	return (i > 2 ? i : 2);
}

int			ft_process_e(char **s, int exp, int len, t_format *format)
{
	char	*str;
	int		total;
	int		i;

	exp += len - 1;
	if (((format->prec + 1 < len) &&
		(ft_round(*s, len, len - 1 - format->prec)) > format->prec + 1))
		++exp;
	i = len - 1 > format->prec ? format->prec : len - 1;
	total = format->prec + (format->sharp || format->prec) + 3 + explen(exp);
	if (!(str = ft_memalloc(total)))
		return (-1);
	*str = **s;
	str[1] = (format->sharp || format->prec) ? '.' : 0;
	ft_memcpy(str + 1 + (format->sharp || format->prec), *s + 1, i);
	str[format->prec + (format->sharp || format->prec) + 1] = format->type;
	str[format->prec + (format->sharp || format->prec) + 2] = exp >= 0 ?
		'+' : '-';
	i = total;
	exp = exp >= 0 ? exp : -exp;
	while (exp && (str[--i] = exp % 10 + '0'))
		exp /= 10;
	free(*s);
	*s = str;
	return (total);
}

int			ft_printf_e(t_format *format, int len, char *str, char **s)
{
	int		i;
	int		total;

	i = -1;
	while (++i < len)
		if (str[i] >= 0 && str[i] <= 9)
			str[i] += '0';
	total = len + (format->sign != 0);
	if (format->width < total)
		format->width = total;
	if (!(*s = (char*)malloc(format->width)))
		return (-1);
	ft_memset(*s, format->fill, format->width);
	ft_memcpy(*s + (format->rpad ?
		(format->sign != 0) : format->width - len), str, len);
	if (format->sign)
		(*s)[**s == '0' || format->rpad ? 0 : format->width - len - 1] =
		format->sign;
	return (format->width);
}

static int	cut_tail(char *s, int total)
{
	while (s[total - 1] == 0)
		--total;
	return (total);
}

int		ft_process_ge(char **s, int exp, int len, t_format *format)
{
	char	*str;
	int		total;
	int		i;

	exp += len - 1;
	if (((--(format->prec) + 1 < len) &&
		(ft_round(*s, len, len - 1 - format->prec)) > format->prec + 1))
		++exp;
	i = len - 1 > format->prec ? format->prec : len - 1;
	total = format->prec + (format->sharp || format->prec) + 3 + explen(exp);
	if (!(str = ft_memalloc(total)))
		return (-1);
	*str = **s;
	len = cut_tail(*s, len);
	str[1] = (format->sharp || format->prec) ? '.' : 0;
	ft_memcpy(str + 1 + (format->sharp || format->prec), *s + 1, i);
	str[format->prec + (format->sharp || format->prec) + 1] = format->type - 2;
	str[format->prec + (format->sharp || format->prec) + 2] = exp >= 0 ?
		'+' : '-';
	i = total;
	exp = exp >= 0 ? exp : -exp;
	while (exp && (str[--i] = exp % 10 + '0'))
		exp /= 10;
	free(*s);
	*s = str;
	return (total);
}
