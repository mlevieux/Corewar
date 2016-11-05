/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlancien <vlancien@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/01 17:54:35 by vlancien          #+#    #+#             */
/*   Updated: 2016/11/05 16:59:38 by vlancien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_H
# define GAME_H

# include "corewar.h"
# include "players.h"
# include "n_curse.h"
# include <ncurses.h>

void	lets_play(t_env *e);
void	find_label(t_env *e, int x);
#endif
