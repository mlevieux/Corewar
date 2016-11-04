/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlancien <vlancien@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 16:58:08 by vlancien          #+#    #+#             */
/*   Updated: 2016/11/04 18:31:31 by vlancien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "n_curse.h"

void	display_menu(WINDOW **menu, t_env *e)
{
	(void)e;
	*menu = newwin(10, 196, 68, 0);

	draw_borders(*menu);
	mvwprintw(*menu, 1, 200 / 2, "Menu");
	wrefresh(*menu);
}

void	display_tab(WINDOW **tab, t_env *e)
{
	(void)e;

	*tab = newwin(68, 196, 0, 0);
	draw_borders(*tab);
	wrefresh(*tab);
}

void	init_index(int *x, int *y, int *u)
{
	start_color();
	init_pair(1, COLOR_WHITE, COLOR_GREEN);
	init_pair(2, COLOR_YELLOW, COLOR_BLUE);
	init_pair(3, COLOR_WHITE, COLOR_YELLOW);
	init_pair(4, COLOR_WHITE, COLOR_RED);
	*x = 0;
	*y = 1;
	*u = 1;
}

void	display_memory_color(t_env *e, int y, int x, int u)
{
	if (tab2[x] == 1)
	{
		wattron(e->window.memory, COLOR_PAIR(1));
		mvwprintw(e->window.memory, y, u , "%c", tab[x]);
 		wattroff(e->window.memory, COLOR_PAIR(1));
	}
	else if (tab2[x] == 2)
	{
		wattron(e->window.memory, COLOR_PAIR(2));
		mvwprintw(e->window.memory, y, u , "%c", tab[x]);
		wattroff(e->window.memory, COLOR_PAIR(2));
	}
	else
		mvwprintw(e->window.memory, y, u , "%c", tab[x]);
}

void	display_memory(WINDOW **memory, t_env *e)
{
	int		y;
	int		x;
	int		u;

	*memory = newwin(66, 194, 1, 1);
	init_index(&x, &y, &u);
	while (getch() != 27)
	{
		if (x == MEM_SIZE * 2)
			init_index(&x, &y, &u);
		if (x % 2 == 0 && x != 0)
		{
			mvwprintw(*memory, y, u, " ");
			u++;
		}
		if (u >= 193 && (u = 1))
			y++;
		display_memory_color(e, y, x, u);
		mvwprintw(e->window.menu, 1, 1, "Test affichage %d", -x);
		wrefresh(*memory);
		wrefresh(e->window.menu);
		x++;
		u++;
	}
	wrefresh(*memory);
}

void	display_delete(t_env *e)
{
	delwin(e->window.tab);
	delwin(e->window.memory);
    delwin(e->window.menu);
}
