/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_number_arguments_bonus.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apinto <apinto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/30 19:57:51 by apinto            #+#    #+#             */
/*   Updated: 2021/07/31 14:18:22 by apinto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

int	check_argument_number(int argc)
{
	if (argc < 5)
	{
		write(1, "pipex: wrong number of arguments.\n", 36);
		return (-1);
	}
	return (1);
}
