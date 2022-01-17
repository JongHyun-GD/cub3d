/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dason <dason@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 13:57:35 by dason             #+#    #+#             */
/*   Updated: 2022/01/13 13:57:58 by dason            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef KEY_HOOK_H
# define KEY_HOOK_H

# include <math.h>
# include "info.h"
# include "render.h"
# include <stdio.h>

#define KEY_W 13
#define KEY_A 0
#define KEY_S 1
#define KEY_D 2
#define KEY_ESC 53

int	key_hook(int keycode, t_info *info);

#endif
