/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sscarecr <sscarecr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/28 23:32:20 by sscarecr          #+#    #+#             */
/*   Updated: 2019/12/17 21:33:18 by sscarecr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H_INCLUDED
# define FDF_H_INCLUDED
# include "libft/libft.h"
# define WIDTH 1920
# define HEIGHT 1080
# define STEP 10

typedef struct	s_vertex
{
	int		x;
	int		y;
	int		z;
	double	w;
	int		color;
}				t_vertex;

typedef struct	s_image
{
	void	*img;
	int		bpp;
	int		width;
	int		endian;
	int		height;
	char 	*s;
}				t_image;

typedef struct	s_map
{
	int			length;
	int			columns;
	int			rows;
	t_vertex	*grid;
}				t_map;

void			sys_error(void);
void			error(char *s);
t_map			*get_map(int fd);
void			window(char *file, t_map *map);
int				key_handle(int key, void *param);
t_image			*new_image(void *mlx, int width, int height);
void			image_put_pixel(t_image *image, int x, int y, int color);
void			image_draw_line(t_image *image, t_vertex *a, t_vertex *b);

double *mult(double a[16], double b[16], double c[16]);
t_vertex *transform(t_vertex *v, double m[16], t_vertex *out);
double *identity(void);
double *scale(int r);
double *projection(double fov, double ratio, double near, double far);
#endif
