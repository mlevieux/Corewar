/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   n_curse.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlancien <vlancien@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/27 17:19:56 by vlancien          #+#    #+#             */
/*   Updated: 2016/10/27 19:54:43 by viko             ###   ########.fr       */
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
		else
			printf("%c", tab[x]);
		if (pair % 2 == 1){
			printf(" ");
			// pair = 0;
		}
		pair++;
		x++;
		if (pair == 110){
			printf(""GREY_BACK"*"NORM_BACK"\n");
			pair = 0;
		}
	}
}

void	afficher_tab()
{
	printf(""CLEAR"");
	printf(""GREY_BACK"");
	print_char('*', 180);
	printf("\n*"NORM_BACK"");
	print_char(' ', 166);

	printf(""GREY_BACK"*"NORM_BACK"\n");
	print_tab();

	printf(""GREY_BACK"*"NORM_BACK"");
	print_char(' ', 125);
	printf(""GREY_BACK"*\n");
	print_char('*', 180);
	printf(""NORM_BACK"");
	printf("\n");
}

void	put_player(t_env *e)
{
	(void)e;
	int byte = BYTE_START_CODE;
	int	x = 0;
	char	*tmp = NULL;

	while (byte < (int)e->players[0].size)
	{
		tmp = print_hexa(e->players[0].file[byte], byte);

		tab[x] = tmp[0];
		tab[x+1] = tmp[1];
		tab2[x] = 1;
		tab2[x+1] = 1;
		byte++;
		x += 2;
		free(tmp);
	}
}

void	n_curse(t_env *e)
{
	init_curse();

	(void)e;
	put_player(e);
	afficher_tab();

	char *tmp;
	char *tmp2;
	tmp = strdup("Salut");
	tmp = ft_strjoin(""GREEN"", tmp);
	tmp2 = ft_strjoin(""YELLOW"", tmp);
	ft_putstr(tmp2);
	// 64 - 51
	// printf("->%c\n", e->players[0].file[2200]);
}
