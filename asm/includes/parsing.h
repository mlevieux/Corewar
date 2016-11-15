/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlancien <vlancien@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/19 13:09:50 by vlancien          #+#    #+#             */
/*   Updated: 2016/11/15 19:07:02 by mlevieux         ###   ########.fr       */
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
	int						method_position; // position en octe de l'info
	int						method_total;
	int						opcode; // code binaire de la method
	int						nb_tab; // num dans le tab op_tab

	int						nb_info; // nombre d'info
	char					*info1;
	int						intfo1[2]; // info transformer en int_fo
	char					*info2;
	int						intfo2[2];
	char					*info3;
	int						intfo3[2];

	int						encod; // code binaire des arguments
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
	char					*label; // nom du truc de merde
	t_line					*line; //pointeur sur struct
	struct s_func			*next;
};


typedef struct s_env		t_env;
struct						s_env
{
	char					*name; // .name
	char					*comment; // .comment
	char					*name_file; //nom du .cor en sortie
	int						suite; // fini ou non
	int						y_line;
	t_func					*head; //pointeur sur la tete
	t_func					*tail; // pointeur sur la queue
	t_op					op_tab[17];

	int						method_position;
	int						method_total;
	int						nb_tab;
};


void		open_line(char *fichier, t_env *e);
void		fille_op_tab(t_env *env);
void		recup_label(char *str, t_env *e);
void		push_tail_label(t_func **begin_list, t_func **end_list, void *data);
void		push_tail_method(t_line **begin_list, char **tab, int nb_arg, t_env *e);
int			ft_parse_match(char *reg, char *str);
void		trim_args(t_env *env);
int			check_param(int nb_tab, t_op op_tab[], char *info, int nb_param);
int			params_correspond(t_env *file);
int			labels_are_defined(t_env *env);











#endif
