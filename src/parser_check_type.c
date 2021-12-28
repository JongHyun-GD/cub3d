/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_check_type.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dason <dason@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/27 20:03:30 by dason             #+#    #+#             */
/*   Updated: 2021/12/28 21:52:23 by dason            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

bool	is_type_id(char *type_id)
{
	if (type_id == NULL)
		return (true);
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

static int	get_num_of_type_data(char **s)
{
	int		count;

	count = 0;
	while (s[count])
		count++;
	return (count);
}

void	check_num_of_type_data(char **map_type)
{
	char	*type_id;
	int		num_of_type_data;

	type_id = map_type[0];
	num_of_type_data = get_num_of_type_data(map_type);
	if (ft_strncmp("R", type_id, 2) == 0 && \
		num_of_type_data != 3)
		error_exit("Too many type identifier data.");
	if ((ft_strncmp("NO", type_id, 3) == 0 || \
		ft_strncmp("SO", type_id, 3) == 0 || \
		ft_strncmp("WE", type_id, 3) == 0 || \
		ft_strncmp("EA", type_id, 3) == 0 || \
		ft_strncmp("S", type_id, 2) == 0) && \
		num_of_type_data != 2)
		error_exit("Too many type identifier data.");
	if ((ft_strncmp("F", type_id, 2) == 0 || \
		ft_strncmp("C", type_id, 2) == 0) && \
		!(2 <= num_of_type_data && num_of_type_data <= 4))
		error_exit("Too many type identifier data.");
}
