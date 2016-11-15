/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   decimal_to_hexa.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlancien <vlancien@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 22:11:14 by vlancien          #+#    #+#             */
/*   Updated: 2016/11/14 22:11:28 by vlancien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

unsigned long	hex_to_dec(char *data, unsigned int size)
{
    int				index;
    unsigned long	value;

	index = 0;
	value = 0;
	while (index < (int)size)
	{
		if (data[index] <= 57)
			value += (data[index] - 48) * (1 << (4 * (size - 1 - index)));
		else
			value += (data[index] - 55) * (1 << (4 * (size - 1 - index)));
		index++;
	}
    return (value);
}
