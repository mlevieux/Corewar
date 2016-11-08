/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_player_in_memory.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlancien <vlancien@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/05 00:55:52 by vlancien          #+#    #+#             */
/*   Updated: 2016/11/08 19:53:35 by vlancien         ###   ########.fr       */
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

void	afficher(t_env *e)
{
	printf("Process .1. = {%d}\n", e->process[0]->id_player);
	printf("Process .2. = {%d}\n", e->process[1]->id_player);
	// printf("Process .3. = {%d}\n", e->process[2]->id_player);
	// printf("Process .4. = {%d}\n", e->process[0].id_player);
}

void	put_player(t_env *e)
{
	t_process	*list;
	int		x;

	x = -1;
	list = NULL;
	e->process = malloc(sizeof(t_process*));
	e->active_process = e->active_players;
	while (++x < e->active_players)
	{
		init_process(e, x);
		e->players[x].position = e->players[x].start % (MEM_SIZE * 2);
		player_to_tab(e, x);
		e->process[x]->position = e->players[x].position % (MEM_SIZE * 2);
		e->process[x]->start = e->players[x].start % (MEM_SIZE * 2);
		e->process[x]->id_player = e->players[x].id_player;
		printf("New process\n");
	}
	// e->active_process++;
	// init_process(e, 2);
	// e->process[2]->position = 50;
	// e->process[2]->start = 50;
	// e->process[2]->id_player = 1;
	afficher(e);
}
