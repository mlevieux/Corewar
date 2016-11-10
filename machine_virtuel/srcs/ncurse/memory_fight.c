/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory_fight.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlancien <vlancien@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 01:16:37 by vlancien          #+#    #+#             */
/*   Updated: 2016/11/10 10:29:25 by viko             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "n_curse.h"

void	process_cursor(t_env *e, int y, int addr, int x)
{
	int		process;

	process = 0;
	if (addr == e->process[e->memory_data[2]]->position)
	{
		wattron(e->window.memory, COLOR_PAIR(6));
		mvwprintw(e->window.memory, y, x, "%c%c", tab[addr % (MEM_SIZE * 2)], tab[addr + 1 % (MEM_SIZE * 2)]);
		wattroff(e->window.memory, COLOR_PAIR(6));
		wrefresh(e->window.memory);
	}
}

void	exec_process(t_env *e, int xproc)
{
	char	status_code[17][8] = {"None", "live", "ld", "st", "add", "sub", "and", "or", "xor", "zjump", "aff", "ldi", "sti", "fork", "lld", "lldi", "lfork"};
	char	*label;
	char	*size;
	int		jumpx;
	int 	index;
	int		func;

	index = 0;
	label = to_opcode(tab[e->process[xproc]->position % (MEM_SIZE * 2)], tab[(e->process[xproc]->position + 1) % (MEM_SIZE * 2)]);
	func = instruct_tab_value(label);
	size = to_opcode(tab[(e->process[xproc]->position + 2) % (MEM_SIZE * 2)], tab[(e->process[xproc]->position + 3) % (MEM_SIZE * 2)]);
	jumpx = jump(ft_atoi(size), status_code[func]);

	if (func == 1)
	{
		e->process[xproc]->reg[0] = tab2[e->process[xproc]->position % (MEM_SIZE * 2)];
		index = 2;
		while (index < 9) {
			tab[(e->process[xproc]->position + index) % (MEM_SIZE * 2)] = 'F';
			tab2[(e->process[xproc]->position + index) % (MEM_SIZE * 2)] = e->process[xproc]->reg[0];
			index++;
		}
		tab[e->process[xproc]->position + 9 % (MEM_SIZE * 2)] = 'G' - e->process[xproc]->reg[0];
		wrefresh(e->window.memory);
	}
	if (func == 3)
	{
		e->process[xproc]->reg[0] = tab2[e->process[xproc]->position % (MEM_SIZE * 2)];
		set_process(e, e->active_process++, e->process[xproc]->addr_pc + (e->process[xproc]->position % IDX_MOD), xproc - 1);
		// tab[e->process[xproc]->position + 9 % (MEM_SIZE * 2)] = 'G' - e->process[xproc]->reg[0];
		wrefresh(e->window.memory);
	}
	// nodelay(stdscr, 0);
	// getch();
}

void	memory_exec(t_env *e, int *nb)
{
	int		memory_size;

	memory_size = (MEM_SIZE * 2);
	display_menu(&e->window.menu, e);
	while (e->flag.pause == 1 && key_hook(e) == 0)
		;
	wrefresh(e->window.memory);
	if (e->process[*nb]->wait_time - 1 == 0)
	{
		exec_process(e, *nb);
		e->process[*nb]->position = (e->process[*nb]->position + e->process[*nb]->jumptodo) % memory_size;
		find_next_pc(e, *nb);
	}
	usleep(e->flag.time_cycle);
	wrefresh(e->window.menu);
	(*nb)++;
}

void	memory_set_init(t_env *e, int *addr, int *y, int *x)
{
	if (*addr == MEM_SIZE * 2)
		init_index(addr, y, x);
	if (*addr % 2 == 0 && *addr != 0)
	{
		mvwprintw(e->window.memory, *y, *x, " ");
		(*x)++;
	}
	if (*x >= 193 && (*x = 1))
		(*y)++;
}

void	memory_run(t_env *e)
{
	cycle_downer(e, &e->memory_data[2]);
	while (e->memory_data[2] != e->active_process)
	{

		memory_set_init(e, &e->memory_data[3], &e->memory_data[0],
			&e->memory_data[1]);
		find_label(e, e->memory_data[2]);
		// mvwprintw(e->window.memory, 4, 160, "id[%d] pos.%d", e->process[e->memory_data[2]]->id_player, e->process[e->memory_data[2]]->position);
		display_memory_color(e, e->memory_data[0], e->memory_data[3],
			e->memory_data[1]);
		process_cursor(e, e->memory_data[0], e->memory_data[3],
			e->memory_data[1]);
		e->memory_data[3] += 2;
		if (e->memory_data[3] == (MEM_SIZE * 2))
			memory_exec(e, &e->memory_data[2]);
		e->memory_data[1] += 2;
	}
}
