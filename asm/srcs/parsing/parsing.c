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

void	double_cote(char *str, char *error)
{
	int	a;

	a = 0;
	while (*str)
	{
		if (*str == '\"')
			a++;
		str++;
	}
	if (a != 2)
		asm_error(error);
}
void	name_comment(char *str, t_env *e)
{
	char	**tab;

	tab = ft_strsplit(str, '\"');
	if ((str[1] == 'n') && (str[2] == 'a') && (str[3] == 'm') && (str[4] == 'e'))
	{
		double_cote(str, "error in .name");
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
		double_cote(str, "error in .comment");
		e->comment = ft_strdup(tab[1]);
		if (ft_strlen(e->comment) > COMMENT_LENGTH)
		{
			printf("Champion comment to long (Max lenght %d)\n", COMMENT_LENGTH);
			free_2d_tab(tab, 2);
			exit(-1);
		}
	}
	free_2d_tab(tab, 2);
}

int		epur_str(char *str)
{
	int		nb_c;
	int		old;
	int		new;
	int		find;

	nb_c = 0;
	old = 0;
	new = 0;
	find = 0;
	while (str[old] && (str[old] == ' ' || str[old] == '\t'))
		old++;
	while (str[old])
	{
		if (str[old] != ' ' && str[old] != '\t')
		{
			str[new] = str[old];
			new++;
			old++;
		}
		while (str[old] && (str[old] == ' ' || str[old] == '\t'))
		{
			find = 1;
			old++;
		}
		if ((find == 1) && str[old])
		{
			find = 0;
			str[new] = ' ';
			new ++;
			nb_c++;
		}
	}
	str[new] = '\0';
	return nb_c;
}

int		is_command(char *str, t_env *e)
{
	int i;

	i = 0;

	while (i < 17)
	{
		//printf("%s == %s\n", str, e->op_tab[i].name);
		if (ft_strcmp(str, e->op_tab[i].name) == 0)
		{
			e->nb_tab = i;
			return (e->op_tab[i].nb_param);
		}
		i++;
	}
	e->nb_tab = 16;
	printf("Syntax error in line %d\n", e->y_line);
	exit(1);
	return (0);
}
void	other(char *str, t_env *e)
{
	char	**tab;
	int		nb_space;
	int		command;

	nb_space = epur_str(str);
	tab = ft_strsplit(str, ' ');
	// printf("%s =>> ", str);
	// printf("%d\n", nb_space);
	if (nb_space == 0)
	{
		// printf("label\n");
		push_tail_label(&e->head, &e->tail, tab[0]);
		return ;
	}
	command = is_command(tab[0], e);
	if (nb_space != command)
	{
		printf("Syntax error in line %d\n", e->y_line);
		exit(1);
	}
	else
		push_tail_method(&e->tail->line, tab, command, e);

}

void	stock_line(char *str, t_env *e)
{
	if ((str[0] == 0) || (str[0] == COMMENT_CHAR) || (str[0] == COMMENT_CHAR2))
	{
		printf("ligne vide ou # ou ;\n");
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
	char	*line;
	int		fd;

	fd = open(fichier, O_RDONLY);
	if (fd == -1)
		asm_error("open_error");
	while (get_next_line(fd, &line) == 1)
	{
		++e->y_line;
		stock_line(line, e);
	}
	if (close(fd) != 0)
		asm_error("close_error");
	printf("%s->%s\n", e->name, e->comment);
}

	// off_t	lenght_file;
	// if ((lenght_file =  lseek(fd, 0, SEEK_END)) > CHAMP_MAX_SIZE) //a faire sur le binaire
		// asm_error("fichier trop long");
