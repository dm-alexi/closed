/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strequ.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sscarecr <sscarecr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/05 21:51:07 by sscarecr          #+#    #+#             */
/*   Updated: 2020/07/31 10:12:15 by sscarecr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strequ(char const *s1, char const *s2)
{
	if (s1 == s2)
		return (1);
	if (!s1 || !s2)
		return (0);
	while (*s1 && *s1 == *s2)
	{
		++s1;
		++s2;
	}
	return (!(*s1 - *s2));
}
