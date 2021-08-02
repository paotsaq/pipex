/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apinto <apinto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/31 19:31:24 by apinto            #+#    #+#             */
/*   Updated: 2021/08/02 16:14:09 by apinto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	print_stdout_error(t_info *info, char *error, char *name)
{
	write(STDERR_FILENO, info->argv[0], ft_strlen(info->argv[0]));
	write(STDERR_FILENO, error, ft_strlen(error));
	write(STDERR_FILENO, name, ft_strlen(name));
	write(STDERR_FILENO, "\n", 1);
}
