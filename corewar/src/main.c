/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sscarecr <sscarecr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/05 16:29:39 by sscarecr          #+#    #+#             */
/*   Updated: 2020/04/12 01:12:59 by sscarecr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"
#include "libft.h"

int	main(int ac, char **av)
{
	t_vm	vm;

	ft_bzero(&vm, sizeof(t_vm));
	input(&vm, ac, av);
	vm.cycles_to_die = CYCLE_TO_DIE;
	vm.next_check = vm.cycles_to_die;
	vm.last_alive = vm.num_players;
	if (vm.visual)
	{
		vm.dump_len = 0;
		vm.verbosity = 0;
	}
	init_arena(&vm);
	if (!vm.visual)
		introduce(&vm);
	if (battle(&vm) && !vm.visual)
		declare_winner(&vm);
	delete_vm(&vm);
	return (0);
}
