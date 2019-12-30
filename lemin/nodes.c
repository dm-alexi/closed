/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nodes.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sscarecr <sscarecr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/27 21:27:12 by sscarecr          #+#    #+#             */
/*   Updated: 2019/12/29 17:40:31 by sscarecr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

static t_list	*new_node(char *line, t_command com)
{
	char	*s;
	t_node	node;

	if (!(s = ft_strrchr(line, ' ')))
		error();
	node.y = ft_atoi(s);
	*s = '\0';
	if (!(s = ft_strrchr(line, ' ')))
		error();
	node.x = ft_atoi(s);
	*s = '\0';
	if (!*line)
		error();
	node.name = ft_strdup(line);
	node.edges = NULL;
	node.distance = com;
	free(line);
	return (ft_lstnew(&node, sizeof(t_node)));
}

static int		compare(const void *a, const void *b)
{
	int		res;

	if (!(res = ft_strcmp((*((t_node **)a))->name, (*((t_node **)b))->name)))
		error();
	return (res);
}

void			get_nodes(t_graph *graph, char **line)
{
	t_list		*lst;
	t_list		*tmp;
	t_command	com;
	int			i;

	lst = NULL;
	while ((i = get_line(line, &com)) == NODE && ++graph->node_num)
		ft_lstadd(&lst, new_node(*line, com));
	if (i <= 0)
		i ? sys_error() : error();
	if (!(graph->nodes = (t_node **)malloc(sizeof(t_node *) * graph->node_num)))
		sys_error();
	i = 0;
	while (lst)
	{
		tmp = lst->next;
		graph->nodes[i++] = lst->content;
		free(lst);
		lst = tmp;
	}
	ft_qsort(graph->nodes, graph->node_num, sizeof(t_node *), compare);
}
