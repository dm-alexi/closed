/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemin.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sscarecr <sscarecr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/27 21:27:04 by sscarecr          #+#    #+#             */
/*   Updated: 2019/12/28 15:44:47 by sscarecr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEMIN_H
# define LEMIN_H
# include "libft/libft.h"

typedef enum	e_command
{
	UNKNOWN, START, END
}				t_command;

typedef struct	s_node
{
	char	*name;
	t_list	*nodes;
	int		distance;
	int		x;
	int		y;
}				t_node;

typedef struct	s_edge
{
	t_node	*node1;
	t_node	*node2;
}				t_edge;

typedef struct	s_graph
{
	int		ant_num;
	int		node_num;
	t_node	**nodes;
	t_edge	*edges;
	t_node	*start;
	t_node	*finish;
}				t_graph;

void			sys_error(void);
void			error(void);

void			print_graph(t_graph *graph);
void 			print_node(const t_node *a);
t_graph			*get_graph(void);
t_list			*new_node(char *line, t_command com);
#endif
