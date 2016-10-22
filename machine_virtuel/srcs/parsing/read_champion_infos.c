/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_champion_infos.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlancien <vlancien@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/22 01:34:08 by vlancien          #+#    #+#             */
/*   Updated: 2016/10/22 01:34:30 by vlancien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

char	*read_name(char *file_player)
{
	char	*res = NULL;
	int		byte;
	int		index;

	byte = 4;
	res = malloc(PROG_NAME_LENGTH);
	index = 0;
	while (byte != PROG_NAME_LENGTH)
	{
		res[index] = file_player[byte];
		index++;
		byte++;
	}
	return (res);
}

char	*read_comment(char *file_player)
{
	char	*res = NULL;
	int		byte;
	int		index;

	byte = 140;
	res = malloc(COMMENT_LENGTH);
	index = 0;
	while (byte != COMMENT_LENGTH)
	{
		res[index] = file_player[byte];
		index++;
		byte++;
	}
	return (res);
}
