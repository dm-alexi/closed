/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_int.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sscarecr <sscarecr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/05 16:22:02 by sscarecr          #+#    #+#             */
/*   Updated: 2019/10/17 23:36:47 by sscarecr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include <stddef.h>
#include <stdint.h>
#include <unistd.h>
#include "ft_printf.h"
#include "libft/libft.h"

static int			intmaxlen(intmax_t n, char **s, t_format *format)
{
	int		len;
	int		sign;
	int		apostrophes;

	sign = (n < 0 || (format->plus || format->space));
	len = !n && format->prec;
	apostrophes = 0;
	while (n && ++len)
		n /= 10;
	if (format->apost && len > 3)
		apostrophes = (len - 1) / 3;
	if (len < format->prec)
		len = format->prec;
	len += sign + apostrophes;
	if (!format->minus && len < format->width)
		len = format->width;
	if (!(*s = (char*)malloc(len)))
		return (-1);
	ft_memset(*s, format->zero ? '0' : ' ', len);
	if (!n && format->prec < 0)
		format->prec = 1;
	return (len);
}

static int			intmaxtoa(intmax_t n, char **s, t_format *format)
{
	int		len;
	int		tmp;
	int		count;
	char	sign;

	if ((len = intmaxlen(n, s, format)) <= 0)
		return (len);
	tmp = len;
	sign = n < 0 ? '-' : 0;
	if (!sign && (format->plus || format->space))
		sign = format->plus ? '+' : ' ';
	count = 0;
	while (n || format->prec > 0)
	{
		(*s)[--tmp] = n >= 0 ? n % 10 + '0' : -(n % 10) + '0';
		if (n && format->apost && !(++count % 3))
			(*s)[--tmp] = '\'';
		n = n >= 0 ? n / 10 : -(n / 10);
		--format->prec;
	}
	if (sign)
		(*s)[(*s)[--tmp] == ' ' ? tmp : 0] = sign;
	return (len);
}

static intmax_t		get_integer(t_format *format, va_list *va)
{
	if (!format->length)
		return ((int)va_arg(*va, int));
	if (format->length == 'H')
		return ((char)va_arg(*va, int));
	if (format->length == 'h')
		return ((short)va_arg(*va, int));
	if (format->length == 'l')
		return ((long)va_arg(*va, long));
	if (format->length == 'L')
		return ((long long)va_arg(*va, long long));
	if (format->length == 'j')
		return ((intmax_t)va_arg(*va, intmax_t));
	if (format->length == 'z')
		return ((ssize_t)va_arg(*va, ssize_t));
	if (format->length == 't')
		return ((ptrdiff_t)va_arg(*va, ptrdiff_t));
	return ((int)va_arg(*va, int));
}

int					ft_printf_int(t_format *format, va_list *va)
{
	char		*s;
	intmax_t	integer;
	int			len;
	int			offset;
	int			len_total;

	if (format->zero && format->prec >= 0)
		format->zero = 0;
	integer = get_integer(format, va);
	if ((len = intmaxtoa(integer, &s, format)) < 0)
		return (-1);
	offset = (format->width > len ? format->width - len : 0);
	len_total = len + offset;
	if (write(1, s, len) < len ||
	(format->minus && ft_printf_pad(1, ' ', offset) < offset))
		len_total = -1;
	free(s);
	return (len_total);
}
