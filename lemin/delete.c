/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delete.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sscarecr <sscarecr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/29 17:21:34 by sscarecr          #+#    #+#             */
/*   Updated: 2020/02/10 20:03:48 by sscarecr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void	delete_graph(t_graph *graph)
{
	int		i;
	t_edge	*tmp;

	i = 0;
	while (i < graph->node_num)
	{
		free(graph->nodes[i]->name);
		while (graph->nodes[i]->edges)
		{
			tmp = graph->nodes[i]->edges->next;
			free(graph->nodes[i]->edges);
			graph->nodes[i]->edges = tmp;
		}
		free(graph->nodes[i]);
		++i;
	}
	free(graph->nodes);
	i = 0;
	while (i < graph->path_num)
		delete_path(graph->paths[i++]);
	free(graph->paths);
	free(graph);
}

void	delete_path(t_edge *path)
{
	t_edge	*t;

	while ((t = path))
	{
		path = path->next;
		free(t);
	}
}

void	delete_paths(t_edge **paths, int n)
{
	while (--n >= 0)
		delete_path(paths[n]);
	free(paths);
}
