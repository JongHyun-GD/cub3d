/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyun <hyun@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/27 19:39:45 by hyun              #+#    #+#             */
/*   Updated: 2022/01/04 22:01:50 by hyun             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycast.h"

int worldMap[24][24]=
{
  {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,2,2,2,2,2,0,0,0,0,3,0,3,0,3,0,0,0,1},
  {1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,3,0,0,0,3,0,0,0,1},
  {1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,2,2,0,2,2,0,0,0,0,3,0,3,0,3,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,4,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,0,4,0,0,0,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,0,0,0,0,5,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,0,4,0,0,0,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,0,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,4,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}
};

double	get_perp_wall_dist(int side, t_vec2int map_pos, t_vec2 pos, t_vec2int step, t_vec2 dir)
{
	double	perp_wall_dist;

	if (side == 0)
		perp_wall_dist = (map_pos.x - pos.x + (1 - step.x) / 2) / dir.x;
	else
		perp_wall_dist = (map_pos.y - pos.y + (1 - step.y) / 2) / dir.y;
	return (perp_wall_dist);
}

int	*make_line(double dist, int side, t_vec2int map_pos)
{
	int	line_height;
	int	draw_start;
	int	draw_end;
	int	y;
	int color;
	int	*line;

	line = (int *)malloc(WIN_HEIGHT * sizeof(int));
	line_height = (int)(WIN_HEIGHT / dist);
	draw_start = -line_height / 2 + WIN_HEIGHT / 2;
	if (draw_start < 0) draw_start = 0;
	draw_end = line_height / 2 + WIN_HEIGHT / 2;
	y = -1;
	while (++y < WIN_HEIGHT)
	{
		switch (worldMap[map_pos.x][map_pos.y])
		{
		case 1: color = RGB_WHITE; break;
		case 2: color = RGB_BLUE; break;
		case 3: color = RGB_GREEN; break;
		case 4: color = RGB_RED; break;
		default: color = RGB_BLACK; break;
		}
		side = 0;
		if (side == 1)
		{
			color /= 2;
			printf("side!\n");
		}
		if (y >= draw_start && y <= draw_end)
			line[y] = color;
		else
			line[y] = RGB_BLACK;
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
		if (worldMap[map_pos.x][map_pos.y] > 0)
			hit = 1;
	}

	// Get dist and draw
	dist = get_perp_wall_dist(side, map_pos, info->p_pos, step, dir);
	return (make_line(dist, side, map_pos));
}

