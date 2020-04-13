/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op4.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sscarecr <sscarecr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/05 16:29:59 by sscarecr          #+#    #+#             */
/*   Updated: 2020/04/13 22:08:28 by sscarecr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"
#include "libft.h"

void	aff(t_process *t, t_vm *vm, t_byte *argtypes, int *args)
{
	(void)vm;
	(void)argtypes;
	ft_printf("Aff: %c\n", (char)t->reg[args[0] - 1]);
}
