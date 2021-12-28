/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dason <dason@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/27 17:18:52 by dason             #+#    #+#             */
/*   Updated: 2021/12/28 12:17:46 by dason            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

// TEST_FUNCTION
void	print_info(t_info *info)
{
	printf("### print_info ###\n");
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
	ft_memset(info, 0, sizeof(t_info));
	printf("# Before\n");
	print_info(info);
	checker(argc, argv, info);
	if (argc == 3)
		info->is_save = true;
	printf("# After\n");
	print_info(info);
}
