/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_n.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sscarecr <sscarecr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/23 23:42:58 by sscarecr          #+#    #+#             */
/*   Updated: 2019/10/26 14:41:52 by sscarecr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>

int		ft_printf_n(va_list *va, int n)
{
	int		*p;

	p = ((int*)va_arg(*va, int*));
	if (p)
		*p = n;
	return (0);
}
