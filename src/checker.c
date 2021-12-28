/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dason <dason@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/27 20:03:30 by dason             #+#    #+#             */
/*   Updated: 2021/12/28 12:24:31 by dason            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

static void	check_param(int argc, char **argv)
{
	if (argc != 2 && argc != 3)
		error_exit("Invalid parameters.");
	if (argc == 3)
	{
		if (ft_strncmp("--save", argv[2], 7) != 0)
			error_exit("Invalid parameters.");
	}
}

static bool	is_type_identifier(char *line)
{
	if (line == NULL)
		return (true);
	if (ft_strncmp("R", line, 2) == 0)
		return (true);
	if (ft_strncmp("NO", line, 3) == 0)
		return (true);
	if (ft_strncmp("SO", line, 3) == 0)
		return (true);
	if (ft_strncmp("WE", line, 3) == 0)
		return (true);
	if (ft_strncmp("EA", line, 3) == 0)
		return (true);
	if (ft_strncmp("S", line, 2) == 0)
		return (true);
	if (ft_strncmp("F", line, 2) == 0)
		return (true);
	if (ft_strncmp("C", line, 2) == 0)
		return (true);
	if (ft_strncmp("1", line, 1) == 0)
		return (true);
	if (ft_strncmp("	", line, ft_strlen("	")) == 0)
		return (true);
	if (ft_strncmp(" ", line, 1) == 0)
		return (true);
	return (false);
}

/* TODO: 고려해야할 list
	- map이 닫혀있는가?
	- type_data보다 나은 단어가 있는지?
	- width와 height가 너무 큰지 체크해야하는가?
	- texture_path가 올바른가?
	- 유형 식별자 F와 C의 데이터가 올바르게 들어가 있는가?
	- 유형 식별자 F와 C의 데이터가 ','또는 ', '로 구분 되어있을 경우 */
static void	get_type_data(t_info *info, char **split_line)
{
	if (ft_strncmp("R", split_line[0], 2) == 0)
	{
		info->map_info.map_width = ft_atoi(split_line[1]);
		info->map_info.map_width = ft_atoi(split_line[2]);
	}
	if (ft_strncmp("NO", split_line[0], 3) == 0)
		info->map_info.no_texture_path = ft_strdup(split_line[1]);
	if (ft_strncmp("SO", split_line[0], 3) == 0)
		info->map_info.so_texture_path = ft_strdup(split_line[1]);
	if (ft_strncmp("WE", split_line[0], 3) == 0)
		info->map_info.we_texture_path = ft_strdup(split_line[1]);
	if (ft_strncmp("EA", split_line[0], 3) == 0)
		info->map_info.ea_texture_path = ft_strdup(split_line[1]);
	if (ft_strncmp("S", split_line[0], 2) == 0)
		info->map_info.s_texture_path = ft_strdup(split_line[1]);
	if (ft_strncmp("F", split_line[0], 2) == 0)
		info->map_info.floor_color = ft_strdup(split_line[1]);
	if (ft_strncmp("C", split_line[0], 2) == 0)
		info->map_info.ceiling_color = ft_strdup(split_line[1]);
}

/* split_line을 했을 때, 아래 내용도 체크해야함
	R의 인덱스 3개
	NO, SO, WE, EA, S의 인덱스 2개
	F, C의 인덱스 2~3개 */
static void	check_map(t_info *info, int fd)
{
	char	*line;
	char	**split_line;

	while (get_next_line(fd, &line) > 0)
	{
		split_line = ft_split(line, ' ');
		if (is_type_identifier(split_line[0]) == false)
			error_exit("Invalid type identifier.");
		if (split_line[0] != NULL)
			get_type_data(info, split_line);
		free(line);
		free_double_pointer(&split_line);
	}
	free(line);
}

/* TODO: check_map(int fd)의 이름 변경, 위치 변경
	- map을 체크하고 그 데이터를 info 넣는 기능임.
	만약 check_param과 check_map을 분리 시킨다고 하면
	check_param만 파일에 있기에 너무 양이 적음 */
void	checker(int argc, char **argv, t_info *info)
{
	int		fd;

	check_param(argc, argv);
	fd = open((char *)argv[1], O_RDONLY);
	if (fd == -1)
		error_exit("The file does not exist.");
	check_map(info, fd);
}
