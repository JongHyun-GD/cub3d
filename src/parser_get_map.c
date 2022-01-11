/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_get_map.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dason <dason@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 22:18:10 by dason             #+#    #+#             */
/*   Updated: 2022/01/11 22:18:35 by dason            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

void get_map(t_info *info, char **tmp_file_data)

{
	char 	**map;
	char	*line;
	int		i;

	i = -1;
	while (tmp_file_data[++i])
	{
		if (i == 5)
			break ;
	}
	while (tmp_file_data[++i])
	{
		line = tmp_file_data[i];
		printf("%s\n", line);
	}
	map = (char **)ft_calloc(info->map_info.map_height + 1, sizeof(char *));
	if (!map)
		error_exit("Malloc allocation failed.");
	info->map_info.map = map;
}
