/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sscarecr <sscarecr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/16 19:27:55 by sscarecr          #+#    #+#             */
/*   Updated: 2020/02/23 15:44:41 by sscarecr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include "fractol.h"

void	*julia(void *param)
{
	t_thread	*t;
	t_complex	z;
	int			x;
	int			i;

	t = param;
	while (t->start != t->finish)
	{
		x = -1;
		while (++x < t->s->image->width)
		{
			map_coord(&z, t->s, x, t->start);
			i = 0;
			while (i < t->s->maxiter && square_dist(&z, t->s->c) <= 4)
				++i;
			image_put_pixel(t->s->image, x, t->start, get_color(i, t->s->maxiter,
				t->s->gamma));
		}
		++t->start;
	}
	return (NULL);
}

void	*mandelbrot(void *param)
{
	t_thread	*t;
	t_complex	z;
	t_complex	c;
	int			x;
	int			i;

	t = param;
	while (t->start != t->finish)
	{
		x = -1;
		while (++x < t->s->image->width)
		{
			map_coord(&c, t->s, x, t->start);
			z = c;
			i = 0;
			while (i < t->s->maxiter && square_dist(&z, c) <= 4)
				++i;
			image_put_pixel(t->s->image, x, t->start, get_color(i, t->s->maxiter,
				t->s->gamma));
		}
		++t->start;
	}
	return (NULL);
}