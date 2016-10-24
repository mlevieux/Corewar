/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlancien <vlancien@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/19 12:59:13 by vlancien          #+#    #+#             */
/*   Updated: 2016/10/20 17:15:45 by vlancien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	init_env(t_env *e)
{
	e->name = NULL;
	e->comment = NULL;
	e->name_file = NULL;
	e->func = NULL;
	e->suite = 0;
}

char	*parsename(char *argv)
{
	int			a;
	int			b;
	int			c;
	char		*name_file;

	a = ft_strlen(argv);
	if ((a - 2) > 0 && (argv[a - 2] != '.' || argv[a - 1] != 's'))
		return (NULL);
	b = a;
	while (a && argv[a] != '/')
		a--;
	while (b && argv[b] != '.')
		b--;
	a = (argv[a] == '/' ? a + 1 : a);
	name_file = (char *)malloc(b - a + 5);
	c = -1;
	while (a <= b)
		name_file[++c] = argv[a++];
	name_file[c] = '.';
	name_file[c + 1] = 'c';
	name_file[c + 2] = 'o';
	name_file[c + 3] = 'r';
	name_file[c + 4] = '\0';
	printf("%s\n", name_file);
	return (name_file);
}


int		main(int argc, char **argv)
{
	t_env	e;

	if (argc < 2)
		asm_error("asm: need more argument!");
	if (!(e.name_file = parsename(argv[1])))
		asm_error("asm: wrong file extension!");
	printf("%s\n", e.name_file);
	init_env(&e);
	//open_line(argv[1], &e);
	return (0);
}
