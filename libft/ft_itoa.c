/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sscarecr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/05 21:18:19 by sscarecr          #+#    #+#             */
/*   Updated: 2019/09/07 15:34:57 by sscarecr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_itoa(int n)
{
	char	*s;
	char	tmp[21];
	int		sign;

	sign = 0;
	s = tmp + 20;
	*s-- = '\0';
	if (n == 0)
		*s-- = '0';
	else if (n < 0)
	{
		sign = 1;
		*s-- = -(n % 10) + '0';
		n = -(n / 10);
	}
	while (n)
	{
		*s-- = n % 10 + '0';
		n /= 10;
	}
	if (sign)
		*s-- = '-';
	return (ft_strdup(s + 1));
}