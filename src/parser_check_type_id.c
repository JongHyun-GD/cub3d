/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_check_type_id.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dason <dason@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/27 20:03:30 by dason             #+#    #+#             */
/*   Updated: 2022/01/03 17:21:24 by dason            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

static bool	is_type_id(char *type_id)
{
	if (ft_strncmp("R", type_id, 2) == 0)
		return (true);
	if (ft_strncmp("NO", type_id, 3) == 0)
		return (true);
	if (ft_strncmp("SO", type_id, 3) == 0)
		return (true);
	if (ft_strncmp("WE", type_id, 3) == 0)
		return (true);
	if (ft_strncmp("EA", type_id, 3) == 0)
		return (true);
	if (ft_strncmp("S", type_id, 2) == 0)
		return (true);
	if (ft_strncmp("F", type_id, 2) == 0)
		return (true);
	if (ft_strncmp("C", type_id, 2) == 0)
		return (true);
	if (ft_strncmp("1", type_id, 1) == 0)
		return (true);
	if (ft_strncmp(" ", type_id, 1) == 0)
		return (true);
	return (false);
}

void	check_type_id(char *type_id)
{
	if (is_type_id(type_id) == false)
		error_exit("Invalid type identifier.");
}
