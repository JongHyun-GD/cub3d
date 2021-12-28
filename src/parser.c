/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dason <dason@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/27 17:18:52 by dason             #+#    #+#             */
/*   Updated: 2021/12/28 21:46:51 by dason            ###   ########.fr       */
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
	check_cub_get_type_data(info, fd);
	print_info(info);
}