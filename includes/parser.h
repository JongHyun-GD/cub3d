/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dason <dason@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/27 17:18:59 by dason             #+#    #+#             */
/*   Updated: 2021/12/28 21:50:57 by dason            ###   ########.fr       */
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
#include <fcntl.h>

void	parser(int argc, char **argv, t_info *info);
void	check_param(int argc, char **argv);
void	check_cub_get_type_data(t_info *info, int fd);
bool	is_type_id(char *type_id);
void	check_num_of_type_data(char **map_type);

#endif
