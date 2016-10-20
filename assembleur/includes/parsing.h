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

typedef struct s_env		t_env;
struct						s_env
{
	char					*name;
	char					*comment;
	t_func					*func;
};

typedef struct s_func		t_func;
struct						s_func
{
	char					*name_func;
	t_line					*lines;
	struct s_func			*next;
};

typedef struct s_line		t_line;
struct						s_line
{
	t_list					*list_action;
	char					*method;
	struct s_line			*next;
};

#endif
