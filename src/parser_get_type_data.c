/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_get_type_data.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dason <dason@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/27 20:03:30 by dason             #+#    #+#             */
/*   Updated: 2022/01/03 14:22:52 by dason            ###   ########.fr       */
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
void	get_type_data(t_info *info, char **map_type)
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