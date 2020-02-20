/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ui.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sscarecr <sscarecr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/29 19:31:00 by sscarecr          #+#    #+#             */
/*   Updated: 2020/02/20 19:22:57 by sscarecr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "fractol.h"
#define ESC 53
#define MOUSE1 1
#define MOUSE2 2
#define SCROLL_UP 4
#define SCROLL_DN 5
#define UP 126
#define DOWN 125
#define LEFT 123
#define RIGHT 124
#define SPACE 49
#define NUM_PLUS 69
#define PLUS 24
#define NUM_MINUS 78
#define MINUS 27
#define Q 12
/*
#define NUM_EIGHT 91
#define EIGHT 28
#define NUM_TWO 84
#define TWO 19
#define NUM_FOUR 86
#define FOUR 21
#define NUM_SIX 88
#define SIX 22
#define NUM_SEVEN 89
#define SEVEN 26
#define NUM_NINE 92
#define NINE 25
*/

#define MOVE_SPEED 0.1
#define ZOOM 1.1
/*
#define ROTATE_SPEED (M_PI / 180)
#define SCALE_FACTOR 1.04
#define Z_SCALE_FACTOR 1.2*/

int				win_close(void *param)
{
	(void)param;
	exit(EXIT_SUCCESS);
}

int				key_handle(int key, void *param)
{
	t_screen	*s;
	
	s = param;
	if (key == ESC)
		win_close(param);
	else if (key == SPACE)
		++s->gamma;
	else if (key == PLUS || key == NUM_PLUS)
		s->maxiter += 8;
	else if ((key == MINUS || key == NUM_MINUS) && s->maxiter > 8)
		s->maxiter -= 8;
	else if (key == Q)
	{
		s->maxiter = INIT_ITER;
		s->moveX = 0;
		s->moveY = 0;
		s->zoom = 1;
	}
	else if (key == UP)
		s->moveY += MOVE_SPEED / s->zoom;
	else if (key == DOWN)
		s->moveY -= MOVE_SPEED / s->zoom;
	else if (key == LEFT)
		s->moveX += MOVE_SPEED / s->zoom;
	else if (key == RIGHT)
		s->moveX -= MOVE_SPEED / s->zoom;
	s->func(s);
	return (0);
}

int				mouse_move(int x, int y, void *param)
{
	t_screen	*s;

	s = param;
	if (!s->cblock)
	{
		if (x >= 0 && y >= 0 && x < s->image->width && y < s->image->height)
			map_coord(&s->c, s, x, y);
		else
		{
			s->c.re = JULIA_RE;
			s->c.im = JULIA_IM;
		}
		s->func(s);
	}
	return (0);
}

int				mouse_handle(int key, int x, int y, void *param)
{
	t_screen	*s;

	s = param;
	(void)key;
	if (x >= 0 && y >=0 && x < s->image->width && y < s->image->height)
	{
		if (key == SCROLL_UP && s->zoom / ZOOM > 0)
		{
			s->zoom /= ZOOM;
			s->moveX = (4.0 * x / s->image->width - 2.0) / s->zoom * (s->zoom - 1);
			s->moveY = (4.0 * y / s->image->height - 2.0) / s->zoom * (s->zoom - 1);
		}
		else if (key == SCROLL_DN)
		{
			s->zoom *= ZOOM;
			s->moveX = ((4.0 * x / s->image->width - 2.0) / s->zoom) * (s->zoom - 1);
			s->moveY = ((4.0 * y / s->image->height - 2.0) / s->zoom) * (s->zoom - 1);
		}
		else if (key == MOUSE1)
			s->cblock = !s->cblock;
	}
	s->func(s);
	return (0);
}
