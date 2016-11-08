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

t_line		*create_method(char **tab, int nb_arg)
{
	t_line		*list;

	list = NULL;
	list = (t_line *)malloc(sizeof(t_line));
	list->info2 = NULL;
	list->info2 = NULL;
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
		list->next = NULL;
	}
	return (list);
}

void		push_tail_method(t_line **begin_list, char **tab, int nb_arg)
{
	t_line		*list;

	list = *begin_list;
	if (list)
	{
		while (list->next != NULL)
			list = list->next;
		list->next = create_method(tab, nb_arg);
	}
	else
	{
		*begin_list = create_method(tab, nb_arg);
	}
}

