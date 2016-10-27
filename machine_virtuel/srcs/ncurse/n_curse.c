/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   n_curse.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlancien <vlancien@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/27 17:19:56 by vlancien          #+#    #+#             */
/*   Updated: 2016/10/27 19:33:40 by vlancien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "corewar.h"
#include "n_curse.h"
#define X 128
#define Y 64

char tab[Y][X];

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
	int	x, n;

	x = 0;
	n = 0;
	while (x < Y)
	{
		n = 0;
		while (n < X)
		{
			tab[x][n] = '0';
			n++;
		}
		x++;
	}
}

void	print_tab()
{
	int		pair;
	int		x = 0;
	int		y = 0;

	pair = 1;
	while (y < Y)
	{
		x = 0;
		printf(""GREY_BACK"*"NORM_BACK"  ");
		while (x < X)
		{
			printf("%c", tab[y][x]);
			if (pair == 2){
				printf(" ");
				pair = 0;
			}
			pair++;
			x++;
		}
		y++;
		printf(" "GREY_BACK"*"NORM_BACK"\n");
	}
}

void	afficher_tab()
{
	printf(""CLEAR"");
	printf(""GREY_BACK"");
	print_char('*', 255);
	printf("\n*"NORM_BACK"");
	print_char(' ', 195);
	printf(""GREY_BACK"*"NORM_BACK"");
	print_char(' ', 57);
	printf(""GREY_BACK"*"NORM_BACK"\n");
	print_tab();

	printf(""GREY_BACK"*"NORM_BACK"");
	print_char(' ', 195);
	printf(""GREY_BACK"*\n");
	print_char('*', 255);
	printf(""NORM_BACK"");
	printf("\n");
}

void	put_player(t_env *e)
{
	(void)e;
	int byte = BYTE_START_CODE;
	int	x = 0;
	char	*tmp = NULL;

	while (x < 70)
	{
		tmp = print_hexa(e->players[0].file[byte], byte);

		tab[0][x] = tmp[0];
		tab[0][x+1] = tmp[1];
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
	// 64 - 51
	// printf("->%c\n", e->players[0].file[2200]);
}
