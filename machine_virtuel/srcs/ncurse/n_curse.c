/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   n_curse.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlancien <vlancien@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/27 17:19:56 by vlancien          #+#    #+#             */
/*   Updated: 2016/10/28 19:15:11 by vlancien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "n_curse.h"

char tab[MEM_SIZE];
char tab2[MEM_SIZE];

void	print_char(char c, int nb)
{
	if (nb < 1)
		return ;
	while (nb != 0)
	{
		printf("%c", c);
		nb--;
	}
}

void	init_curse()
{
	int n;

	n = 0;
	while (n < MEM_SIZE)
	{
		tab[n] = '0';
		tab2[n] = '0';
		n++;
	}
}

void	print_tab()
{
	int		pair;
	int		x = 0;

	pair = 0;
	while (x < MEM_SIZE)
	{
		if (pair == 0)
			printf(""GREY_BACK"*"NORM_BACK" ");
		if (tab2[x] == 1)
			printf(""GREEN"%c"NORM"", tab[x]);
		else if (tab2[x] == 2)
			printf(""RED"%c"NORM"", tab[x]);
		else if (tab2[x] == 3)
			printf(""YELLOW"%c"NORM"", tab[x]);
		else if (tab2[x] == 4)
			printf(""PURPLE"%c"NORM"", tab[x]);
		else
			printf("%c", tab[x]);
		if (pair % 2 == 1)
			printf(" ");
		pair++;
		x++;
		if (pair == 110) {
			printf(""GREY_BACK"*"NORM_BACK"\n");
			pair = 0;
		}
	}
}

void	afficher_tab()
{
	printf(""CLEAR"");
	printf(""GREY_BACK"");
	print_char('*', 168);
	printf("\n*"NORM_BACK"");
	print_char(' ', 166);
	printf(""GREY_BACK"*"NORM_BACK"\n");
	print_tab();
	printf(""GREY_BACK"*"NORM_BACK"");
	print_char(' ', 125);
	printf(""GREY_BACK"*\n");
	print_char('*', 168);
	printf(""NORM_BACK"");
	printf("\n");
}

void	put_player(t_env *e, int x)
{
	int byte = BYTE_START_CODE;
	int	start = e->players[x].start;
	char	*tmp = NULL;

	while (byte < (int)e->players[x].size)
	{
		tmp = print_hexa(e->players[x].file[byte], byte);
		tab[start % MEM_SIZE] = tmp[0];
		tab[(start + 1) % MEM_SIZE] = tmp[1];
		tab2[start % MEM_SIZE] = x + 1;
		tab2[(start + 1) % MEM_SIZE] = x + 1;
		byte++;
		start += 2;
		free(tmp);
	}
}

void	n_curse(t_env *e)
{
	int			x;

	x = 0;
	init_curse();
	while (x < e->active_players)
	{
		put_player(e, x);
		x++;
	}
	afficher_tab();
}