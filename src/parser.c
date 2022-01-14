/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dason <dason@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/27 17:18:52 by dason             #+#    #+#             */
/*   Updated: 2022/01/05 18:21:25 by dason            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

void	print_info(t_info *info)
{
	int		i;

	printf("### print_info ###\n");
	printf("p_pos.x: %f\n", info->player_info.p_pos.x);
	printf("p_pos.y: %f\n", info->player_info.p_pos.y);
	printf("p_direction.x: %f\n", info->player_info.p_direction.x);
	printf("p_direction.y: %f\n", info->player_info.p_direction.y);
	printf("no_texture: %p\n", info->map_info.no_texture);
	printf("so_texture: %p\n", info->map_info.so_texture);
	printf("we_texture: %p\n", info->map_info.we_texture);
	printf("ea_texture: %p\n", info->map_info.ea_texture);
	printf("floor_color: %d\n", info->map_info.floor_color);
	printf("ceiling_color: %d\n", info->map_info.ceiling_color);
	printf("map_width: %d\n", info->map_info.map_width);
	printf("map_height: %d\n", info->map_info.map_height);
	printf("map: \n");
	if (info->map_info.map)
	{
		i = -1;
		while (info->map_info.map[++i])
			printf("%s\n", info->map_info.map[i]);
	}
}

static void	check_param(int argc, char *filepath)
{
	char	*extension;

	if (argc != 2)
		error_exit("Invalid parameters.");
	extension = ft_strrchr(filepath, '.');
	if (ft_strncmp(".cub", extension, 5) != 0)
		error_exit("It's an incorrrect extension.");
}

void	parse_map(int argc, char **argv, t_info *info)
{
	char	**tmp_file_data;

	ft_memset(&info->map_info, 0, sizeof(t_map));
	ft_memset(&info->player_info, 0, sizeof(t_player));
	check_param(argc, argv[1]);
	tmp_file_data = store_file_data(argv[1]);
	get_file_data(info, tmp_file_data);
	get_map(info, tmp_file_data);
	free_double_pointer(&tmp_file_data);
	print_info(info);
}
