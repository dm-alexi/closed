/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sscarecr <sscarecr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/27 21:27:16 by sscarecr          #+#    #+#             */
/*   Updated: 2019/12/28 15:54:23 by sscarecr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void print_node(const t_node *a)
{
	t_list	*tmp;
	
	ft_printf("Name: %s, x = %d, y = %d\t\tconnected to: ", a->name, a->x, a->y);
	tmp = a->nodes;
	while (tmp)
	{
		ft_printf("%s ", (*((t_node**)(tmp->content)))->name);
		tmp = tmp->next;
	}
	ft_printf("\n");
}

void	print_graph(t_graph *graph)
{
	int		i;

	ft_printf("--------------------\n");
	ft_printf("Number of ants: %d\nNodes:\n", graph->ant_num);
	i = -1;
	while (++i < graph->node_num)
		print_node(graph->nodes[i]);
	ft_printf("--------------------\n");
}
