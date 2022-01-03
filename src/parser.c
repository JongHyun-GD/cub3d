/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dason <dason@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/27 17:18:52 by dason             #+#    #+#             */
/*   Updated: 2022/01/03 15:36:54 by dason            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

// TEST_FUNCTION
void	print_info(t_info *info)
{
	printf("### print_info ###\n");
	printf("is_save: %d\n", info->is_save);
	printf("map_height: %d\n", info->map_info.map_height);
	printf("map_width: %d\n", info->map_info.map_width);
	printf("no_texture_path: %s\n", info->map_info.no_texture_path);
	printf("so_texture_path: %s\n", info->map_info.so_texture_path);
	printf("we_texture_path: %s\n", info->map_info.we_texture_path);
	printf("ea_texture_path: %s\n", info->map_info.ea_texture_path);
	printf("s_exture_path: %s\n", info->map_info.s_texture_path);
	printf("floor_color: %s\n", info->map_info.floor_color);
	printf("ceiling_color: %s\n", info->map_info.ceiling_color);
	printf("\n");
}

// TODO: BFS, DFS 공부하기
/* TODO: check_map(int fd)의 이름 변경, 위치 변경
	- map을 체크하고 그 데이터를 info 넣는 기능임. */
/* TODO: checker 이름 변경
	- 동사라서 class 이름 같다 */
/* TODO: 유형 식별자가 끝인지 체크하는 함수 만들기
	- R, NO, ... F, C의 값이 전부 있으면 그 다음부터는 map */
/* TODO: info안에 유형 식별자값이 0인 경우 예외처리
	- get_type_data 후, info안에 값들이 전부 있는지 확인 */
static void	check_type_get_type_data(t_info *info, int fd)
{
	char	*line;
	char	**map_type;
	int		type_id;

	while (get_next_line(fd, &line) > 0)
	{
		map_type = ft_split(line, ' ');
		if (map_type[0] != NULL)
		{
			check_type_id(map_type[0]);
			type_id = get_kind_of_type(map_type[0]);
			check_num_of_type_data(map_type, type_id);
			check_invalid_type_data(map_type, type_id);
			get_type_data(info, map_type, type_id);
		}
		free(line);
		free_double_pointer(&map_type);
	}
	free(line);
}

void	parser(int argc, char **argv, t_info *info)
{
	int		fd;

	ft_memset(info, 0, sizeof(t_info));
	check_param(argc, argv);
	if (argc == 3)
		info->is_save = true;
	fd = open((char *)argv[1], O_RDONLY);
	if (fd == -1)
		error_exit("The file does not exist.");
	check_type_get_type_data(info, fd);
	print_info(info);
}