/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_command.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apinto <apinto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/27 00:26:20 by apinto            #+#    #+#             */
/*   Updated: 2021/07/28 10:12:46 by apinto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

/* dup2(fd_1, fd_2)
 * fd_2 will be overwritten with fd_1 */
int execute_command(s_info *info, char **command)
{
	int pid1;
	int pid2;
	int err;
	int fd[2];
	char **command_2;

	if (pipe(fd) == -1)
		return (-1);
	dup2(STDIN, info->infile_fd);
	pid1 = fork();
	if (pid1 == 0)
	{
		if (DEBUG)
			printf("executing %s\n", command[0]);
		dup2(fd[1], STDOUT);
		printf("%s\n", command[1] + 1);
		err = execve(info->concatenated_path, &command[1] + 1, info->envp);
		if (err == -1)
			printf("failed execution of %s\n", command[0]);
	}
	pid2 = fork();
	if (pid2 == 0)
	{
		dup2(fd[0], STDIN);
		if (DEBUG)
			printf("executing %s\n", "grep");
		command_2 = ft_split("\"test\"", ' ');
		printf("%s\n", command_2[0]);
		err = execve("/usr/bin/grep", &command_2[0], info->envp);
		if (err == -1)
			printf("failed execution of %s\n", "grep");
	}
	waitpid(pid1, NULL, 0);
	waitpid(pid2, NULL, 0);
	return (1);
}
