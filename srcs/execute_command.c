/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_command.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apinto <apinto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/27 00:26:20 by apinto            #+#    #+#             */
/*   Updated: 2021/07/28 07:36:15 by apinto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

int execute_command(s_info *info, char **command)
{
	int pid;

	pid = fork();
	if (pid == 0)
	{
		dup2(STDIN, info->infile_fd);
		dup2(STDIN, info->infile_fd);
		if (DEBUG)
			printf("executing %s\n", command[0]);
		printf("%s\n", command[1] + 1);
		int err = execve(info->concatenated_path, &command[1] + 1, info->envp);
		if (err == -1)
			printf("failed execution of %s\n", command[0]);
	}
	else
		wait(NULL);
	return (1);
}
