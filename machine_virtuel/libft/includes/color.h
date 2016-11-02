/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlancien <vlancien@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/01 20:02:38 by vlancien          #+#    #+#             */
/*   Updated: 2016/11/02 14:05:22 by vlancien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COLOR_H
# define COLOR_H

# define CLEAR     "\33[H\33[2J"
# define GREY_BACK "\x1b[6;37;47m"
# define NORM_BACK "\x1b[0m"

# define PURPLE_SELECT "\x1b[6;35;47m"
# define YELLOW_SELECT "\x1b[6;33;47m"
# define RED_SELECT    "\x1b[6;32;47m"
# define GREEN_SELECT  "\x1b[6;31;47m"

# define PURPLE    "\033[0;35m"
# define YELLOW    "\033[0;33m"
# define GREEN     "\033[0;32m"
# define RED       "\033[0;31m"
# define BLACK     "\033[0;30m"
# define BLUE      "\033[0;34m"
# define CYAN      "\033[0;36m"
# define GREY      "\033[0;37m"
# define NORM      "\033[0;m"
# define OK  BLUE "[" GREEN  "ok" BLUE "] " DEFAULT_COLOR

#endif
