/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sscarecr <sscarecr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/17 18:55:37 by sscarecr          #+#    #+#             */
/*   Updated: 2020/02/24 16:11:02 by sscarecr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "fractol.h"

void	map_coord(t_complex *z, t_screen *s, int x, int y)
{
	z->re = (s->maxx - s->minx) * x / s->image->width + s->minx;
	z->im = (s->maxy - s->miny) * y / s->image->height + s->miny;
}

t_complex	complex_div(t_complex a, t_complex b)
{
	t_complex	c;

	c.re = (a.re * b.re + a.im * b.im) / (b.re * b.re + b.im * b.im);
	c.im = (a.im * b.re - b.im * a.re) / (b.re * b.re + b.im * b.im);
	return (c);
}

double	square_dist(t_complex *z, t_complex c)
{
	double	t;

	t = z->re * z->re - z->im * z->im + c.re;
	z->im = 2 * z->re * z->im + c.im;
	z->re = t;
	return (z->re * z->re + z->im * z->im);
}

double	square_dist_abs(t_complex *z, t_complex c)
{
	double	t;

	t = fabs(z->re * z->re - z->im * z->im + c.re);
	z->im = fabs(2 * z->re * z->im + c.im);
	z->re = t;
	return (z->re * z->re + z->im * z->im);
}

int		sierpinsky_fill(t_complex *z)
{
	int	x;
	int	y;
	int	i;

	x = z->re;
	y = z->im;
	i = 0;
	while (x > 0 && y > 0)
	{
		if (x % 3 == 1 && y % 3 == 1)
			return (0);
		x = x / 3;
		y = y / 3;
		++i;
	}
	return (i);
}

double	mult_dist(t_complex *z, t_complex c, int n)
{
	double	t;

	while (n--)
	{
		t = z->re * z->re - z->im * z->im;
		z->im = 2 * z->re * z->im;
		z->re = t;
	}
	z->re += c.re;
	z->im += c.im;
	return (z->re * z->re + z->im * z->im);
}
