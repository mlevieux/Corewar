/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   players.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlancien <vlancien@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/21 17:13:17 by vlancien          #+#    #+#             */
/*   Updated: 2016/10/24 10:38:16 by viko             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PLAYERS_H
# define PLAYERS_H

#include "corewar.h"

typedef struct s_player	t_player;
struct					s_player
{
	char				*name;
	char				*comment;
	char				*path;
	int					size;
	char				*file;
};


char	*read_comment(char *file_player);
char	*read_name(char *file_player);
char	*print_hexa(unsigned char c, int byte);

void	hex_to_bin_quad(char *str_1);
#endif
