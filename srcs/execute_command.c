/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_command.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apinto <apinto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/27 00:26:20 by apinto            #+#    #+#             */
/*   Updated: 2021/07/28 19:09:54 by apinto           ###   ########.fr       */
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
	char buffer[100];

	if (pipe(fd) == -1)
		return (-1);
	pid1 = fork();
	if (pid1 == 0)
	{
		printf("%s\n", info->infile);
		if (DEBUG)
			printf("executing %s\n", info->concatenated_path);
		printf("%d\n", info->infile_fd);
		printf("%d\n", STDIN);
		dup2(info->infile_fd, STDIN);
		err = execve(info->concatenated_path, ft_split("cat", ' '), info->envp);
		if (err == -1)
			printf("failed execution of %s\n", command[0]);
	}
	waitpid(pid1, NULL, 0);
	close(fd[1]);
	read(info->infilerfd, buffer, 15);
	buffer[15] = '\0';
	printf("buffer is %s\n", buffer);
	printf("this is the main process! \n");
	pid2 = fork();
	if (pid2 == 0)
	{
		dup2(fd[0], STDIN);
		if (DEBUG)
			printf("executing %s\n", "wc");
		err = execve("/usr/bin/wc", ft_split("wc", ' '), info->envp);
		if (err == -1)
			printf("failed execution of %s\n", "wc");
	}
	waitpid(pid2, NULL, 0);
	return (1);
}
