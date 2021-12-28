/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_check_cub_get_type_data.c                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dason <dason@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/27 20:03:30 by dason             #+#    #+#             */
/*   Updated: 2021/12/28 21:53:55 by dason            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

/* TODO: F와 C를 int형에 담는 함수 만들기
	- 유형 식별자 F와 C의 값을 비트 연산자를 이용해 int형으로 */
static void	get_type_data_fc(t_info *info, char **map_type)
{
	char	*type_id;

	type_id = map_type[0];
	if (ft_strncmp("F", type_id, 2) == 0)
		info->map_info.floor_color = ft_strdup(map_type[1]);
	if (ft_strncmp("C", type_id, 2) == 0)
		info->map_info.ceiling_color = ft_strdup(map_type[1]);
}

/* TODO: 함수 이름 변경
	- type_data보다 나은 단어가 있는지? */
static void	get_type_data(t_info *info, char **map_type)
{
	char	*type_id;

	type_id = map_type[0];
	if (ft_strncmp("R", type_id, 2) == 0)
	{
		info->map_info.map_width = ft_atoi(map_type[1]);
		info->map_info.map_width = ft_atoi(map_type[2]);
	}
	if (ft_strncmp("NO", type_id, 3) == 0)
		info->map_info.no_texture_path = ft_strdup(map_type[1]);
	if (ft_strncmp("SO", type_id, 3) == 0)
		info->map_info.so_texture_path = ft_strdup(map_type[1]);
	if (ft_strncmp("WE", type_id, 3) == 0)
		info->map_info.we_texture_path = ft_strdup(map_type[1]);
	if (ft_strncmp("EA", type_id, 3) == 0)
		info->map_info.ea_texture_path = ft_strdup(map_type[1]);
	if (ft_strncmp("S", type_id, 2) == 0)
		info->map_info.s_texture_path = ft_strdup(map_type[1]);
	if (ft_strncmp("F", type_id, 2) == 0 || \
		ft_strncmp("C", type_id, 2) == 0)
		get_type_data_fc(info, map_type);
}

// TODO: BFS, DFS 공부하기
/* TODO: check_map(int fd)의 이름 변경, 위치 변경
	- map을 체크하고 그 데이터를 info 넣는 기능임. */
/* TODO: checker 이름 변경
	- 동사라서 class 이름 같다 */
/* TODO: 유형 식별자가 끝인지 체크하는 함수 만들기
	- R, NO, ... F, C의 값이 전부 있으면 그 다음부터는 map */
void	check_cub_get_type_data(t_info *info, int fd)
{
	char	*line;
	char	**map_type;

	while (get_next_line(fd, &line) > 0)
	{
		map_type = ft_split(line, ' ');
		if (is_type_id(map_type[0]) == false)
			error_exit("Invalid type identifier.");
		if (map_type[0] != NULL)
		{
			check_num_of_type_data(map_type);
			get_type_data(info, map_type);
		}
		free(line);
		free_double_pointer(&map_type);
	}
	free(line);
}
