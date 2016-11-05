/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlancien <vlancien@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/20 16:57:55 by vlancien          #+#    #+#             */
/*   Updated: 2016/11/05 02:06:44 by vlancien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int		flag(char *str)
{
	int		index;

	index = 0;
	if (str[0] == '-' && str[1] == 'n')
		return (TRUE);
	return (FALSE);
}

int		is_cor(char *str)
{
	int		index;

	index = ft_strlen(str);
	if (index < 4)
		vm_error("File error. Need *.cor !");
	if (strstr(str, ".cor\0"))
		return (1);
	return (0);
}

void	get_flag_prog(char *arg, t_env *e)
{
	(void)e;
	if (flag(arg)){
		printf(""RED"%s\n"NORM"", arg);
		e->flag.flag_n = 1;
	}
	else if (e->active_players != MAX_PLAYERS && is_cor(arg))
	{
		e->players[e->active_players].path = arg;
		e->active_players++;
	}
	else if (e->active_players == MAX_PLAYERS)
		vm_error("Too much champions!");
}

void	get_pos_champion(t_env *e, int size_total)
{
	int		size;

	size = (MEM_SIZE * 2) / (e->active_players);
	printf("active_players %d\n",MEM_SIZE * 2);
	(void)size_total;
	e->players[0].start = 0;
	if (e->active_players >= 2)
		e->players[1].start = size;
	if (e->active_players >= 3)
		e->players[2].start = size * 2;
	if (e->active_players >= 4)
		e->players[3].start = size * 3;
}

void	parsing_arg(char **arg, t_env *e)
{
	int		i;
	int		size_total = 0;

	i = 1;
	while (arg[i])
	{
		get_flag_prog(arg[i], e);
		i++;
	}
	int x = 0;
	while (x < e->active_players)
	{
		printf("Champion %d: %s\n",x + 1, e->players[x].path);
		reading_file(e, x);
		printf("Player name: %s\n", e->players[x].name);
		printf("Player comment: %s\n", e->players[x].comment);
		e->players[x].id_player = x;
		size_total += e->players[x].size_func;
		x++;
		printf("\n");
	}
	if ((MEM_SIZE * 2) < size_total)
		vm_error("Not enough space available.");
	get_pos_champion(e, size_total);
	return ;
}
