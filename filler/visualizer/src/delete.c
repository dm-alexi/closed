/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delete.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sscarecr <sscarecr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/13 21:58:48 by sscarecr          #+#    #+#             */
/*   Updated: 2020/08/09 09:34:46 by sscarecr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "visual.h"

void	delete_game(t_game *game)
{
	t_field	*t;

	while (game->start)
	{
		t = game->start->next;
		free(game->start->table);
		free(game->start);
		game->start = t;
	}
	free(game->p1);
	free(game->p2);
	free(game->title);
}
