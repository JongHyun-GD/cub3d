/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dason <dason@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/28 12:24:58 by dason             #+#    #+#             */
/*   Updated: 2021/12/28 12:25:00 by dason            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	free_double_pointer(char ***s)
{
	int		i;

	i = -1;
	while ((*s)[++i])
	{
		free((*s)[i]);
		(*s)[i] = NULL;
	}
	free(*s);
	*s = NULL;
}

/* TODO: free_info 함수 이름 변경
	info->map_info안의 포인터를 free해주는 함수
	그 외의 다른 포인터도 free할 예정 */
void	free_info(t_info *info)
{
	free(info->map_info.no_texture_path);
	free(info->map_info.so_texture_path);
	free(info->map_info.we_texture_path);
	free(info->map_info.ea_texture_path);
	free(info->map_info.s_texture_path);
	free(info->map_info.floor_color);
	free(info->map_info.ceiling_color);
}
