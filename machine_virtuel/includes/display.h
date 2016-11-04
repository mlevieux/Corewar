/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlancien <vlancien@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 15:33:29 by vlancien          #+#    #+#             */
/*   Updated: 2016/11/04 15:41:28 by vlancien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DISPLAY_H
# define DISPLAY_H

# include <ncurses.h>

typedef struct s_window	t_window;
struct					s_window
{
	WINDOW				*tab;
	WINDOW				*menu;
	WINDOW				*memory;
};

#endif
