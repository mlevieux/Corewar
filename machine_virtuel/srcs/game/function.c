/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   function.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlancien <vlancien@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 17:37:17 by vlancien          #+#    #+#             */
/*   Updated: 2016/11/15 13:31:22 by vlancien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "n_curse.h"
void	ld_func(t_env *e, int xproc, int func);

void	(*g_func_process[5])(t_env*, int, int) = {live_func, live_func, ld_func, add_func, sub_func};

void	apply_func(t_env *e, int xproc, int func)
{
	if (func == 1 || func == 3 || func == 4)
		g_func_process[func - 1](e, xproc, func);
}

char	*get_op_str(char c, char c1)
{
	char	*str;

	str = malloc(sizeof(char) * 3);
	str[0] = c;
	str[1] = c1;
	str[2] = '\0';
	printf("{{%s}}\n", str);
	return (str);
}

int check_jump(t_env *e, char *op_size)
{
	int		index = 0;
	int		t_dir = 0;
	int		t_ind = 0;
	int		t_reg = 0;

	(void)e;
	printf("OPsize %s\n", op_size);
	if (ft_strlen(op_size) != 8)
		return (-1);
	while (op_size[index] != '\0')
	{
		if (op_size[index] == '0' && op_size[index + 1] == '1')
			t_reg++;
		else if (op_size[index] == '1' && op_size[index + 1] == '0')
			t_dir++;
		else if (op_size[index] == '1' && op_size[index + 1] == '1')
			t_ind++;
		index += 2;
	}
	printf("t_dir = %d\nt_reg = %d\nt_ind = %d\n", t_dir, t_reg, t_ind);
	return (0);
}

void	ld_func(t_env *e, int xproc, int func)
{
	char	*op_size;
	int		index;

	(void)func;
	index = 4;
	op_size = hex_to_bin_quad(get_op_str(tab[(e->process[xproc]->position + 2) % ((MEM_SIZE) * 2)], tab[(e->process[xproc]->position + 3) % ((MEM_SIZE) * 2)]));
	check_jump(e, op_size);
	
	nodelay(stdscr, 0);
	getch();

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
