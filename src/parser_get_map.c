/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_get_map.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyun <hyun@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 22:18:10 by dason             #+#    #+#             */
/*   Updated: 2022/01/20 21:49:13 by hyun             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

// TODO: 좀 더 단순화 시킬 수 있는 방법 찾아보기.
static void	check_closed_map(char **map, int x, int y)
{
	int		start_x;
	int		end_x;
	int		start_y;
	int		end_y;

	start_y = y - 1;
	end_y = y + 1;
	while (start_y <= end_y)
	{
		start_x = x - 1;
		end_x = x + 1;
		while (start_x <= end_x)
		{
			if (start_x < 0 || start_y < 0)
				error_exit("The map is not closed.");
			if (map[start_y][start_x] == SPACE || \
				map[start_y][start_x] == '\0')
				error_exit("The map is not closed.");
			start_x++;
		}
		start_y++;
	}
}

static void	set_player_info(t_info *info, char map_tile, int x, int y)
{
	info->p_fov.x = 0.66;
	info->p_fov.y = 0;
	info->p_pos.x = x;
	info->p_pos.y = y;
	info->map_info.map[y][x] = PLAYER;
	if (map_tile == 'N')
	{
		info->p_dir.x = 0;
		info->p_dir.y = -1;
		info->p_right.x = 1;
		info->p_right.y = 0;
	}
	else if (map_tile == 'S')
	{
		info->p_dir.x = 0;
		info->p_dir.y = 1;
		info->p_right.x = -1;
		info->p_right.y = 0;
	}
	else if (map_tile == 'W')
	{
		info->p_dir.x = -1;
		info->p_dir.y = 0;
		info->p_right.x = 0;
		info->p_right.y = -1;
	}
	else if (map_tile == 'E')
	{
		info->p_dir.x = 1;
		info->p_dir.y = 0;
		info->p_right.x = 0;
		info->p_right.y = 1;
	}
}

static bool	organize_map(t_info *info)
{
	char	**map;
	char	map_tile;
	int		x;
	int		y;
	bool	has_player;

	map = info->map_info.map;
	has_player = false;
	y = -1;
	while (map[++y])
	{
		x = -1;
		while (map[y][++x])
		{
			map_tile = map[y][x];
			if (map_tile == FLOOR)
				check_closed_map(map, x, y);
			if (map_tile == 'N' || map_tile == 'S' || \
				map_tile == 'W' || map_tile == 'E')
			{
				set_player_info(info, map_tile, x, y);
				has_player = true;
			}
		}
	}
	return (has_player);
}

void	get_map(t_info *info, char **tmp_file_data)
{
	char	**map;
	char	*line;
	int		m_i;
	int		i;

	m_i = 0;
	map = (char **)ft_calloc(info->map_info.map_height + 1, sizeof(char *));
	print_info(info);
	if (!map)
		error_exit("Malloc allocation failed.");
	i = -1;
	while (tmp_file_data[++i])
	{
		if (i == 5)
			break ;
	}
	while (tmp_file_data[++i])
	{
		line = tmp_file_data[i];
		map[m_i++] = ft_strdup(line);
	}
	info->map_info.map = map;
	if (organize_map(info) == false) {
		error_exit("[Error] Invalid map\n");
	}
}
