/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sscarecr <sscarecr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/16 19:27:55 by sscarecr          #+#    #+#             */
/*   Updated: 2020/02/23 14:27:39 by sscarecr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <pthread.h>
#include "fractol.h"
#define THREADS 32

void	map_coord(t_complex *z, t_screen *s, int x, int y)
{
	z->re = (s->maxx - s->minx) * x / s->image->width + s->minx;
	z->im = (s->maxy - s->miny) * y / s->image->height + s->miny;
}

void	*julia_inst(void *param)
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

void	*julia(void *param)
{
	t_screen	*s;
	int			i;
	t_thread	thread[THREADS];
	pthread_t	t[THREADS];

	s = param;
	i = -1;
	while (++i < THREADS)
	{
		thread[i].s = s;
		thread[i].start = i * (s->image->height / THREADS);
		thread[i].finish = thread[i].start + s->image->height / THREADS;
		pthread_create(t + i, NULL, julia_inst, thread + i);
	}
	i = -1;
	while (++i < THREADS)
		pthread_join(t[i], NULL);
	mlx_put_image_to_window(s->mlx, s->win, s->image->img, 0, 0);
	return (NULL);
}
