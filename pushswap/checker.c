#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include "pushswap.h"

int 	main(int ac, char **av)
{
	int			n;
	int			fd;
	t_flags		flags;
	t_stack		t;

	if (ac > 1 && (n = get_flags(ac, av, &flags)) > 0)
	{
		ft_bzero(&t, sizeof(t));
		t.a = get_args(n, av + ac - n, &n);
		t.a_count = n;
		show_stacks(&t);
        if ((fd = (flags.filename ? open(flags.filename, O_RDONLY) : 0)) < 0)
			file_error(flags.filename);
		while ((n = get_com(fd, &t)))
			;
        write(1, sorted(t.a) && !t.b_count ? "OK\n" : "KO\n", 3);
        show_stacks(&t);
        clear_stacks(&t);
	}
    return 0;
}
