/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_op.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sscarecr <sscarecr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/12 21:37:22 by sscarecr          #+#    #+#             */
/*   Updated: 2019/11/12 22:46:02 by sscarecr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

t_node	*new_node(int n)
{
	t_node	*t;

	if (!(t = (t_node*)malloc(sizeof(t_node))))
		return (NULL);
	t->num = n;
	t->u = t;
	t->d = t;
	return (t);
}

t_node	*add(t_node **cur, t_node *t)
{
	if (!t)
		return (NULL);
	if (*cur)
	{
		t->u = (*cur)->u;
		t->d = *cur;
		(*cur)->u->d = t;
		(*cur)->u = t;
	}
	else
	{
		t->u = t;
		t->d = t;
	}
	*cur = t;
	return (t);
}

t_node	*pop(t_node **cur)
{
	t_node	*t;

	if (!*cur)
		return (NULL);
	t = *cur;
	if ((*cur)->d == *cur)
		*cur = NULL;
	else
	{
		*cur = (*cur)->d;
		(*cur)->u = (*cur)->u->u;
		(*cur)->u->d = (*cur);
	}
	return (t);
}

void	swap(t_node *t)
{
	int		n;

	if (t && t->d != t)
	{
		n = t->num;
		t->num = t->d->num;
		t->d->num = n;
	}
}

void	clear_stacks(t_stack *t)
{
	t_node	*tmp;

	if ((tmp = t->a))
	{
		while (tmp->d != t->a)
		{
			tmp = tmp->d;
			free(tmp->u);
		}
		free(tmp);
	}
	if ((tmp = t->b))
	{
		while (tmp->d != t->b)
		{
			tmp = tmp->d;
			free(tmp->u);
		}
		free(tmp);
	}
}
