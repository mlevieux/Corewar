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


// typedef struct		header_s
// {
//   unsigned int		magic;
//   char				prog_name[PROG_NAME_LENGTH + 1];
//   unsigned int		prog_size;
//   char				comment[COMMENT_LENGTH + 1];
// }					header_t;

unsigned int	little_to_big(unsigned int little)
{
	unsigned int	big;

	big = ((little >> 24 )& 0xff) | ((little << 8) & 0xff0000) |
	((little >> 8) & 0xff00) | ((little << 24 )& 0xff000000);
	return (big);
}

void	create_file(t_env *e)
{
	int			fd;
	header_t	header;

	ft_bzero(header.prog_name, PROG_NAME_LENGTH + 1);
	ft_bzero(header.comment, COMMENT_LENGTH + 1);

	header.prog_size = 0; // a calculer


	header.magic = little_to_big(COREWAR_EXEC_MAGIC);
	ft_strncpy(header.prog_name ,e->name,PROG_NAME_LENGTH);
	ft_strncpy(header.comment ,e->comment, COMMENT_LENGTH);
	if ((fd = open(e->name_file, O_WRONLY | O_CREAT | O_TRUNC, 0644)) == -1)
		ft_printf("%s\n", e->name_file);
	write(fd, &header, sizeof(header));
	if (close(fd) != 0)
		asm_error("close_error_.cor");
}

void	init_env(t_env *e)
{
	e->name = NULL;
	e->comment = NULL;
	e->name_file = NULL;
	e->func = NULL;
	e->suite = 0;
	e->y_line = 0;
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
	return (name_file);
}

void	print_all(t_env *e)
{
	t_func	*tmp_label;
	t_line	*tmp_method;

	tmp_label = e->func;
	while (tmp_label != NULL)
	{	
		if (tmp_label)
			printf("%s\n", tmp_label->label);
		tmp_method = tmp_label->line;
		if (tmp_method)
		while (tmp_method->next != NULL)
		{
			if (tmp_method)
				printf("%s %s %s %s\n", tmp_method->method,
					tmp_method->info1, tmp_method->info2, tmp_method->info3);
			tmp_method = tmp_method->next;
		}
		if (tmp_method)
			printf("%s %s %s %s\n", tmp_method->method,
				tmp_method->info1, tmp_method->info2, tmp_method->info3);
		tmp_label = tmp_label->next;
	}
}

int		main(int argc, char **argv)
{
	t_env		e;

	if (argc < 2)
		asm_error("Usage: ./asm <sourcefile.s>");
	init_env(&e);
	if (!(e.name_file = parsename(argv[1])))
		asm_error("asm: wrong file extension!");
	printf("%s\n", e.name_file);
	open_line(argv[1], &e);
	create_file(&e);
	print_all(&e);
	return (0);
}
