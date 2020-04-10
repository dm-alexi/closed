/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   players.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sscarecr <sscarecr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/05 16:30:35 by sscarecr          #+#    #+#             */
/*   Updated: 2020/04/10 14:45:15 by sscarecr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include "libft.h"
#include "corewar.h"

static void	byte_swap(unsigned *n)
{
	int		i;
	char	*s;
	char	c;

	i = 0;
	s = (char*)n;
	while (i < (int)sizeof(unsigned) / 2)
	{
		c = s[i];
		s[i] = s[sizeof(unsigned) - 1 - i];
		s[sizeof(unsigned) - 1 - i] = c;
		++i;
	}
}

static void	get_player(t_player *player, char *file)
{
	int	fd;
	int	r;

	r = 0;
	if ((fd = open(file, O_RDONLY)) < 0 ||
	(r = read(fd, &(player->header), sizeof(t_header))) < 0)
		sys_error(file);
	byte_swap(&player->header.magic);
	byte_swap(&player->header.prog_size);
	if (r < (int)sizeof(t_header) || player->header.magic != COREWAR_EXEC_MAGIC)
		error_ext("invalid file ", file);
	if (player->header.prog_size > CHAMP_MAX_SIZE)
		error_ext(file, " code size exceeds maximum value.");
	if (!(player->code = (t_byte*)malloc(player->header.prog_size)))
		sys_error(NULL);
	if ((r = read(fd, player->code, player->header.prog_size)) <
	(int)player->header.prog_size)
		r < 0 ? sys_error(file) : error_ext("invalid file ", file);
	close(fd);
}

void		get_players(t_vm *vm, char **files)
{
	unsigned	i;

	vm->players = (t_player*)malloc(sizeof(t_player) * vm->num_players);
	i = 0;
	while (i < vm->num_players)
	{
		get_player(vm->players + i, files[i]);
		vm->players[i].num = i + 1;
		++i;
	}
}
