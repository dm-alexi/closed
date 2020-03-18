#ifdef _WIN32
# include <stdio.h>
#endif
#include <unistd.h>
#include "libft.h"
#include "corewar.h"

void	introduce(t_vm *vm)
{
	int	i;

	ft_printf("Introducing contestants...\n");
	i = -1;
	while (++i < vm->num_players)
		ft_printf("* Player %d, weighing %u t_bytes, \"%s\" (\"%s\") !\n", i + 1,
		vm->players[i].header.prog_size, vm->players[i].header.prog_name,
		vm->players[i].header.comment);
}

void	dump(t_vm *vm)
{
	t_byte	*t;
	char	*s;
	char	*str;
	int		size;

	t = vm->arena;
	size = MEM_SIZE * 2 + MEM_SIZE / vm->dump_len +
	(MEM_SIZE % vm->dump_len > 0);
	if (!(str = (char*)malloc(size)))
		sys_error(NULL);
	s = str;
	while (t - vm->arena < MEM_SIZE)
	{
        *s++ = (*t / 16 > 9 ? *t / 16 - 10 + 'a' : *t / 16 + '0');
        *s++ = (*t % 16 > 9 ? *t / 16 - 10 + 'a' : *t / 16 + '0');
        if (!((++t - vm->arena) % vm->dump_len))
			*s++ = '\n';
	}
	if (MEM_SIZE % vm->dump_len > 0)
		*s = '\n';
	write(STDOUT_FILENO, str, size);
}
