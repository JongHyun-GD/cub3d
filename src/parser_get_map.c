/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_get_map.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dason <dason@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 22:18:10 by dason             #+#    #+#             */
/*   Updated: 2022/01/11 22:18:35 by dason            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

// TODO: 좀 더 단순화 시킬 수 있는 방법 찾아보기.
static void	check_closed_map(t_info *info, int x, int y)
{
	char	**map;
	int		start_x;
	int		end_x;
	int		start_y;
	int		end_y;

	map = info->map_info.map;
	start_y = y - 1;
	end_y = y + 1;
	while (start_y <= end_y)
	{
		start_x = x - 1;
		end_x = x + 1;
		while (start_x <= end_x)
		{
			if (start_x < 0 || start_y < 0 || \
				info->map_info.map_height <= start_y)
				error_exit("The map is not closed.");
			if (map[start_y][start_x] == SPACE || \
				map[start_y][start_x] == '\0')
				error_exit("The map is not closed.");
			start_x++;
		}
		start_y++;
	}
}

static void	get_player_info(t_info *info, char map_tile, int x, int y)
{
	info->player_info.exist_player = true;
	info->player_info.p_pos.x = x;
	info->player_info.p_pos.y = y;
	info->map_info.map[y][x] = PLAYER;
	if (map_tile == 'N')
	{
		info->player_info.p_direction.x = 0;
		info->player_info.p_direction.y = -1;
	}
	else if (map_tile == 'S')
	{
		info->player_info.p_direction.x = 0;
		info->player_info.p_direction.y = 1;
	}
	else if (map_tile == 'W')
	{
		info->player_info.p_direction.x = -1;
		info->player_info.p_direction.y = 0;
	}
	else if (map_tile == 'E')
	{
		info->player_info.p_direction.x = 1;
		info->player_info.p_direction.y = 0;
	}
}

static void	organize_map(t_info *info)
{
	char	**map;
	char	map_tile;
	int		x;
	int		y;

	map = info->map_info.map;
	y = -1;
	while (map[++y])
	{
		x = -1;
		while (map[y][++x])
		{
			map_tile = map[y][x];
			if (map_tile == FLOOR)
				check_closed_map(info, x, y);
			if (map_tile == 'N' || map_tile == 'S' || \
				map_tile == 'W' || map_tile == 'E')
				get_player_info(info, map_tile, x, y);
		}
	}
}

static void	check_map(t_info *info)
{
	if (info->player_info.exist_player == false)
		error_exit("There's no player.");
	if (info->map_info.map == NULL)
		error_exit("There's no map.");
}

void	get_map(t_info *info, char **tmp_file_data)
{
	char	**map;
	char	*line;
	int		m_i;
	int		i;

	m_i = 0;
	map = (char **)ft_calloc(info->map_info.map_height + 1, sizeof(char *));
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
	organize_map(info);
	check_map(info);
}
