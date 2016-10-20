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
	e->func = NULL;
}

int		main(int argc, char **argv)
{
	t_env	e;

	if (argc < 2)
		asm_error("Need more argument!");
	init_env(&e);
	open_line(argv[1], &e);
	return (0);
}
