/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sscarecr <sscarecr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/16 15:52:09 by sscarecr          #+#    #+#             */
/*   Updated: 2020/02/23 18:30:48 by sscarecr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
# include "libft/libft.h"
# define FRACTALS 3
# define INIT_ITER 256
# define WIDTH 1024
# define HEIGHT 1024
# define BLACK 0x000000
# define WHITE 0xFFFFFF
# define RED 0xFF0000
# define BLUE 0x0000FF
# define PINK 0xFF0080
# define CYAN 0x00FFFF
# define GREEN 0x00FF00
# define VIOLET 0xFF00FF
# define YELLOW 0xFFFF00
# define ORANGE 0xFF8000
# define AVOCADO 0x00FF80

# define JULIA_RE 0.325
# define JULIA_IM -0.0375

typedef struct	s_complex
{
	double re;
	double im;
}				t_complex;

typedef struct	s_image
{
	void	*img;
	int		bpp;
	int		sizeline;
	int		width;
	int		height;
	int		endian;
	char	*map;
}				t_image;

typedef struct	s_screen
{
	void		*mlx;
	void		*win;
	t_image		*image;
	void		*(*func)(void *);
	int			gamma;
	double		minx;
	double		miny;
	double		maxx;
	double		maxy;
	char		cblock;
	int			maxiter;
	t_complex	c;
}				t_screen;

typedef struct	s_thread
{
	int			start;
	int			finish;
	t_screen	*s;
}				t_thread;

void			sys_error(void);

int				win_close(void *param);
int				counter(int x);
int				key_handle(int key, void *param);
int				mouse_handle(int key, int x, int y, void *param);
int				mouse_move(int x, int y, void *param);

int				init(void *mlx, int type);
t_image			*new_image(void *mlx, int width, int height);
void			image_put_pixel(t_image *image, int x, int y, int color);

void			*mandelbrot(void *param);
void			*julia(void *param);
void			*burning(void *param);
void			*threads(void *param);

double			square_dist(t_complex *z, t_complex c);
double			square_dist_abs(t_complex *z, t_complex c);
void			map_coord(t_complex *z, t_screen *s, int x, int y);
int				get_color(int iter, int maxiter, int g);
#endif
