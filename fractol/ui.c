/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ui.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sscarecr <sscarecr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/29 19:31:00 by sscarecr          #+#    #+#             */
/*   Updated: 2020/02/18 20:18:56 by sscarecr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "fractol.h"
#define ESC 53
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
/*
#define MOVE_SPEED 5
#define ROTATE_SPEED (M_PI / 180)
#define SCALE_FACTOR 1.04
#define Z_SCALE_FACTOR 1.2*/

int				win_close(void *param)
{
	(void)param;
	exit(EXIT_SUCCESS);
}
/*
static void		key_matrix_movement(int key, t_map *map)
{
	if (key == UP)
		map->matrix.move[1] -= MOVE_SPEED;
	else if (key == DOWN)
		map->matrix.move[1] += MOVE_SPEED;
	else if (key == LEFT)
		map->matrix.move[0] -= MOVE_SPEED;
	else if (key == RIGHT)
		map->matrix.move[0] += MOVE_SPEED;
	else if (key == EIGHT || key == NUM_EIGHT)
		map->matrix.rotate[0] += ROTATE_SPEED;
	else if (key == TWO || key == NUM_TWO)
		map->matrix.rotate[0] -= ROTATE_SPEED;
	else if (key == SIX || key == NUM_SIX)
		map->matrix.rotate[1] += ROTATE_SPEED;
	else if (key == FOUR || key == NUM_FOUR)
		map->matrix.rotate[1] -= ROTATE_SPEED;
	else if (key == SEVEN || key == NUM_SEVEN)
		map->matrix.rotate[2] -= ROTATE_SPEED;
	else if (key == NINE || key == NUM_NINE)
		map->matrix.rotate[2] += ROTATE_SPEED;
}
*/

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
		s->maxiter = INIT_ITER;
/*
	if (key == UP || key == DOWN || key == LEFT || key == RIGHT || key == EIGHT
		|| key == NUM_EIGHT || key == TWO || key == NUM_TWO || key == SIX ||
		key == NUM_SIX || key == FOUR || key == NUM_FOUR || key == SEVEN ||
		key == NUM_SEVEN || key == NINE || key == NUM_NINE || key == SPACE)
		key_matrix_movement(key, (t_map*)param);
	else if (key == Q)
	{
		((t_map*)param)->matrix.rotate[0] = 0.75;
		((t_map*)param)->matrix.rotate[1] = -0.5;
		((t_map*)param)->matrix.rotate[2] = 0.5;
	}
	matrix_result(((t_map*)param));*/
	s->func(s);
	return (0);
}

int				mouse_move(int x, int y, void *param)
{
	t_screen	*s;

	s = param;
	if (x >= 0 && y >= 0 && x < s->image->width && y < s->image->height)
		map_coord(&s->c, s, x, y);
	else
	{
		s->c.re = JULIA_RE;
		s->c.im = JULIA_IM;
	}
	s->func(s);
	return (0);
}

/*
int				mouse_handle(int key, int x, int y, void *param)
{
	t_screen	*s;
	//static const int	colors[] = {RED, BLUE, PINK, CYAN, GREEN, VIOLET,
	//	YELLOW, ORANGE, AVOCADO, WHITE};

	s = param;
	(void)key;
	if (key == SCROLL_UP)
		map->matrix.scale[2] /= Z_SCALE_FACTOR;
	else if (key == SCROLL_DN)
		map->matrix.scale[2] *= Z_SCALE_FACTOR;
	if (x >= 0 && y >=0 && x < s->image->width && y < s->image->height)
	{
	}
	julia(s);
	return (0);
}
*/