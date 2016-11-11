/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   function.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlancien <vlancien@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 17:37:17 by vlancien          #+#    #+#             */
/*   Updated: 2016/11/11 04:59:03 by vlancien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "n_curse.h"

void	(*g_func_process[5])(t_env*, int, int) = {live_func, live_func, live_func, add_func, sub_func};

void	apply_func(t_env *e, int xproc, int func)
{
	if (func == 1 || func == 3 || func == 4)
		g_func_process[func - 1](e, xproc, func);
}

void	ld_func(t_env *e, int xproc, int func)
{
	char	number[1][4];
	// char	regist[1][2];
	// char	reg_result[1][4];
	int		index;

	(void)func;
	index = 4;
	while (index < 8)
	{
		number[0][index - 4] = tab[(e->process[xproc]->position + index) % ((MEM_SIZE) * 2)];
		index++;
	}

	// char *nb = dec_to_hex(ft_atoi(number), NULL, 0);
	// regist[0][0] = index;
	// regist[0][1] = index + 1;
	// reg_result[0][0] = tab[(e->process[xproc]->addr_pc + (nb % IDX_MOD)) % ((MEM_SIZE) * 2)];
	// reg_result[0][1] = tab[(e->process[xproc]->addr_pc + (nb % IDX_MOD)) + 1 % ((MEM_SIZE) * 2)];
	// reg_result[0][2] = tab[(e->process[xproc]->addr_pc + (nb % IDX_MOD)) + 2 % ((MEM_SIZE) * 2)];
	// reg_result[0][3] = tab[(e->process[xproc]->addr_pc + (nb % IDX_MOD)) + 3 % ((MEM_SIZE) * 2)];
	// e->process[xproc]->reg[regist] = reg_result;
}

void	live_func(t_env *e, int xproc, int func)
{
	int		index;

	index = 0;
	if (func == 1 && !e->process[xproc]->live_status)
	{
		e->process[xproc]->reg[0] = tab2[e->process[xproc]->position
			% ((MEM_SIZE) * 2)];
		index = 2;
		while (index < 9)
		{
			tab[(e->process[xproc]->position + index) % ((MEM_SIZE) * 2)] = 'F';
			tab2[(e->process[xproc]->position + index) % ((MEM_SIZE) * 2)] =
			e->process[xproc]->reg[0];
			index++;
		}
		tab[e->process[xproc]->position + 9 % ((MEM_SIZE) * 2)] = 'G'
			- e->process[xproc]->reg[0];
		e->process[xproc]->live_status = 1;
	}
}

void	add_func(t_env *e, int xproc, int func)
{
	char	r[3][2];

	r[0][0] = (e->process[xproc]->position + 4) % ((MEM_SIZE) * 2);
	r[0][1] = (e->process[xproc]->position + 5) % ((MEM_SIZE) * 2);
	r[1][0] = (e->process[xproc]->position + 6) % ((MEM_SIZE) * 2);
	r[1][1] = (e->process[xproc]->position + 7) % ((MEM_SIZE) * 2);
	r[2][0] = (e->process[xproc]->position + 7) % ((MEM_SIZE) * 2);
	r[2][1] = (e->process[xproc]->position + 8) % ((MEM_SIZE) * 2);
	if (func == 3)
		e->process[xproc]->reg[ft_atoi(r[2])] = e->process[xproc]->reg[ft_atoi(r[0])] + e->process[xproc]->reg[ft_atoi(r[1])];
}

void	sub_func(t_env *e, int xproc, int func)
{
	char	r[3][2];

	r[0][0] = (e->process[xproc]->position + 4) % ((MEM_SIZE) * 2);
	r[0][1] = (e->process[xproc]->position + 5) % ((MEM_SIZE) * 2);
	r[1][0] = (e->process[xproc]->position + 6) % ((MEM_SIZE) * 2);
	r[1][1] = (e->process[xproc]->position + 7) % ((MEM_SIZE) * 2);
	r[2][0] = (e->process[xproc]->position + 7) % ((MEM_SIZE) * 2);
	r[2][1] = (e->process[xproc]->position + 8) % ((MEM_SIZE) * 2);
	if (func == 4)
		e->process[xproc]->reg[ft_atoi(r[2])] = e->process[xproc]->reg[ft_atoi(r[0])] - e->process[xproc]->reg[ft_atoi(r[1])];
}
