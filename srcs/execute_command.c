/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_command.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apinto <apinto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/27 00:26:20 by apinto            #+#    #+#             */
/*   Updated: 2021/08/02 16:03:16 by apinto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

static int	command_is_first(t_info *info)
{
	return (info->command_count == 1);
}

static int	command_is_last(t_info *info)
{
	return (info->command_count == info->argc - 3);
}

static int	command_is_heredoc_command(t_info *info)
{
	return (info->command_count == 2);
}

/* dup2(fd_1, fd_2)
 * fd_2 will point to the same stream as fd_1
 *  fd[0]; //-> for using read end
    fd[1]; //-> for using write end */
int	execute_command(t_info *info, char **command)
{
	int	pid;

	info->command_count++;
	pid = fork();
	if (pid == 0)
	{
		close(info->current_pipe[0]);
		if (param_is_heredoc(info) && command_is_heredoc_command(info))
			dup2(info->heredoc_pipe[0], STDIN_FILENO);
		else if (command_is_first(info))
			dup2(info->infile_fd, STDIN_FILENO);
		else
			dup2(info->previous_pipe[0], STDIN_FILENO);
		if (command_is_last(info))
			dup2(info->outfile_fd, STDOUT_FILENO);
		else
			dup2(info->current_pipe[1], STDOUT_FILENO);
		if (!((command_is_first(info) && !info->allow_first)
				|| (command_is_last(info) && !info->allow_last)))
			execve(info->concatenated_path, command, info->envp);
	}
	wait(NULL);
	close(info->current_pipe[1]);
	duplicate_pipe_to_previous(info);
	return (1);
}
