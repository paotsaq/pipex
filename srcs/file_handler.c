/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_handler.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apinto <apinto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/27 19:31:46 by apinto            #+#    #+#             */
/*   Updated: 2021/07/31 12:47:20 by apinto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

int	file_handler_in(s_info *info)
{
	if (access(info->infile, F_OK | R_OK) == -1)
	{
		perror(info->exec_name);
		info->skip_first = 1;
		if (pipe(info->current_pipe) == -1)
			return (-1);
		write(info->current_pipe[1], NULL, 0);
		close(info->current_pipe[1]);
		info->previous_pipe[0] = info->current_pipe[0];
		return (1);
	}
	else if (access(info->infile, F_OK) != -1)
	{
		info->infile_fd = open(info->infile, O_RDONLY);
		if (info->infile_fd == -1)
		{
			perror(info->exec_name);
			return (-1);
		}
	}
	return (1);
}

int	file_handler_out(s_info *info)
{
	if (access(info->outfile, F_OK) != -1 &&
			(access(info->outfile, R_OK) == -1 ||
			 access(info->outfile, W_OK) == -1))
	{
		perror(info->exec_name);
		return (-1);
	}
	else if (access(info->outfile, F_OK) != -1)
		info->outfile_fd = open(info->outfile, O_WRONLY | O_TRUNC);
	else
		info->outfile_fd = open(info->outfile, O_WRONLY | O_CREAT, 0755);
	return (1);
}
