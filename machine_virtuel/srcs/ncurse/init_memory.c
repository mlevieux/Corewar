/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_memory.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlancien <vlancien@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/05 00:52:00 by vlancien          #+#    #+#             */
/*   Updated: 2016/11/08 18:13:57 by vlancien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"
#include "n_curse.h"

void	init_curse()
{
	int n;

	n = 0;
	while (n < MEM_SIZE * 2)
	{
		tab[n] = '0';
		tab2[n] = '0';
		tab3[n] = '-';
		n++;
	}
}

// void			init_temp_process(t_env *e)
// {
// 	e->temp_process.start = 0;
// 	e->temp_process.position = 0;
// 	e->temp_process.jumptodo = 0;
// 	e->temp_process.carry = 0;
// 	e->temp_process.id_player = 0;
// 	ft_memset(e->temp_process.reg, 0, 17);
// }

void			init_process(t_env *e, int nb)
{
	e->process[nb] = malloc(sizeof(t_process));
	e->process[nb]->start = 0;
	e->process[nb]->position = 0;
	e->process[nb]->jumptodo = 0;
	e->process[nb]->carry = 0;
	e->process[nb]->id_player = 0;
	ft_memset(e->process[nb]->reg, 0, 17);
	// init_temp_process(e);
}
