/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isqrt.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sscarecr <sscarecr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/04 22:44:52 by sscarecr          #+#    #+#             */
/*   Updated: 2020/07/31 21:50:13 by sscarecr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Integer square root
*/

int	ft_isqrt(int n)
{
	int	x;
	int	y;

	if (n <= 0)
		return (0);
	x = n;
	y = x / 2 + x % 2;
	while (y < x)
	{
		x = y;
		y = (x + n / x) / 2;
	}
	return (x);
}
