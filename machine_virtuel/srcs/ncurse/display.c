/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlancien <vlancien@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 16:58:08 by vlancien          #+#    #+#             */
/*   Updated: 2016/11/08 20:33:22 by vlancien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "n_curse.h"

void	name_menu(t_env *e, int nb)
{
	wattron(e->window.menu, COLOR_PAIR(nb + 1));
	mvwprintw(e->window.menu, ((nb+1) * 1.8) + 1, 12, "%s", e->players[nb].name);
	wattroff(e->window.menu, COLOR_PAIR(nb + 1));
}

void	display_info_menu(WINDOW **menu, t_env *e)
{
	(void)e;
	mvwprintw(*menu, 1, 165, "CYCLE_TO_DIE: ");
	mvwprintw(*menu, 2, 165, "CYCLE_DELTA: ");
	mvwprintw(*menu, 3, 165, "CYCLE: ");
	wattron(e->window.menu, COLOR_PAIR(5));
	mvwprintw(*menu, 1, 180, "%d", CYCLE_TO_DIE);
	mvwprintw(*menu, 2, 180, "%d", CYCLE_DELTA);
	mvwprintw(*menu, 3, 180, "%d", e->arena.cycle);
	wattroff(e->window.menu, COLOR_PAIR(5));
	wrefresh(*menu);
}

void	display_menu(WINDOW **menu, t_env *e)
{
	int		nb;

	nb = 0;
	*menu = newwin(10, 196, 68, 0);
	draw_borders(*menu);
	display_info_menu(menu, e);
	while (nb < e->active_players)
	{
		wattron(*menu, COLOR_PAIR(5));
		mvwprintw(*menu, ((nb+1) * 1.8 ) + 1 , 1, "Joueur %d: ", nb + 1);
		wattroff(*menu, COLOR_PAIR(5));
		mvwprintw(*menu, ((nb+1) * 1.8 ) + 1 , 35, "|");
		name_menu(e, nb);
		nb++;
	}
	wrefresh(*menu);
}

void	display_tab(WINDOW **tab, t_env *e)
{
	(void)e;

	*tab = newwin(68, 196, 0, 0);
	draw_borders(*tab);
	wrefresh(*tab);
}

void	init_index(int *x, int *y, int *u, int *i)
{
	*x = 0;
	*y = 1;
	*u = 1;
	*i = 0;
}

void	display_memory_color(t_env *e, int y, int x, int u)
{
	if (tab2[x] >= 1 && tab2[x] <= 4)
	{
		wattron(e->window.memory, COLOR_PAIR(tab2[x]));
		mvwprintw(e->window.memory, y, u , "%c%c", tab[x], tab[x + 1]);
		wattroff(e->window.memory, COLOR_PAIR(tab2[x]));
	}
	else
		mvwprintw(e->window.memory, y, u , "%c%c", tab[x], tab[x + 1]);
}

void	process_cursor(t_env *e, int nb, int y, int x, int u)
{
	int		process;

	process = 0;
	(void)u;
	(void)y;
	(void)x;
	if (x == e->process[nb]->position)
	{
		wattron(e->window.memory, COLOR_PAIR(6));
		mvwprintw(e->window.memory, y, u, "%c%c", tab[x], tab[x + 1]);
		wattroff(e->window.memory, COLOR_PAIR(6));
	}
}

void	display_memory(WINDOW **memory, t_env *e)
{
	int		y;
	int		x;
	int		u;
	int		i;
	int		nb = 0;

	*memory = newwin(66, 194, 1, 1);
	init_index(&x, &y, &u, &i);
	// printf("e->active_process = %d\n", e->active_process);
	while ((i = getch()) != 27)
	{
		if (nb == e->active_process)
			nb = 0;
		while (nb != e->active_process)
		{
			if (x == MEM_SIZE * 2)
				init_index(&x, &y, &u, &i);
			if (x % 2 == 0 && x != 0)
			{
				mvwprintw(*memory, y, u, " ");
				u++;
			}
			if (u >= 193 && (u = 1))
				y++;
			find_label(e, nb);
			display_memory_color(e, y, x, u);
			process_cursor(e, nb, y, x, u);
			x += 2;
			if (x == MEM_SIZE * 2)
			{
				e->arena.cycle--;
				wrefresh(e->window.menu);
				display_menu(&e->window.menu, e);
				wrefresh(*memory);
				e->process[nb]->position = (e->process[nb]->position + e->process[nb]->jumptodo) % (MEM_SIZE * 2);
				i = 0;
				usleep(10000);
				// sleep(1);
				// printf("Work ON %d\n", nb);
				nb++;
			}
			u += 2;
		}
	}
}

void	display_init_color()
{
	start_color();
	// init_color(COLOR_CYAN, 0, 0, 255);

	init_pair(1, COLOR_GREEN, COLOR_BLACK);
	init_pair(10, COLOR_WHITE, COLOR_GREEN);

	init_pair(2, COLOR_BLUE, COLOR_BLACK);
	init_pair(20, COLOR_BLACK, COLOR_BLUE);

	init_pair(3, COLOR_YELLOW, COLOR_BLACK);
	init_pair(30, COLOR_BLUE, COLOR_YELLOW);

	init_pair(4, COLOR_RED, COLOR_BLACK);
	init_pair(40, COLOR_BLACK, COLOR_RED);

	init_pair(5, COLOR_MAGENTA, COLOR_BLACK);
	init_pair(6, COLOR_BLACK, COLOR_YELLOW);

}

void	display_delete(t_env *e)
{
	delwin(e->window.tab);
	delwin(e->window.memory);
    delwin(e->window.menu);
}
