/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   info.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dason <dason@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/27 17:19:11 by dason             #+#    #+#             */
/*   Updated: 2021/12/27 17:36:56 by dason            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INFO_H
# define INFO_H

# include "mlx_info.h"
# include "vec2.h"
# include <stdbool.h>

typedef struct s_info
{
	t_mlx_info	mlx_info;
	t_vec		p_pos;
	bool		is_save;
	int			map_width;
	int			map_height;
}	t_info;

#endif
