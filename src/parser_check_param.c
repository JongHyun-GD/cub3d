/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_check_param.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dason <dason@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/27 17:18:52 by dason             #+#    #+#             */
/*   Updated: 2022/01/03 16:33:51 by dason            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

void	check_param(int argc, char **argv)
{
	if (argc != 2 && argc != 3)
		error_exit("Invalid parameters.");
	if (argc == 3)
	{
		if (ft_strncmp("--save", argv[2], 7) != 0)
			error_exit("Invalid parameters.");
	}
}
