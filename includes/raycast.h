/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyun <hyun@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/27 19:43:04 by hyun              #+#    #+#             */
/*   Updated: 2022/01/19 21:32:12 by hyun             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAYCAST_H
# define RAYCAST_H

# include <stdlib.h>
# include <stdio.h>

# include "info.h"
# include "math.h"
# include "img.h"

# define RGB_RED 0x00FF0000
# define RGB_GREEN 0x0000FF00
# define RGB_BLUE 0x000000FF
# define RGB_WHITE 0x00FFFFFF
# define RGB_BLACK 0x00000000

# define TEX_WIDTH 64
# define TEX_HEIGHT 64

int	*raycast(t_info *info, t_vec2 dir);

#endif
