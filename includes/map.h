/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dason <dason@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/27 17:58:30 by dason             #+#    #+#             */
/*   Updated: 2022/01/05 14:37:46 by dason            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_H
# define MAP_H

# define FLOOR '0'
# define WALL '1'
# define SPACE ' '
# define PLAYER '3'

typedef struct s_map
{
	int		texture_width;
	int		texture_height;
	void	*no_texture;
	void	*so_texture;
	void	*we_texture;
	void	*ea_texture;
	int		floor_color;
	int		ceiling_color;
	int		map_width;
	int		map_height;
	char	**map;
}	t_map;

#endif
