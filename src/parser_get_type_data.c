/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_get_type_data.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dason <dason@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/27 20:03:30 by dason             #+#    #+#             */
/*   Updated: 2022/01/05 17:58:12 by dason            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

static int	compress_int_to_rgb(int rgb, int color)
{
	rgb = rgb << 8;
	rgb = rgb + color;
	return (rgb);
}

static void	get_type_data_fc(t_info *info, char **map_type)
{
	char	*type_id;
	char	**split_data;
	int		rgb;
	int		i;
	int		j;

	rgb = 0;
	type_id = map_type[0];
	i = 0;
	while (map_type[++i])
	{
		split_data = ft_split(map_type[i], ',');
		j = -1;
		while (split_data[++j])
			rgb = compress_int_to_rgb(rgb, ft_atoi(split_data[j]));
		free_double_pointer(&split_data);
	}
	if (ft_strncmp("F", type_id, 2) == 0)
		info->map_info.floor_color = rgb;
	if (ft_strncmp("C", type_id, 2) == 0)
		info->map_info.ceiling_color = rgb;
}

/* TODO: texture 변경 
	- void *texture
	- texture = mlx_xpm_file_to_image();*/
static void	get_type_data_texture(t_info *info, char **map_type, int type_id)
{
	char	*texture;

	texture = ft_strdup(map_type[1]);
	// texture = mlx_xpm_file_to_image(info->mlx_info.mlx, map_type[1], &info->map_info.texture_width, &info->map_info.texture_height);
	if (type_id == TYPE_NO)
		info->map_info.no_texture_path = texture;
	if (type_id == TYPE_SO)
		info->map_info.so_texture_path = texture;
	if (type_id == TYPE_WE)
		info->map_info.we_texture_path = texture;
	if (type_id == TYPE_EA)
		info->map_info.ea_texture_path = texture;
	if (type_id == TYPE_S)
		info->map_info.s_texture_path = texture;
}

void	get_type_data(t_info *info, char **map_type, int type_id)
{
	if (type_id == TYPE_R)
	{
		info->map_info.map_width = ft_atoi(map_type[1]);
		info->map_info.map_height = ft_atoi(map_type[2]);
	}
	if (type_id == TYPE_NO || type_id == TYPE_SO || \
		type_id == TYPE_WE || type_id == TYPE_EA || \
		type_id == TYPE_S)
		get_type_data_texture(info, map_type, type_id);
	if (type_id == TYPE_F || type_id == TYPE_C)
		get_type_data_fc(info, map_type);
}
