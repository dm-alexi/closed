#ifdef _WIN32
# include <stdio.h>
#else
# include <unistd.h>
#endif
#include "filler.h"

void	get_player(t_map *map)
{
    char	*line;
    int		r;

	if ((r = get_next_line(STDIN_FILENO, &line)) <= 0)
		r ? sys_error() : error("player number not received\n");
	if (ft_strequ(line, "$$$ exec p1 : [sscarecr]"))
		map->mine = 'O';
	else if (ft_strequ(line, "$$$ exec p2 : [sscarecr]"))
		map->mine = 'X';
	else
		error("invalid player number\n");
	map->enemy = (map->mine == 'O' ? 'X' : 'O');
	free(line);
}

int		get_dim(t_map *map)
{
	char	*line;
	char	*t;
	int		r;

	if ((r = get_next_line(STDIN_FILENO, &line)) <= 0)
		r ? sys_error() : error("map not received\n");
	if (!ft_strnequ(line, "Plateau ", 8))
		r = 0;
	else
	{
		if ((map->h = ft_strtol(line + 8, &t, 10)) <= 0 ||
		(map->w = ft_atoi(t)) <= 0)
			error("invalid map size\n");
		r = 1;
	}
	free(line);
	if (!map->field && !(map->field = (char*)malloc(map->h * map->w)))
		sys_error();
	return (r);
}

void	get_map(t_map *map)
{
	char	*line;
	int		r;
	int		i;

	if ((r = get_next_line(STDIN_FILENO, &line)) <= 0)
		r ? sys_error() : error("invalid map\n");
	free(line);
	i = -1;
    while (++i < map->h)
	{
		if ((r = get_next_line(STDIN_FILENO, &line)) <= 0)
		r ? sys_error() : error("invalid map\n");
        ft_strncpy(map->field + map->w * i, ft_strchr(line, ' ') + 1, map->w);
        free(line);
	}
}

void	get_piece(t_piece *piece)
{
	char	*line;
	char	*t;
	int		i;
	int		r;

	if ((r= get_next_line(STDIN_FILENO, &line)) < 0)
		sys_error();
	if (!r || !ft_strnequ(line, "Piece ", 6))
		error("piece not received\n");
	if ((piece->h = ft_strtol(line + 6, &t, 10)) <= 0 ||
		(piece->w = ft_atoi(t)) <= 0)
			error("invalid piece size\n");
	free(line);
	if (!piece->field && !(piece->field = (char*)malloc(piece->h * piece->w)))
		sys_error();
	i = -1;
    while (++i < piece->h)
	{
		if ((r = get_next_line(STDIN_FILENO, &line)) <= 0)
			r ? sys_error() : error("invalid piece\n");
        ft_strncpy(piece->field + piece->w * i, line, piece->w);
        free(line);
	}
}
