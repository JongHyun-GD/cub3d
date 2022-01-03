/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_check_invalid_type_data.c                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dason <dason@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/27 20:03:30 by dason             #+#    #+#             */
/*   Updated: 2022/01/03 14:42:10 by dason            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

static bool check_invalid_type_data_fc(char **map_type)
{
	char	**tmp;
	int		i;
	int		j;
	int		k;

	i = 0;
	while (map_type[++i])
	{
		tmp = ft_split(map_type[i], ',');
		j = -1;
		while (tmp[++j])
		{
			k = -1;
			while (tmp[j][++k])
			{
				if (!ft_isdigit(tmp[j][k]))
				{
					free_double_pointer(&tmp);
					return (false);
				}
			}
		}
		free_double_pointer(&tmp);
	}
	return (true);
}

void	check_invalid_type_data(char **map_type)
{
	if (check_invalid_type_data_fc(map_type) == false)
		error_exit("Invalid type data.");
}
