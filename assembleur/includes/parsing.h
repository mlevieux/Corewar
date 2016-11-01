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
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>


// typedef struct s_line		t_line;
// struct						s_line
// {
// 	char					*method; // sti and live zjmp
// 	char					*info1;
// 	char					*info2;
// 	char					*info3;
// 	int						nb_info;
// 	struct s_line			*next;
// };

typedef struct s_func		t_func;
struct						s_func
{
	// char					*label; // l2: ou live;
	// t_line					*line; //pointeur sur struct
	char					*line;
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
	t_func					*func; //pointeur sur struct
};

void	open_line(char *fichier, t_env *e);









#endif
