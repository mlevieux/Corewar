/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlancien <vlancien@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/19 12:59:13 by vlancien          #+#    #+#             */
/*   Updated: 2016/10/27 17:24:03 by vlancien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	free_fighter(t_env *e)
{
	int		x;

	x = 0;
	while (x < e->active_players)
	{
		free(e->players[x].name);
		free(e->players[x].file);
		free(e->players[x].comment);
		x++;
	}
}

int		main(int argc, char **argv)

{
	t_env *e;

	e = (t_env *)ft_memalloc(sizeof(t_env));
	if (argc < 2)
		vm_error("Need more argument!");
	parsing_arg(argv, e);
	// int s;
	// s = 0b1011 + 0b111;
	// printf("{{-%d\n", 0b1011 + 0b111);
	// char *a = strdup("1101");
	// char *b = strdup("111");
	// char *result = strdup("");
	// (void)result;
	//
	// int	len = ft_strlen(a) > ft_strlen(b) ? ft_strlen(a) : ft_strlen(b);
	// int retenue = 0;
	// int resultat = 0;
	// int position = 0;
	// int	somme = 0;
	// int	chiffre_a = 0;
	// int	chiffre_b = 0;

	// int index = 0;
	// while (index < len)
	// {
	// 	if (a[index] == '' + b[index] == 0)
	// 	index++;
	// }

	// printf("%d\n", resultat);

	
	if (e->flag.flag_n)
		n_curse(e);
	free_fighter(e);
	free(e);
	return (0);
}
