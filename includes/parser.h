/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dason <dason@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/27 17:18:59 by dason             #+#    #+#             */
/*   Updated: 2022/01/03 15:36:54 by dason            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# include "../libft/includes/libft.h"
# include "get_next_line.h"
# include "info.h"
# include "map.h"
# include "utils.h"
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>

# define TYPE_NONE 0
# define TYPE_R 1
# define TYPE_NO 2
# define TYPE_SO 3
# define TYPE_WE 4
# define TYPE_EA 5
# define TYPE_S 6
# define TYPE_F 7
# define TYPE_C 8
# define TYPE_MAP 9

/*
**	MAIN
*/
void	parser(int argc, char **argv, t_info *info);
void	check_param(int argc, char **argv);
void	check_type_id(char *type_id);
void	check_num_of_type_data(char **map_type, int type_id);
void	check_invalid_type_data(char **map_type, int type_id);
void	get_type_data(t_info *info, char **map_type, int type_id);

/*
**	UTILS
*/
void	error_exit(char *error_msg);
int		get_kind_of_type(char *type_id);

#endif
