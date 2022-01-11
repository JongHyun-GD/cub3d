/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   info.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dason <dason@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/27 17:19:11 by dason             #+#    #+#             */
/*   Updated: 2021/12/27 19:54:29 by dason            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INFO_H
# define INFO_H

# include "map.h"
# include "mlx_info.h"
# include "vec2.h"
# include <stdbool.h>

typedef struct s_info
{
	t_mlx_info	mlx_info;
	t_map		map_info;
	t_vec		p_pos;
}	t_info;

#endif
