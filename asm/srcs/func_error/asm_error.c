/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_error.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlancien <vlancien@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/20 17:09:56 by vlancien          #+#    #+#             */
/*   Updated: 2016/10/20 17:15:31 by vlancien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void		asm_error(char *str)
{
	ft_printf("%s\n", str);
	exit(-1);
}

void		asm_error_str(char *str)
{
	ft_printf("%s\n", str);
	exit(-1);
}