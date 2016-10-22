/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlancien <vlancien@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/20 16:57:55 by vlancien          #+#    #+#             */
/*   Updated: 2016/10/20 17:17:28 by vlancien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

void	name_comment(char *str, t_env *e)
{
	if ((str[1] == 'n') && (str[2] == 'a') && (str[3] == 'm') && (str[4] == 'e")) 
		e->name = 
	else if ((str[1] == 'c') && (str[2] == 'o') && (str[3] == 'm')
		&& (str[4] == 'm') && (str[5] == 'e') && (str[6] == 'n') &&  (str[6] == 't'))
		 

}

void	stock_line(char *str, t_env *e)
{
	if (str[0] == 0)
	{
		printf("toto\n");
		free(str);
		return ;
	}
	else if (str[0] == '.')
		name_comment(str, e);
	else
		other(str, e);
}

void	open_line(char *fichier, t_env *e)
{
	int		fd;
	char	*line;

	fd = open(fichier, O_RDONLY);
	if (fd == -1)
		asm_error("open_error");
	while (get_next_line(fd, &line) == 1)
	{
		stock_line(line, e);
	}
	if (close(fd) != 0)
		asm_error("close_error");
}
