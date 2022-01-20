/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   info.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyun <hyun@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/27 17:19:11 by dason             #+#    #+#             */
/*   Updated: 2022/01/19 21:38:01 by hyun             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INFO_H
# define INFO_H

# include "map.h"
# include "mlx_info.h"
# include "player.h"
# include <stdbool.h>

typedef struct s_info
{
	t_mlx_info	mlx_info;
	t_vec2		p_pos;
	t_vec2		p_dir;
	t_vec2		p_fov;
	int			map_width;
	int			map_height;
	t_map		map_info;
}	t_info;

#endif
