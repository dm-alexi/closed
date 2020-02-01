/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sscarecr <sscarecr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/28 23:32:20 by sscarecr          #+#    #+#             */
/*   Updated: 2020/02/01 21:26:38 by sscarecr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include "libft/libft.h"
# define WIDTH 1920
# define HEIGHT 1080
# define INVALID "Invalid map."
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

typedef struct	s_vertex
{
	int		x;
	int		y;
	int		z;
	int		w;
	int		color;
}				t_vertex;

typedef struct	s_image
{
	void	*img;
	int		bpp;
	int		sizeline;
	int		width;
	int		height;
	int		endian;
	char	*s;
	int		*zbuf;
}				t_image;

typedef struct	s_matrix
{
	double	result[16];
	double	scale[3];
	double	rotate[3];
	double	move[3];
}				t_matrix;

typedef struct	s_map
{
	int			fd;
	int			length;
	int			columns;
	int			rows;
	int			z_min;
	int			z_max;
	int			mincolor;
	int			maxcolor;
	int			midcolor;
	t_matrix	matrix;
	void		*mlx;
	void		*win;
	t_image		*image;
	t_vertex	*grid;
	t_vertex	*show;
}				t_map;

void			sys_error(void);
void			error(char *s);
t_map			*get_map(int fd);
void			fdf_init(char *file, t_map *map);
int				key_handle(int key, void *param);
int				mouse_handle(int key, int x, int y, void *param);
int				win_close(void *param);
t_image			*new_image(void *mlx, int width, int height);
void			image_draw_line(t_image *image, t_vertex *a, t_vertex *b);
double			*mult(double a[16], double b[16], double c[16]);
double			*translation(double move[3]);
double			*rotation(double r[3]);
double			*scale(double r[3]);
void			matrix_init(t_map *map);
void			matrix_result(t_map *map);
void			ft_menu(t_map *map);
int				gradient_check(t_vertex *a, t_vertex *b, int steps, int i);
int				gradient(int start, int finish, double k);
void			set_colors(t_map *map);

#endif
