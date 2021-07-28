/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_command.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apinto <apinto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/27 00:26:20 by apinto            #+#    #+#             */
/*   Updated: 2021/07/28 20:54:02 by apinto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

/* dup2(fd_1, fd_2)
 * fd_2 will point to the same stream as fd_1
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
		dup2(info->infile_fd, STDIN);
		dup2(fd[1], STDOUT);
		err = execve(info->concatenated_path, ft_split("cat", ' '), info->envp);
		if (err == -1)
			printf("failed execution of %s\n", command[0]);
	}
	waitpid(pid1, NULL, 0);
	close(fd[1]);
	pid2 = fork();
	if (pid2 == 0)
	{
		dup2(fd[0], STDIN);
		dup2(info->outfile_fd, STDOUT);
		err = execve("/usr/bin/wc", ft_split("wc", ' '), info->envp);
		if (err == -1)
			printf("failed execution of %s\n", "wc");
	}
	waitpid(pid2, NULL, 0);
	return (1);
}
