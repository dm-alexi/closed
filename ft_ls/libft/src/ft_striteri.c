/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sscarecr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/05 21:53:33 by sscarecr          #+#    #+#             */
/*   Updated: 2019/09/07 15:42:01 by sscarecr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	int		i;

	if (!s || !f)
		return ;
	i = 0;
	while (*(s + i))
	{
		f(i, s + i);
		++i;
	}
}
