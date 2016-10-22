/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlancien <vlancien@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/19 13:09:50 by vlancien          #+#    #+#             */
/*   Updated: 2016/10/21 22:35:27 by vlancien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COREWAR_H
# define COREWAR_H

# include "libft.h"
# include "players.h"
# include "../../op.h"
# include <fcntl.h>
# include <sys/types.h>

# define TRUE 1
# define FALSE 0

typedef struct s_flag	t_flag;
struct					s_flag
{
	int					flag_n;
};

typedef struct s_arena	t_arena;
struct					s_arena
{
	char				zone_mem[MEM_SIZE];
};

typedef struct s_env	t_env;
struct					s_env
{
	t_flag				flag;
	t_player			players[MAX_PLAYERS];
	int					active_players;
	t_arena				arena;

};

void		vm_error(char *str);
void		parsing_arg(char **arg, t_env *e);
void		reading_file(t_env *e, int x);
#endif
