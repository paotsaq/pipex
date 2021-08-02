/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_handler.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apinto <apinto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/27 19:31:46 by apinto            #+#    #+#             */
/*   Updated: 2021/08/02 19:46:22 by apinto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

int	file_handler_in(t_info *info)
{
	if (access(info->infile, R_OK) != -1)
	{
		info->infile_fd = open(info->infile, O_RDONLY);
		if (info->infile_fd == -1)
		{
			perror(info->exec_name);
			return (-1);
		}
		return (1);
	}
	if (access(info->infile, F_OK) == -1)
		print_stdout_error(info, FILE_OR_DIR, info->infile);
	else if (access(info->infile, R_OK) == -1)
		print_stdout_error(info, NO_PERM, info->infile);
	info->command_count++;
	return (handle_error_pipe(info));
}

int	file_handler_out(t_info *info)
{
	if (access(info->outfile, F_OK) != -1
		&& (access(info->outfile, R_OK) == -1
			|| access(info->outfile, W_OK) == -1))
	{
		print_stdout_error(info, NO_PERM, info->outfile);
		info->allow_last = 0;
		return (handle_error_pipe(info));
	}
	else if (param_is_heredoc(info) && access(info->outfile, F_OK) != -1)
		info->outfile_fd = open(info->outfile, O_WRONLY | O_APPEND);
	else if (access(info->outfile, F_OK) != -1)
		info->outfile_fd = open(info->outfile, O_WRONLY | O_TRUNC);
	else
		info->outfile_fd = open(info->outfile, O_WRONLY | O_CREAT, 0644);
	if (info->outfile_fd == -1)
	{
		perror(info->exec_name);
		return (-1);
	}
	return (1);
}
