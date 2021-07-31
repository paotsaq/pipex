/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_command.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apinto <apinto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/27 00:26:20 by apinto            #+#    #+#             */
/*   Updated: 2021/07/31 12:14:20 by apinto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

static	void pipe_management(s_info *info)
{
	info->previous_pipe[0] = info->current_pipe[0];
	info->previous_pipe[1] = info->current_pipe[1];
}

/* dup2(fd_1, fd_2)
 * fd_2 will point to the same stream as fd_1
 *  fd[0]; //-> for using read end
    fd[1]; //-> for using write end */
int execute_command(s_info *info, char **command)
{
	int pid;

	info->command_count++;
	pid = fork();
	if (pid == 0)
	{
		if (info->command_count == 1)
			dup2(info->infile_fd, STDIN_FILENO);
		else
			dup2(info->previous_pipe[0], STDIN_FILENO);
		if (info->command_count == info->argc - 3)
			dup2(info->outfile_fd, STDOUT_FILENO);
		else
			dup2(info->current_pipe[1], STDOUT_FILENO);
		execve(info->concatenated_path, command, info->envp);
	}
	wait(NULL);
	close(info->current_pipe[1]);
	pipe_management(info);
	return (1);
}
