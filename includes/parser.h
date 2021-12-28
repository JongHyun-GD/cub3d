/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dason <dason@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/27 17:18:59 by dason             #+#    #+#             */
/*   Updated: 2021/12/28 11:56:02 by dason            ###   ########.fr       */
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
void	checker(int argc, char **argv, t_info *info);
void	error_exit(char *error_msg);

#endif
