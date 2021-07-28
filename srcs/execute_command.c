/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_command.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apinto <apinto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/27 00:26:20 by apinto            #+#    #+#             */
/*   Updated: 2021/07/28 13:22:48 by apinto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

/* dup2(fd_1, fd_2)
 * fd_1 will be overwritten with fd_2
 *  fd[0]; //-> for using read end
    fd[1]; //-> for using write end*/
int execute_command(s_info *info, char **command)
{
	int pid1;
	int pid2;
	int err;
	int fd[2];

	if (pipe(fd) == -1)
		return (-1);
	pid1 = fork();
	if (pid1 == 0)
	{
		if (DEBUG)
		{
			printf("executing %s\n", info->concatenated_path);
			printf("command[1] + 1: %s\n", (command[1] + 1));
		}
		dup2(info->infile_fd, STDIN);
		dup2(fd[1], STDOUT);
		err = execve(info->concatenated_path, &command[1] + 1, info->envp);
		if (err == -1)
			printf("failed execution of %s\n", command[0]);
	}
	waitpid(pid1, NULL, 0);
	printf("this is the main process! \n");
	pid2 = fork();
	if (pid2 == 0)
	{
		dup2(fd[0], STDIN);
		close(fd[1]);
		if (DEBUG)
			printf("executing %s\n", "cat");
		err = execve("/bin/cat", NULL, info->envp);
		if (err == -1)
			printf("failed execution of %s\n", "cat");
	}
	waitpid(pid2, NULL, 0);
	return (1);
}
