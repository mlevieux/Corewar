/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   method.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaustry <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 23:53:21 by jaustry           #+#    #+#             */
/*   Updated: 2016/11/04 23:53:22 by jaustry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int		coerence_str_optab(char *str, t_env *e) // verifie si la str
{
	if ((str[0]) == 'r')
		return (1);
	else if ((str[0]) == '%')
		return (10);
	else
		return (11);
}

int			calculate_encod(char **tab, int nb_arg, t_env *e)
{
	int			encod;
	int			a;
	int			multiplicateur;
	int			binary_code;

	a = 1;
	multiplicateur = 128;
	if ((e->nb_tab) == 0 || (e->nb_tab) == 8 || (e->nb_tab) == 11 ||
		(e->nb_tab) == 16 || (e->nb_tab) == 17)
		return (0);
	while (a <= nb_arg)
	{
		binary_code = coerence_str_optab(tab[a], e);
		encod = encod + (binary_code / 10 * multiplicateur) + (binary_code % 10 * multiplicateur / 2);
		multiplicateur /= 4;
		a++;
	}
	return (encod);
}

t_line		*create_method(char **tab, int nb_arg, t_env *e)
{
	t_line		*list;

	list = NULL;
	list = (t_line *)malloc(sizeof(t_line));
	list->info1 = NULL;
	list->info2 = NULL;
	list->info3 = NULL;
	if (list)
	{
		list->method = tab[0];
		list->method_position = 0;
		if (nb_arg >= 1)
			list->info1 = tab[1];
		if (nb_arg >= 2)
			list->info2 = tab[2];
		if (nb_arg >= 3)
			list->info3 = tab[3];
		list->nb_info = nb_arg;
		list->opcode = e->op_tab[e->nb_tab].opcode;
		list->nb_tab = e->nb_tab;
		list->encod = calculate_encod(tab, nb_arg, e);
		list->next = NULL;
	}
	return (list);
}

void		push_tail_method(t_line **begin_list, char **tab, int nb_arg, t_env *e)
{
	t_line		*list;

	list = *begin_list;
	if (list)
	{
		while (list->next != NULL)
			list = list->next;
		list->next = create_method(tab, nb_arg, e);
	}
	else
	{
		*begin_list = create_method(tab, nb_arg, e);
	}
}

