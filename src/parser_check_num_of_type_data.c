/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_check_num_of_type_data.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dason <dason@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/27 20:03:30 by dason             #+#    #+#             */
/*   Updated: 2022/01/03 14:39:07 by dason            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

static int	get_num_of_type_data(char **s)
{
	int		count;

	count = 0;
	while (s[count])
		count++;
	return (count);
}

static bool check_num_of_type_data_fc(char **map_type)
{
	char	**tmp;
	int		i;
	int		j;
	int		count;

	count = 0;
	i = 0;
	while (map_type[++i])
	{
		tmp = ft_split(map_type[i], ',');
		j = -1;
		while (tmp[++j])
			count++;
		free_double_pointer(&tmp);
	}
	if (count != 3)
		return (false);
	return (true);
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
		check_num_of_type_data_fc(map_type) == false)
		error_exit("Too many type identifier data.");
}