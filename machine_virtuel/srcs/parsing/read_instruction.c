/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_instruction.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viko <viko@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/24 09:02:53 by viko              #+#    #+#             */
/*   Updated: 2016/10/24 13:58:34 by viko             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	read_instruction(t_env *e, int x)
{
	char	*tmp = NULL;
	int		byte;
	char	c = 0;

	byte = 2192;
	while (1)
	{
		c = e->players[x].file[byte];
		printf("%s\n", (tmp = print_hexa(c, byte)));
		if  (!ft_strcmp("01", tmp))
			printf("live\n");
		if  (!ft_strcmp("02", tmp))
			printf("ld\n");
		if  (!ft_strcmp("03", tmp))
			printf("st\n");
		if  (!ft_strcmp("04", tmp))
			printf("add\n");
		if  (!ft_strcmp("05", tmp))
			printf("sub\n");
		if  (!ft_strcmp("06", tmp))
			printf("and\n");
		if  (!ft_strcmp("07", tmp))
			printf("or\n");
		if  (!ft_strcmp("08", tmp))
			printf("xor\n");
		if  (!ft_strcmp("09", tmp))
			printf("zjump\n");
		if  (!ft_strcmp("10", tmp))
			printf("aff\n");
		if  (!ft_strcmp("0a", tmp))
			printf("ldi\n");
		if  (!ft_strcmp("0b", tmp))
			printf("sti\n");
		if  (!ft_strcmp("0c", tmp))
			printf("fork\n");
		if  (!ft_strcmp("0d", tmp))
			printf("lld\n");
		if  (!ft_strcmp("0e", tmp))
			printf("lldi\n");
		if  (!ft_strcmp("0f", tmp))
			printf("lfork\n");
		hex_to_bin_quad(tmp);
		byte++;
		if (byte == 2200)
			break;
	}
}
