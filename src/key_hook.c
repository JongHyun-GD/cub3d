/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyun <hyun@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 20:31:33 by hyun              #+#    #+#             */
/*   Updated: 2022/01/24 23:59:37 by hyun             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "key_hook.h"

int	move_forward(t_info *info)
{
	printf("Key W pressed\n");
	info->p_pos = v2_plus(info->p_pos, info->p_dir);
	render(info);
	return (0);
}

int	move_backward(t_info *info)
{
	printf("Key S pressed\n");
	info->p_pos = v2_minus(info->p_pos, info->p_dir);
	render(info);
	return (0);
}

int	move_right(t_info *info)
{
	printf("Key D pressed\n");
	info->p_pos = v2_plus(info->p_pos, info->p_right);
	render(info);
	return (0);
}

int	move_left(t_info *info)
{
	printf("Key A pressed\n");
	info->p_pos = v2_minus(info->p_pos, info->p_right);
	render(info);
	return (0);
}

int	key_hook(int keycode, t_info *info)
{
	if (keycode == KEY_ESC)
		exit(0);
	if (keycode == KEY_W)
		return (move_forward(info));
	if (keycode == KEY_S)
		return (move_backward(info));
	if (keycode == KEY_D)
		return (move_right(info));
	if (keycode == KEY_A)
		return (move_left(info));
	if (keycode == KEY_RIGHT)
		return (turn_right(info));
	if (keycode == KEY_LEFT)
		return (turn_left(info));
	return (0);
}
