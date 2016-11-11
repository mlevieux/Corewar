/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   g_variable.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlancien <vlancien@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/11 02:33:06 by vlancien          #+#    #+#             */
/*   Updated: 2016/11/11 02:33:26 by vlancien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef G_VARIABLE_H
# define G_VARIABLE_H

char	g_status_code[17][8] = {
	"None", "live", "ld", "st", "add", "sub", "and", "or", "xor", "zjump",
	"aff", "ldi", "sti", "fork", "lld", "lldi", "lfork"
};

#endif
