/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_uint.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sscarecr <sscarecr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/16 19:35:11 by sscarecr          #+#    #+#             */
/*   Updated: 2019/10/23 23:43:58 by sscarecr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include <stddef.h>
#include <stdint.h>
#include <unistd.h>
#include "ft_printf.h"
#include "libft/libft.h"

static uintmax_t	get_uinteger(t_format *format, va_list *va)
{
	if (!format->length)
		return ((unsigned int)va_arg(*va, unsigned int));
	if (format->length == 'H')
		return ((unsigned char)va_arg(*va, unsigned int));
	if (format->length == 'h')
		return ((unsigned short)va_arg(*va, unsigned int));
	if (format->length == 'l')
		return ((unsigned long)va_arg(*va, unsigned long));
	if (format->length == 'L')
		return ((unsigned long long)va_arg(*va, unsigned long long));
	if (format->length == 'j')
		return ((uintmax_t)va_arg(*va, uintmax_t));
	if (format->length == 'z')
		return ((size_t)va_arg(*va, size_t));
	if (format->length == 't')
		return ((uintptr_t)va_arg(*va, uintptr_t));
	return ((unsigned int)va_arg(*va, unsigned int));
}

int					ft_printf_uint(t_format *format, va_list *va)
{
	uintmax_t	uinteger;
	char		*s;
	int			len;
	int			total_len;
	int			offset;

	uinteger = get_uinteger(format, va);
	if (format->prec >= 0)
		format->fill = ' ';
	if (format->type == 'u')
		len = ft_utoa(uinteger, &s, format);
	else if (format->type == 'o')
		len = ft_otoa(uinteger, &s, format);
	else
		len = ft_xtoa(uinteger, &s, format);
	if (!uinteger && (format->type == 'x' || format->type == 'X'))
		format->sharp = 0;
	if (len < 0)
		return (-1);
	if (write(1, s, len) < len)
		len = -1;
	free(s);
	return (len);
}
