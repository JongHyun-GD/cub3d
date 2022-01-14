/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dason <dason@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 13:16:09 by dason             #+#    #+#             */
/*   Updated: 2022/01/13 13:16:10 by dason            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PLAYER_H
# define PLAYER_H

# include "vec2.h"
# include <stdbool.h>

typedef struct s_player
{
	t_vec	p_direction;
	t_vec	p_pos;
	bool	exist_player;
}	t_player;
#endif
