/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlancien <vlancien@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/01 17:50:40 by vlancien          #+#    #+#             */
/*   Updated: 2016/11/03 17:07:33 by vlancien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

int		jump(int code, char *status)
{
	int		jump;

	jump = 1;
	if (code == 90 && !ft_strcmp(status, "ld"))
		return (14);
	else if (code == 68 && !ft_strcmp(status, "sti"))
		return (14);
	else if (code == 64 && !ft_strcmp(status, "sti"))
		return (12);
	else if (code == 70 && !ft_strcmp(status, "st"))
		return (10);
	else if (!ft_strcmp(status, "live"))
		return (10);
	else if (!ft_strcmp(status, "fork"))
		return (6);
	else if (code == 94 && !ft_strcmp(status, "ldi"))
		return (12);
	else if (!ft_strcmp(status, "zjump"))
		return (6);
	else if (code == 58)
		return (12);
	else if (code == 54 && !ft_strcmp(status, "add"))
		return (10);
	else if (code == 64 && !ft_strcmp(status, "and"))
		return (16);
	else if (code == 54 && !ft_strcmp(status, "xor"))
		return (10);
	else if (code == 64 && !ft_strcmp(status, "xor"))
		return (16);
	return (jump);
}

void	curse_player()
{
	char	status_code[17][16] = {"None", "live","ld","st","add","sub","and","or","xor","zjump","aff","ldi","sti","fork","lld","lldi","lfork"};
	int		x;
	char	*hex;
	char	*code;
	int		done;

	done = 0;
	x = 0;
	hex = malloc(sizeof(char) * 8);
	code = malloc(sizeof(char) * 8);
	hex[7] = '\0';
	code[2] = '\0';
	while (1)
	{
		if (tab2[x % MEM_SIZE] == 1)
		{
			hex[0] = tab[x % MEM_SIZE];
			hex[1] = tab[x % MEM_SIZE + 1];
			code[0] = tab[x % MEM_SIZE + 2];
			code[1] = tab[x % MEM_SIZE + 3];
			printf("%s, %s\n", status_code[instruct_tab_value(hex)], code);
			if (tab3[x] == '-' && !done)
			{
				tab3[x ] = tab[x ];
				tab3[(x ) + 1] = tab[(x ) + 1];
				done = jump(ft_atoi(code), status_code[instruct_tab_value(hex)]);
			}
			x += jump(ft_atoi(code), status_code[instruct_tab_value(hex)]);
			printf(""CLEAR"");
			usleep(70000);
			print_ncurse();
			if (done)
				done -= 2;
		}
	}
	return ;
}

void	lets_play(t_env *e)
{
	int		cycle;

	cycle = 1;
	(void)e;

	while (cycle > 0)
	{
		// curse_player();

		clear();
		printw("Timeleft : %d", cycle);
		start_color();
		init_pair(1, COLOR_WHITE, COLOR_GREEN);
		attron(COLOR_PAIR(1));
		printw("test\n");
		attroff(COLOR_PAIR(1));
		usleep(70000);

		// refresh();
		cycle--;
	}
}
