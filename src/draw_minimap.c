/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_minimap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dason <dason@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 20:31:07 by dason             #+#    #+#             */
/*   Updated: 2022/02/03 17:39:39 by dason            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minimap.h"

void	draw_player_pixel(t_img *img, int x, int y)
{
	for (int hy = y * MINIMAP_CELL_SIZE; hy < (y + 1) * MINIMAP_CELL_SIZE; hy++)
	{
		for (int hx = x * MINIMAP_CELL_SIZE; hx < (x + 1) * MINIMAP_CELL_SIZE; hx++)
		{
			img->data[hy * WIN_WIDTH + hx] = GREEN;
		}
	}
}

void	draw_wall_pixel(t_img *img, int x, int y)
{
	for (int hy = y * MINIMAP_CELL_SIZE; hy < (y + 1) * MINIMAP_CELL_SIZE; hy++)
	{
		for (int hx = x * MINIMAP_CELL_SIZE; hx < (x + 1) * MINIMAP_CELL_SIZE; hx++)
		{
			img->data[hy * WIN_WIDTH + hx] = GREY;
		}
	}
}

void	draw_floor_pixel(t_img *img, int x, int y)
{
	for (int hy = y * MINIMAP_CELL_SIZE; hy < (y + 1) * MINIMAP_CELL_SIZE; hy++)
	{
		for (int hx = x * MINIMAP_CELL_SIZE; hx < (x + 1) * MINIMAP_CELL_SIZE; hx++)
		{
			img->data[hy * WIN_WIDTH + hx] = BLACK;
		}
	}
}

int	draw_minimap(t_info *info, t_img *img)
{
	int		x;
	int		y;
	int		minimap_x;
	int		minimap_y;

	minimap_y = 0;
	y = (int)info->p_pos.y - (MINIMAP_HEIGHT / 2) - 1;
	while (++y <= (int)info->p_pos.y + (MINIMAP_HEIGHT / 2))
	{
		minimap_x = 0;
		x = (int)info->p_pos.x - (MINIMAP_WIDTH / 2) - 1;
		while (++x <= (int)info->p_pos.x + (MINIMAP_WIDTH / 2))
		{
			if (y < 0 || x < 0 || \
			y >= info->map_info.map_height || \
			x >= info->map_info.map_width)
			{
				minimap_x++;
				continue ;
			}
			else if (info->map_info.map[y] == NULL || \
				info->map_info.map[y][x] == '\0')
				break ;
			else if (y == info->p_pos.y && x == info->p_pos.x)
				draw_player_pixel(img, minimap_x, minimap_y);
			else if (info->map_info.map[y][x] == ' ')
			{
				minimap_x++;
				continue;
			}
			else if (info->map_info.map[y][x] == '1')
				draw_wall_pixel(img, minimap_x, minimap_y);
			else
				draw_floor_pixel(img, minimap_x, minimap_y);
			minimap_x++;
		}
		minimap_y++;
	}
	return (0);
}

