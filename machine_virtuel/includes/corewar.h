/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlancien <vlancien@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/19 13:09:50 by vlancien          #+#    #+#             */
/*   Updated: 2016/11/03 16:28:28 by vlancien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COREWAR_H
# define COREWAR_H

# include "libft.h"
# include "../../op.h"
# include <fcntl.h>
# include <sys/types.h>

# define TRUE 1
# define FALSE 0

# define BYTE_START_CODE 2192

typedef struct s_player	t_player;
struct					s_player
{
	char				*name;
	char				*comment;
	char				*path;
	unsigned long		size;
	int					start;
	int					size_func;
	char				*file;
};

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
void		read_instruction(t_env *e, int x);

int			instruct_tab_value(char *str);
int			get_func_method(int jump, char **action_, char *tmp);
//Players
char	*read_comment(char *file_player);
char	*read_name(char *file_player);
char	*print_hexa(unsigned char c, int byte);
void	hex_to_bin_quad(char *str_1);
//Players
#endif
