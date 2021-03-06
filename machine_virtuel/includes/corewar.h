/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlancien <vlancien@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/19 13:09:50 by vlancien          #+#    #+#             */
/*   Updated: 2016/11/15 12:54:49 by vlancien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COREWAR_H
# define COREWAR_H

# include "libft.h"
# include "../../op.h"
# include <fcntl.h>
# include <sys/types.h>
# include <display.h>
# include "players.h"

# define TRUE 1
# define FALSE 0

char tab[MEM_SIZE * 2];
char tab2[MEM_SIZE * 2];
char tab3[MEM_SIZE * 2];

# define BYTE_START_CODE 2192

typedef struct s_flag	t_flag;
struct					s_flag
{
	int					flag_n;
	int					time_cycle;
	int					pause;
};

typedef struct s_arena	t_arena;
struct					s_arena
{
	char				zone_mem[MEM_SIZE];
	int					cycle;
};

typedef struct s_env	t_env;
struct					s_env
{
	t_flag				flag;
	t_player			players[MAX_PLAYERS];
	int					active_players;
	int					active_process;
	int					memory_data[4];
	t_arena				arena;
	t_window			window;
	t_process			**process;
};

void			vm_error(char *str);
void			parsing_arg(char **arg, t_env *e);
void			reading_file(t_env *e, int x);
void			read_instruction(t_env *e, int x);

int				instruct_tab_value(char *str);
int				get_func_method(int jump, char **action_, char *tmp);

//Players
char			*read_comment(char *file_player);
char			*read_name(char *file_player);
char			*print_hexa(unsigned char c, int byte);

char			*hex_to_bin_quad(char *str_1);
unsigned long	hex_to_dec(char *data, unsigned int size);

void			put_player(t_env *e);
void			player_to_tab(t_env *e, int x);
//Players

// void		new_emptyprocess(t_process **begin_list, t_env *e);
// void		init_temp_process(t_env *e);
int				jump(int code, char *status);
void			find_next_pc(t_env *e, int x);
int				key_hook(t_env *e);
char			*to_opcode(char c, char c1);
void			init_process(t_env *e, int nb);
void			set_process(t_env *e, int process_nb, int x, int creator);

int				check_jump(t_env *e, char *op);
// int		get_process_pos(t_process *list, int x);
// int		get_process_start(t_process *list, int x);
// int		get_process_jumptodo(t_process *list, int x);
// int		set_process_pos(t_env *e, int process, int data);
// int		set_process_jumptodo(t_env *e, int process, int data);

#endif
