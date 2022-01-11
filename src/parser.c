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

// TEST_FUNCTION
void print_info(t_info *info)
{
	printf("### print_info ###\n");
	printf("no_texture_path: %p\n", info->map_info.no_texture_path);
	printf("so_texture_path: %p\n", info->map_info.so_texture_path);
	printf("we_texture_path: %p\n", info->map_info.we_texture_path);
	printf("ea_texture_path: %p\n", info->map_info.ea_texture_path);
	printf("floor_color: %d\n", info->map_info.floor_color);
	printf("ceiling_color: %d\n", info->map_info.ceiling_color);
	printf("map_width: %d\n", info->map_info.map_width);
	printf("map_height: %d\n", info->map_info.map_height);
	printf("map: \n");
	if (info->map_info.map)
		for (int i = 0; info->map_info.map[i]; i++)
			printf("%s\n", info->map_info.map[i]);
	printf("\n");
}

static void check_param(int argc, char *filepath)
{
	char	*extension;

	if (argc != 2)
		error_exit("Invalid parameters.");
	extension = ft_strrchr(filepath, '.');
	if (ft_strncmp(".cub", extension, 5) != 0)
		error_exit("It's an incorrrect extension.");
}

void parser(int argc, char **argv, t_info *info)
{
	char	**tmp_file_data;

	check_param(argc, argv[1]);
	ft_memset(&info->map_info, 0, sizeof(t_map));
	tmp_file_data = store_file_data(argv[1]);
	get_file_data(info, tmp_file_data);
	get_map(info, tmp_file_data);
	print_info(info);
	free_double_pointer(&tmp_file_data);
}
