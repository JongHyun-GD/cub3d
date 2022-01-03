/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dason <dason@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/28 12:24:58 by dason             #+#    #+#             */
/*   Updated: 2022/01/03 15:01:18 by dason            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

void	error_exit(char *error_msg)
{
	ft_putstr_fd(error_msg, 2);
	exit(1);
}

void	get_kind_of_type(char *type_id)
{
	
}