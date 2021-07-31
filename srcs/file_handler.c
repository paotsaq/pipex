/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_handler.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apinto <apinto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/27 19:31:46 by apinto            #+#    #+#             */
/*   Updated: 2021/07/31 08:16:00 by apinto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

int	file_handler(s_info *info, int in)
{
	if (in && access(info->infile, R_OK) == -1)
	{
		perror(info->exec_name);
		return (-1);
	}
	else if (in)
	{
		info->infile_fd = open(info->infile, O_RDONLY);
		if (info->infile_fd == -1)
		{
			perror(info->exec_name);
			return (-1);
		}
	}
	if (access(info->outfile, F_OK) == 1 &&
			(access(info->outfile, R_OK) == -1 ||
			 access(info->outfile, W_OK) == -1))
	{
		perror(info->exec_name);
		return (-1);
	}
	else if (access(info->outfile, F_OK) == 1)
		info->outfile_fd = open(info->outfile,
				O_WRONLY | O_TRUNC);
	else
		info->outfile_fd = open(info->outfile,
				O_WRONLY | O_CREAT, 0755);
	return (1);
}
