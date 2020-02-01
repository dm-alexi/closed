/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stristim <stristim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/29 19:31:00 by sscarecr          #+#    #+#             */
/*   Updated: 2020/02/01 21:08:08 by stristim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <math.h>
#include "fdf.h"
#define ESC 53
#define UP 126
#define DOWN 125
#define LEFT 123
#define RIGHT 124
#define NUM_PLUS 69
#define PLUS 24
#define NUM_MINUS 78
#define MINUS 27
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
#define SPACE 49
#define MOVE_SPEED 5
#define ROTATE_SPEED (M_PI / 180)
#define SCALE_FACTOR 1.04
#define Z_SCALE_FACTOR 1.25
#define SCROLL_UP 4
#define SCROLL_DN 5

int		win_close(void *param)
{
	(void)param;
	exit(EXIT_SUCCESS);
}

int		key_handle(int key, void *param)
{
	t_map	*map;
	int i;
	i = -1;
	map = param;
	if (key == ESC)
		win_close(param);
	else if (key == PLUS || key == NUM_PLUS)
	{
		map->matrix.scale[0] *= SCALE_FACTOR;
		map->matrix.scale[1] *= SCALE_FACTOR;
		map->matrix.scale[2] *= SCALE_FACTOR;
	}
	else if (key == MINUS || key == NUM_MINUS)
	{
		map->matrix.scale[0] /= SCALE_FACTOR;
		map->matrix.scale[1] /= SCALE_FACTOR;
		map->matrix.scale[2] /= SCALE_FACTOR;
	}
	else if (key == UP)
		map->matrix.move[1] -= MOVE_SPEED;
	else if (key == DOWN)
		map->matrix.move[1] += MOVE_SPEED;
	else if (key == LEFT)
		map->matrix.move[0] -= MOVE_SPEED;
	else if (key == RIGHT)
		map->matrix.move[0] += MOVE_SPEED;
	else if (key == EIGHT  || key == NUM_EIGHT)
		map->matrix.rotate[0] += ROTATE_SPEED;
	else if (key == TWO ||  key == NUM_TWO)
		map->matrix.rotate[0] -= ROTATE_SPEED;
	else if (key == SIX || key == NUM_SIX)
		map->matrix.rotate[1] += ROTATE_SPEED;
	else if (key == FOUR || key == NUM_FOUR)
		map->matrix.rotate[1] -= ROTATE_SPEED;
	else if (key == SEVEN || key == NUM_SEVEN)
		map->matrix.rotate[2] -= ROTATE_SPEED;
	else if (key == NINE || key == NUM_NINE)
		map->matrix.rotate[2] += ROTATE_SPEED;
	else  if (key == SPACE)
		matrix_init(map);
	else if (key == 12)
	{
		map->matrix.rotate[0] = 0.75;
		map->matrix.rotate[1] = -0.5;
		map->matrix.rotate[2] = 0.5;
	}
	matrix_result(map);
	return (0);
}

int		mouse_handle(int key, int x, int y, void *param)
{
	t_map	*map;

	map = param;
	if (key == SCROLL_UP)
		map->matrix.scale[2] /= Z_SCALE_FACTOR;
	else if (key == SCROLL_DN)
		map->matrix.scale[2] *= Z_SCALE_FACTOR;
	else if (x >= 15 && x <= 100 && y >= 175 && y <= 275)
	{		
		map->maxcolor = BLUE;
		set_colors(map);
	}
	matrix_result(map);
	return(0);
}