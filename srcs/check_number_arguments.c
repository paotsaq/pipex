/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_number_arguments.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apinto <apinto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/30 19:54:14 by apinto            #+#    #+#             */
/*   Updated: 2021/08/02 18:50:31 by apinto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

int	check_argument_number(int argc)
{
	if (argc != 5)
	{
		write(1, "pipex: wrong number of arguments.\n", 35);
		return (-1);
	}
	return (1);
}
