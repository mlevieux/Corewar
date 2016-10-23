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
#include "../../op.h"

void	free_2d_tab(char **tab, int size)
{
	int a;

	a = 0;
	if (tab == NULL)
		return ;
	while (tab[a] && tab[a][0] && (a < size - 1))
	{
		free(tab[a]);
		++a;
	}
	free(tab[a]);
	free(tab);
}

void			print_2d_tab(char **tab, int size)
{
	int a;

	a = 0;
	if (tab == NULL)
		return ;
	while (tab[a] && tab[a][0] && (a < size - 1))
	{
		ft_putendl(tab[a]);
		++a;
	}
	ft_putendl(tab[a]);
}

void	name_comment(char *str, t_env *e)
{
	char **tab;

	tab = ft_strsplit(str, '\"');
	if ((str[1] == 'n') && (str[2] == 'a') && (str[3] == 'm') && (str[4] == 'e'))
	{
		e->name = ft_strdup(tab[1]);
		if (ft_strlen(e->name) > PROG_NAME_LENGTH)
		{
			printf("Champion name to long (Max lenght %d)\n", PROG_NAME_LENGTH);
			free_2d_tab(tab, 2);
			exit(-1);
		}
	}
	else if ((str[1] == 'c') && (str[2] == 'o') && (str[3] == 'm')
		&& (str[4] == 'm') && (str[5] == 'e') && (str[6] == 'n') && (str[7] == 't'))
	{
		 e->comment = ft_strdup(tab[1]);
		 if (ft_strlen(e->comment) > COMMENT_LENGTH)
		{
			printf("Champion comment to long (Max lenght %d)\n", COMMENT_LENGTH);
			free_2d_tab(tab, 2);
			exit(-1);
		}
	}
	free_2d_tab(tab, 2); // veriffier les leaks
}

void	stock_line(char *str, t_env *e)
{
	if ((str[0] == 0) || (str[0] == '#'))
	{
		printf("ligne vide ou #\n");
		free(str);
		e->suite = 0;
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
	printf("%s->%s\n", e->name, e->comment);
}
