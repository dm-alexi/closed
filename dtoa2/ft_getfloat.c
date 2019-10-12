/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getfloat.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sscarecr <sscarecr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/12 14:37:41 by sscarecr          #+#    #+#             */
/*   Updated: 2019/10/12 14:39:53 by sscarecr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_bigint.h"

void	get_double(double value, int *sign, uint64_t *frac, int *exp)
{
	uint64_t val;

	val = *(uint64_t*)&value;
	*sign = (val & 0x8000000000000000L) != 0;
	*exp = (int32_t)((val << 1) >> 53) - 1075;
	*frac = (val & 0x000fffffffffffff) | 0x0010000000000000;
	while (!(*frac & 1L))
	{
		++*exp;
		*frac >>= 1;
	}
}
