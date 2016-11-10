/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlancien <vlancien@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 02:28:03 by vlancien          #+#    #+#             */
/*   Updated: 2016/11/10 02:30:11 by vlancien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		intlen(int nb)
{
	int nbr;

	nbr = 1;
	while (nb >= 10)
	{
		nb = nb / 10;
		nbr++;
	}
	return (nbr);
}

char	*ft_itoa_base(int value, int base)
{
	char	base16[17] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F'};
	char	*result = NULL;
	int		converted[64];
	int		sign = value < 0 ? 1 : 0;
	int		index = 0;
	int		size = 0;
	int		x = 0;

	if (base < 2 || base > 16)
		return (NULL);
	if (value > 2147483647 && base == 10)
		return (ft_strdup("2147483648"));
	if (value < -2147483647 && base == 10)
		return (ft_strdup("-2147483648"));
	size = intlen(value);
	if (!(result = malloc(sizeof(char) * size + sign + 1)))
		return (NULL);
	if (value < 0)
		value = -value;
	while (value)
	{
		converted[index] = value % base;
		value = value / base;
		index++;
	}
	index--;
	if (sign && base == 10)
	{
		result[x] = '-';
		x++;
	}
	while (index != -1)
	{
		result[x] = base16[converted[index]];
		x++;
		index--;
	}
	return (result);
}
