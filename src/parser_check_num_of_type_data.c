/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_check_num_of_type_data.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dason <dason@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/27 20:03:30 by dason             #+#    #+#             */
/*   Updated: 2022/01/03 17:16:10 by dason            ###   ########.fr       */
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

static bool	check_num_of_type_data_fc(char **map_type)
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

void	check_num_of_type_data(char **map_type, int type_id)
{
	int		num_of_type_data;

	num_of_type_data = get_num_of_type_data(map_type);
	if (type_id == TYPE_R && num_of_type_data != 3)
		error_exit("Too many type identifier data.: R");
	if ((type_id == TYPE_NO || type_id == TYPE_SO || \
		type_id == TYPE_WE || type_id == TYPE_EA || \
		type_id == TYPE_S) && \
		num_of_type_data != 2)
		error_exit("Too many type identifier data.: NO SO WA EA S");
	if ((type_id == TYPE_F || type_id == TYPE_C) && \
		check_num_of_type_data_fc(map_type) == false)
		error_exit("Too many type identifier data.: F C");
}
