/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nodes.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sscarecr <sscarecr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/27 21:27:12 by sscarecr          #+#    #+#             */
/*   Updated: 2020/02/18 18:52:41 by sscarecr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include "lemin.h"

static int		get_coordinate(char *s)
{
	long	n;
	char	*t;

	n = ft_strtol(s, &t, 10);
	if ((n == 0 && *(t - 1) != '0') || n > INT_MAX || n < INT_MIN)
		error();
	return (n);
}

static t_list	*new_node(char *line, t_type type)
{
	char	*s;
	t_node	node;

	if (*line == 'L')
		error();
	if (!(s = ft_strrchr(line, ' ')))
		error();
	node.y = get_coordinate(s);
	*s = '\0';
	if (!(s = ft_strrchr(line, ' ')))
		error();
	node.x = get_coordinate(s);
	*s = '\0';
	if (!*line)
		error();
	node.name = ft_strdup(line);
	node.edges = NULL;
	node.prev = NULL;
	node.distance = (type == START ? 0 : -1);
	node.type = type;
	node.rank = 0;
	free(line);
	return (ft_lstnew(&node, sizeof(t_node)));
}

static int		compare(const void *a, const void *b)
{
	int		res;

	if (!(res = ft_strcmp((*((t_node **)a))->name, (*((t_node **)b))->name))
	&& a != b)
		error();
	return (res);
}

void			get_nodes(t_graph *graph, char **line)
{
	t_list	*lst;
	t_list	*tmp;
	t_type	type;
	int		i;

	lst = NULL;
	while ((i = get_line(line, &type)) == NODE && ++graph->node_num)
		ft_lstadd(&lst, new_node(*line, type));
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
