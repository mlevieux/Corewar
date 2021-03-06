/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlancien <vlancien@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/19 13:09:50 by vlancien          #+#    #+#             */
/*   Updated: 2016/10/20 18:07:01 by vlancien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

# include "corewar.h"
# include "../../op.h"

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>



typedef struct s_line		t_line;
struct						s_line
{
	char					*method; // sti and live zjmp
	char					*info1;
	char					*info2;
	char					*info3;
	int						nb_info;
	struct s_line			*next;
};

typedef struct				s_op
{
	char					*name;
	int						nb_param;
	char					params_types[4];
	int						opcode;
	int						nb_tours;
	char					*full_name;
	char					params_byte;
	char					index_size;
}							t_op;

typedef struct s_func		t_func;
struct						s_func
{
	char					*label; // l2: ou live;
	t_line					*line; //pointeur sur struct
	struct s_func			*next;
};


typedef struct s_env		t_env;
struct						s_env
{
	char					*name; // .name
	char					*comment; // .comment
	char					*name_file; //nom du .cor en sortie
	int						suite; // instruction fini ou non
	int						y_line;
	t_func					*head; //pointeur sur la tete
	t_func					*tail; // pointeur sur la queue
	t_op					op_tab[17];
};


void		open_line(char *fichier, t_env *e);
void		fille_op_tab(t_env *env);
void		recup_label(char *str, t_env *e);
void		push_tail_label(t_func **begin_list, t_func **end_list, void *data);
void		push_tail_method(t_line **begin_list, char **tab, int nb_arg);












#endif
