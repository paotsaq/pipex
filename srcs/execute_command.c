/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_command.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apinto <apinto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/27 00:26:20 by apinto            #+#    #+#             */
/*   Updated: 2021/07/29 20:51:24 by apinto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

/* dup2(fd_1, fd_2)
 * fd_2 will point to the same stream as fd_1
 *  fd[0]; //-> for using read end
    fd[1]; //-> for using write end */
int execute_command(s_info *info, char **command)
{
	int err;
	int pid;
	// char buffer[100];

	printf("I'm executing command %s with args %s\n", command[0], command[1]);
	info->command_count++;
	if (pipe(info->current_pipe) == -1)
		return (-1);
	pid = fork();
	if (pid == 0)
	{
		if (info->command_count == 1)
		{
			dup2(info->infile_fd, STDIN_FILENO);
			close(info->current_pipe[0]);
		}
		else
			dup2(info->previous_pipe[0], STDIN_FILENO);
		if (info->command_count == info->argc - 3)
		{
			dup2(info->outfile_fd, STDOUT_FILENO);
			close(info->current_pipe[1]);
		}
		else
			dup2(info->current_pipe[1], STDOUT_FILENO);
		err = execve(info->concatenated_path, command, info->envp);
		if (err == -1)
			printf("failed execution of %s\n", command[0]);
	}
	// read(info->current_pipe[0], buffer, 20);
	// buffer[20] = '\0';
	// printf("buffer is %s\n", buffer);
	close(info->current_pipe[1]);
	wait(NULL);
	info->previous_pipe[0] = info->current_pipe[0];
	info->previous_pipe[1] = info->current_pipe[1];
	return (1);
}
