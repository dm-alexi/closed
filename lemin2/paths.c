/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   paths.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sscarecr <sscarecr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/12 19:30:43 by sscarecr          #+#    #+#             */
/*   Updated: 2020/03/03 15:56:58 by sscarecr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

static void	unite_path(t_edge *path)
{
	t_edge	*t;

	while (path->node->type != FINISH && path->next->node->type != FINISH)
		if (path->next->node->type == TEMP)
		{
			t = path->next->node->edges;
			while (t->len)
				t = t->next;
			path->next->node = t->node;
		}
		else if (path->node == path->next->node)
		{
			t = path->next->next;
			free(path->next);
			path->next = t;
		}
		else
			path = path->next;
}

t_edge		*get_path(t_graph *graph)
{
	t_edge	*res;
	t_edge	*tmp;
	int		i;

	if ((i = graph->finish->distance) <= 0)
	{
		if (graph->nodes[graph->node_num - 1]->type == TEMP)
			restore_graph(graph);
		return (NULL);
	}
	if (!(res = (t_edge*)ft_memalloc(sizeof(t_edge))))
		sys_error();
	res->node = graph->finish;
	while (res->node->prev)
	{
		if (!(tmp = (t_edge*)malloc(sizeof(t_edge))))
			sys_error();
		tmp->node = res->node->prev;
		tmp->next = res;
		res = tmp;
	}
	unite_path(res);
	if (graph->nodes[graph->node_num - 1]->type == TEMP)
		restore_graph(graph);
	return (res);
}

int			path_len(t_edge *path)
{
	int		n;

	n = 0;
	while ((path = path->next))
		++n;
	return (n);
}

int			count_moves(t_edge **paths, int n_paths, int ants)
{
	int		i;
	int		n;

	n = 0;
	i = 0;
	while (i < n_paths)
		n += path_len(paths[i++]);
	return ((ants - n_paths + n) / n_paths + ((ants + n) % n_paths > 0));
}
