#include <fcntl.h>
#include <limits.h>
#include "pushswap.h"
#include "libft/libft.h"

int		get_flags(int ac, char **av, t_flags *flags)
{
    int		i;
    char	*s;

    i = 0;
    ft_bzero(flags, sizeof(t_flags));
    while (++i < ac && (s = av[i]))
	{
		if (*s != '-' || ft_isdigit(*++s))
			return (ac - i);
        while (*s && ft_strchr("cfv", *s))
		{
			if (*s == 'c')
				flags->colored = 1;
			else if (*s == 'v')
				flags->debug = 1;
			else if (i < ac - 1)
				flags->filename = av[++i];
			else
				a_error("Error: file name missing\n");
			++s;
		}
		if (*s)
			flag_error(*s);
	}
	return (0);
}

t_node	*get_args(int n, char **av)
{
	int		i;
	long	num;
	t_node	*t;
	t_node	*tmp;

	i = 0;
	t = NULL;
	while (i < n)
	{
		num = ft_strtol(*(av + i), av + i, 10);
		if (**(av + i) || num > INT_MAX || num < INT_MIN)
			error();
		if (!push(&t, (int)num))
			a_error("Error: memory allocation failed.\n");
		tmp = t->u;
		while (tmp != t)
		{
			if (tmp->num == t->num)
				error();
			tmp = tmp->u;
		}
		++i;
	}
	return (t);
}
