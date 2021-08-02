/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apinto <apinto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/31 19:31:24 by apinto            #+#    #+#             */
/*   Updated: 2021/08/02 16:04:29 by apinto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	print_stdout_error(t_info *info, char *error, char *name)
{
	write(STDOUT_FILENO, info->argv[0], ft_strlen(info->argv[0]));
	write(STDOUT_FILENO, error, ft_strlen(error));
	write(STDOUT_FILENO, name, ft_strlen(name));
	write(STDOUT_FILENO, "\n", 1);
}
