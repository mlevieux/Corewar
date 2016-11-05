/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_player_in_memory.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlancien <vlancien@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/05 00:55:52 by vlancien          #+#    #+#             */
/*   Updated: 2016/11/05 17:06:00 by vlancien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

void	player_to_tab(t_env *e, int x)
{
	int		byte = BYTE_START_CODE;
	int		start = e->players[x].start;
	char	*tmp = NULL;

	while (byte < (int)e->players[x].size)
	{
		tmp = print_hexa(e->players[x].file[byte], byte);
		tab[start % (MEM_SIZE * 2)] = tmp[0];
		tab[(start + 1) % (MEM_SIZE * 2)] = tmp[1];
		tab2[start % (MEM_SIZE * 2)] = x + 1;
		tab2[(start + 1) % (MEM_SIZE * 2)] = x + 1;
		byte++;
		start += 2;
		free(tmp);
	}
}

void	put_player(t_env *e)
{
	int		x;

	x = -1;
	while (++x < e->active_players){
		e->players[x].position = e->players[x].start;
		e->players[x].process = (t_process*)malloc(sizeof(t_process));
		e->players[x].process->start = e->players[x].position;
		e->players[x].process->position = e->players[x].position;
		player_to_tab(e, x);
	}
}
