/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   n_curse.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlancien <vlancien@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/27 17:26:39 by vlancien          #+#    #+#             */
/*   Updated: 2016/11/03 16:52:35 by vlancien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef N_CURSE_H
# define N_CURSE_H

# include "corewar.h"
# include "game.h"
# include <ncurses.h>

char tab[MEM_SIZE];
char tab2[MEM_SIZE];
char tab3[MEM_SIZE];

void	n_curse(t_env *e);
void	print_ncurse();

#endif
