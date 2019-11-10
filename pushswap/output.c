#include "pushswap.h"

void	show_stacks(t_stack *t)
{
	if (t->a)
	{
		ft_printf("%d\n", t->a->num);
		for (t_node *tmp = t->a->d; tmp != t->a; tmp = tmp->d)
			ft_printf("%d\n", tmp->num);
	}
	else
		ft_printf("Stack A empty\n");
	ft_printf("-----\n");
	if (t->b)
	{
		ft_printf("%d\n", t->b->num);
		for (t_node *tmp = t->b->d; tmp != t->b; tmp = tmp->d)
			ft_printf("%d\n", tmp->num);
	}
	else
		ft_printf("Stack B empty\n");
}

void	print_log(t_stack *t)
{
	t_list	*lst;
	int		n;

	n = 0;
	lst = t->start;
	if (!lst)
		ft_printf("No list!");
	while (lst && ++n)
	{
		ft_printf("%s ", lst->content);
		lst = lst->next;
	}
	ft_printf("\nCom len = %d\n", n);
}
