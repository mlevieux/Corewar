/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_string.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlancien <vlancien@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/28 16:44:19 by vlancien          #+#    #+#             */
/*   Updated: 2016/10/21 18:44:16 by vlancien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			data_next(t_info_str *list)
{
	// ft_memdel((void*)list->data);
	// if (!list->data)
		// list->data = ft_memalloc(sizeof(t_result));

	(void)list;
	return (0);
}

int			ft_print_string(char *str, t_info_str *list)
{
	intmax_t			index;

	index = list->size;
	if (list->size)
		index = data_next(list);
	while (*str != '\0' && *str != '%')
	{
		list->data->result[index] = *str;
		index++;
		str++;
		if (*str == '\0')
			break;
		list->size = index;
		if (index == BUFFER)
		{
			write(1, list->data->result, index);
			list->size = data_next(list);
		}
		if (*str == '\0' || *str == '%')
			write(1, list->data->result, index);
	}
	return (1);
}
