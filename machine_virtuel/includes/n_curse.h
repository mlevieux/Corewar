/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   n_curse.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlancien <vlancien@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/27 17:26:39 by vlancien          #+#    #+#             */
/*   Updated: 2016/11/05 00:51:43 by vlancien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef N_CURSE_H
# define N_CURSE_H

# include "corewar.h"
# include "game.h"
# include <ncurses.h>

void	n_curse(t_env *e);
void	draw_borders(WINDOW *screen);
void	init_curse();

void	display_menu(WINDOW **menu, t_env *e);
void	display_tab(WINDOW **tab, t_env *e);
void	display_memory(WINDOW **memory, t_env *e);
void	display_init_color(void);
void	display_delete(t_env *e);

#endif
