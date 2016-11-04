/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   n_curse.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlancien <vlancien@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/27 17:26:39 by vlancien          #+#    #+#             */
/*   Updated: 2016/11/04 17:49:38 by vlancien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef N_CURSE_H
# define N_CURSE_H

# include "corewar.h"
# include "game.h"
# include <ncurses.h>

char tab[MEM_SIZE * 2];
char tab2[MEM_SIZE * 2];
char tab3[MEM_SIZE * 2];

void	n_curse(t_env *e);
void	print_ncurse();

void	draw_borders(WINDOW *screen);

void	display_menu(WINDOW **menu, t_env *e);
void	display_tab(WINDOW **tab, t_env *e);
void	display_memory(WINDOW **memory, t_env *e);
void	display_delete(t_env *e);

#endif
