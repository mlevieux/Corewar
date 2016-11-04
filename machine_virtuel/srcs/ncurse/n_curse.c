/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   n_curse.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlancien <vlancien@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/27 17:19:56 by vlancien          #+#    #+#             */
/*   Updated: 2016/11/04 18:32:01 by vlancien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "n_curse.h"

void	print_char(char c, int nb)
{
	if (nb < 1)
		return ;
	while (nb != 0)
	{
		printw("%c", c);
		nb--;
	}
}

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

void	print_tab()
{
	int		pair;
	int		x = 0;
	// int		done = 2;

	pair = 0;
	while (x < MEM_SIZE)
	{
		if (pair == 0)
			printw("*");

		if (tab2[x] == 1 && tab3[x] == '-')
		{
			attron(COLOR_PAIR(2));
			printw("%c", tab[x]);
			attroff(COLOR_PAIR(2));

		}
		else if (tab2[x] == 2 && tab3[x] == '-')
			printw("%c", tab[x]);
		else if (tab2[x] == 3 && tab3[x] == '-')
			printw("%c", tab[x]);
		else if (tab2[x] == 4 && tab3[x] == '-')
			printw("%c", tab[x]);
		else if (tab2[x] == 1 && tab3[x] != '-')
		{
			printw("%c", tab[x]);
			tab3[x] = '-';
		}
		else
			printw("%c", tab[x]);
		if (pair % 2 == 1)
			printw(" ");
		pair++;
		x++;
		if (pair == 110) {
			printw("*\n");
			pair = 0;
		}
	}
	printw("\n");
}

void	put_player(t_env *e, int x)
{
	int byte = BYTE_START_CODE;
	int	start = e->players[x].start;
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

void	draw_borders(WINDOW *screen)
{
	int x, y, i;

	getmaxyx(screen, y, x);
	mvwprintw(screen, 0, 0, "+");
	mvwprintw(screen, y - 1, 0, "+");
	mvwprintw(screen, 0, x - 1, "+");
	mvwprintw(screen, y - 1, x - 1, "+");
	for (i = 1; i < (y - 1); i++) {
		mvwprintw(screen, i, 0, "|");
		mvwprintw(screen, i, x - 1, "|");
	}
	for (i = 1; i < (x - 1); i++) {
		mvwprintw(screen, 0, i, "-");
		mvwprintw(screen, y - 1, i, "-");
	}
}

void	n_curse(t_env *e)
{
	int			x = -1, y = 0;

	(void)y;
	initscr();
	cbreak();
	nodelay(stdscr, 1);
	// raw();
	noecho();
	curs_set(0);
	init_curse();
	while (++x < e->active_players)
		put_player(e, x);
	x = 0;
    refresh();

	display_menu(&e->window.menu, e);
	display_tab(&e->window.tab, e);
	display_memory(&e->window.memory, e);
	// lets_play(e);
    getch();
	display_delete(e);
    endwin();
}
