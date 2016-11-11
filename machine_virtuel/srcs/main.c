/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlancien <vlancien@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/19 12:59:13 by vlancien          #+#    #+#             */
/*   Updated: 2016/11/11 04:55:40 by vlancien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"
#include "n_curse.h"
#include "players.h"

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

char mdec_to_hex[17] = "0123456789ABCDEF";
int mhexdec[256];

char	*dec_to_hex(unsigned dec, char *hex, int len)
{
	char *hex2;
	char	*end;
	char *c;;
	char *s;

	if (hex == NULL)
	{
		len = dec & 0xFFFF0000 ? (dec & 0xFF000000 ? (dec & 0xF0000000 ? 8 : 7) : (dec & 0x00F00000 ? 6 : 5)) : (dec & 0x0000FF00 ? (dec & 0x0000F000 ? 4 : 3) : (dec & 0x000000FF ? (dec & 0x000000F0 ? 2 : 1) : 1));
		hex = malloc((len + 1)*sizeof(char));
	}
	hex2 = hex + len;
	*hex2 = '\0';
	c = hex;
	s = hex2;
	end = hex2;
	for (--hex2; ; hex2--)
	{
		*hex2 = mdec_to_hex[dec & 0xF];
		dec >>= 4;
		if (dec == 0)
			break;
	}
	return (hex2);
}

unsigned hexdec (const char *hex, const int s_hex) {
	if (s_hex == 0) {
		return 0;
	}
	int d = 0, dv = 0, i;
	for (i = 0; i < s_hex; i++) {
		dv = mhexdec[(int) hex[i]];
		if (dv < 0) {
			return 0;
		}
		d += dv * (1 << ((s_hex-i-1) << 2));
	}
	return d;
}

int		main(int argc, char **argv)
{
	t_env *e;

	e = (t_env *)ft_memalloc(sizeof(t_env));
	if (argc < 2)
		vm_error("Need more argument!");
	parsing_arg(argv, e);
	init_curse();
	put_player(e);
	e->arena.cycle = CYCLE_TO_DIE;
	e->flag.pause = 0;
	if (e->flag.flag_n)
		n_curse(e);
	free_fighter(e);
	printf("END OF THE PROGRAM\n");

	char	*x;

	x = dec_to_hex(34, NULL, 0);
	printf("%s\n", x);

	printf("%d\n", hexdec(x, ft_strlen(x)));
	// hex_to_bin_quad("FFFA");
	return (0);
}
