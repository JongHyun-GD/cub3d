/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dason <dason@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/27 17:18:59 by dason             #+#    #+#             */
/*   Updated: 2021/12/27 17:40:53 by dason            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# include "../libft/includes/libft.h"
# include "info.h"
# include <stdlib.h>
# include <stdio.h>

void	parser(int argc, char **argv, t_info *info);
void	checker(int argc, char **argv);

#endif
