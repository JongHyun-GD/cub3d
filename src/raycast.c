/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyun <hyun@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/27 19:39:45 by hyun              #+#    #+#             */
/*   Updated: 2022/01/20 18:31:26 by hyun             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycast.h"

double	get_perp_wall_dist(int side, t_vec2int map_pos, t_vec2 pos, t_vec2int step, t_vec2 dir)
{
	double	perp_wall_dist;

	if (side == 0)
		perp_wall_dist = (map_pos.x - pos.x + (1 - step.x) / 2) / dir.x;
	else
		perp_wall_dist = (map_pos.y - pos.y + (1 - step.y) / 2) / dir.y;
	return (perp_wall_dist);
}

int	*make_line(t_info *info, double dist, int side, t_vec2 dir)
{
	int	line_height;
	int	draw_start;
	int	draw_end;
	int	y;
	int color;
	int	*line;
	double step;
	double tex_pos;
	t_vec2 wall;
	t_vec2int tex;

	line = (int *)malloc(WIN_HEIGHT * sizeof(int));
	line_height = (int)(WIN_HEIGHT / dist);
	draw_start = -line_height / 2 + WIN_HEIGHT / 2;
	if (draw_start < 0) draw_start = 0;
	draw_end = line_height / 2 + WIN_HEIGHT / 2;
	if (side == 0)
		wall.x = info->p_pos.y + dist * dir.y;
	else
		wall.x = info->p_pos.x + dist * dir.x;
	wall.x -= floor(wall.x);
	tex.x = (int)(wall.x * TEX_WIDTH);
	if (side == 0 && dir.x > 0) tex.x = TEX_WIDTH - tex.x - 1;
	if (side == 1 && dir.y < 0) tex.x = TEX_WIDTH - tex.x - 1;

	step = 1.0 * TEX_HEIGHT / (double)line_height;
	tex_pos = (draw_start - WIN_HEIGHT / 2 + line_height / 2) * step;

	y = -1;
	while (++y < WIN_HEIGHT)
	{
		if (y < draw_start) line[y] = RGB_BLACK;
		else if (y > draw_end) line[y] = RGB_BLACK;
		else
		{
			tex.y = (int)tex_pos & (TEX_HEIGHT - 1);
			tex_pos += step;
			if (side == 1 && dir.y <= 0) {
				color = info->map_info.ea_texture[tex.y * TEX_WIDTH + tex.x];
			}
			else if (side == 1 && dir.y > 0) {
				color = info->map_info.we_texture[tex.y * TEX_WIDTH + tex.x];
			}
			else if (side == 0 && dir.x >= 0) {
				color = info->map_info.no_texture[tex.y * TEX_WIDTH + tex.x];
			}
			else if (side == 0 && dir.x < 0) {
				color = info->map_info.so_texture[tex.y * TEX_WIDTH + tex.x];
			}
			line[y] = color;
		}
	}
	return (line);
}

int	*raycast(t_info *info, t_vec2 dir)
{
	t_vec2int	map_pos;
	t_vec2int	step;
	t_vec2		side_dist;
	t_vec2		delta_dist;
	int			hit;
	int			side;
	double		dist;

	map_pos.x = (int)info->p_pos.x;
	map_pos.y = (int)info->p_pos.y;
	delta_dist.x = fabs(1 / dir.x);
	delta_dist.y = fabs(1 / dir.y);
	if (dir.x < 0)
	{
		step.x = -1;
		side_dist.x = (info->p_pos.x - map_pos.x) * delta_dist.x;
	}
	else
	{
		step.x = 1;
		side_dist.x = (map_pos.x + 1.0 - info->p_pos.x) * delta_dist.x;
	}
	if (dir.y < 0)
	{
		step.y = -1;
		side_dist.y = (info->p_pos.y - map_pos.y) * delta_dist.y;
	}
	else
	{
		step.y = 1;
		side_dist.y = (map_pos.y + 1.0 - info->p_pos.y) * delta_dist.y;
	}
	hit = 0;
	while (hit == 0)
	{
		if (side_dist.x < side_dist.y)
		{
			side_dist.x += delta_dist.x;
			map_pos.x += step.x;
			side = 0;
		}
		else
		{
			side_dist.y += delta_dist.y;
			map_pos.y += step.y;
			side = 1;
		}
		if (info->map_info.map[map_pos.y][map_pos.x] != FLOOR)
			hit = 1;
	}

	// Get dist and draw
	dist = get_perp_wall_dist(side, map_pos, info->p_pos, step, dir);
	return (make_line(info, dist, side, dir));
}

