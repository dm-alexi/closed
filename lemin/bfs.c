/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bfs.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sscarecr <sscarecr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/08 16:30:18 by sscarecr          #+#    #+#             */
/*   Updated: 2020/02/14 19:47:45 by sscarecr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

static void		process(t_queue **q, t_queue **last)
{
	t_edge		*t;
	t_queue		*tmp;

	t = (*q)->node->edges;
	while (t)
	{
		if (t->node->distance < 0)
		{
			t->node->distance = (*q)->node->distance + t->len;
			t->node->prev = (*q)->node;
			if (!((*last)->next = (t_queue*)malloc(sizeof(t_queue))))
				sys_error();
			*last = (*last)->next;
			(*last)->node = t->node;
			(*last)->next = NULL;
		}
		t = t->next;
	}
	tmp = (*q)->next;
	free(*q);
	*q = tmp;
}

void			bfs(t_graph *graph)
{
	t_queue		*q;
	t_queue		*last;

	if (!(q = (t_queue*)malloc(sizeof(t_queue))))
		sys_error();
	q->node = graph->start;
	q->next = NULL;
	last = q;
	while (q && graph->finish->distance < 0)
		process(&q, &last);
	while (q)
	{
		last = q->next;
		free(q);
		q = last;
	}
	if ((graph->finish->distance) < 0)
		error();
	if ((graph->moves = graph->ant_num - 1 + graph->finish->distance) <= 0)
		error();
	graph->path_num = 1;
	graph->paths[0] = get_path(graph);
}
