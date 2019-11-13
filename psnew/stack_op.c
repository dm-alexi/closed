/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_op.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sscarecr <sscarecr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/12 21:31:18 by sscarecr          #+#    #+#             */
/*   Updated: 2019/11/12 22:48:18 by sscarecr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

static void		exec_silent(t_stack *t, enum e_command com)
{
	if (com == SA || com == SS)
		swap(t->a);
	if (com == SB || com == SS)
		swap(t->a);
	if (com == RA || com == RR)
		t->a = t->a->d;
	if (com == RB || com == RR)
		t->b = t->b->d;
	if (com == RRA || com == RRR)
		t->a = t->a->u;
	if (com == RRB || com == RRR)
		t->b = t->b->u;
	if (com == PA)
	{
		add(&(t->a), pop(&(t->b)));
		++t->a_count;
		--t->b_count;
	}
	if (com == PB)
	{
		add(&(t->b), pop(&(t->a)));
		++t->b_count;
		--t->a_count;
	}
}

void			exec(t_stack *t, enum e_command com)
{
	static const char	*arr[11] =
	{"sa", "sb", "ss", "pa", "pb", "ra", "rb", "rr", "rra", "rrb", "rrr"};

	exec_silent(t, com);
	if (!t->fin)
	{
		if (!(t->fin = ft_lstnew(arr[com], ft_strlen(arr[com]) + 1)))
			mem_error();
		t->start = t->fin;
	}
	else
	{
		if (!(t->fin->next = ft_lstnew(arr[com], ft_strlen(arr[com]) + 1)))
			mem_error();
		t->fin = t->fin->next;
	}
}

int				get_com(int fd, t_stack *t)
{
	static const char	*arr[11] =
	{"sa", "sb", "ss", "pa", "pb", "ra", "rb", "rr", "rra", "rrb", "rrr"};
	enum e_command		com;
	int					r;
	char				*s;

	if ((r = get_next_line(fd, &s)) < 0)
		a_error("Input error.\n");
	if (!r)
		return (0);
	com = SA;
	while (com <= RRR)
	{
		if (ft_strequ(s, arr[com]))
			break ;
		++com;
	}
	free(s);
	if (com > RRR)
		error();
	exec_silent(t, com);
	return (1);
}
