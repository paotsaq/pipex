/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apinto <apinto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/25 11:06:42 by apinto            #+#    #+#             */
/*   Updated: 2021/08/02 14:35:35 by apinto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

static char	**get_path_variables(char **envp)
{
	char	**paths;

	while (*envp && ft_strncmp(*envp, "PATH=", 5) != 0)
		envp++;
	paths = ft_split(*envp, ':');
	return (paths);
}

int	param_is_heredoc(t_info *info)
{
	return (BONUS && ft_strcmp(info->argv[1], "here_doc") == 0);
}

int	initialize_info(t_info *info, int argc, char **argv, char **envp)
{
	info->exec_name = argv[0] + 2;
	info->allow_first = 1;
	info->allow_last = 1;
	info->infile = argv[1];
	info->outfile = argv[argc - 1];
	info->command_count = 0;
	info->skip_pipe_creation = 0;
	info->paths = get_path_variables(envp);
	info->envp = envp;
	info->argv = argv;
	info->argc = argc;
	if (!info->paths)
		return (-1);
	return (1);
}

int	handle_error_pipe(t_info *info)
{
	if (pipe(info->current_pipe) == -1)
		return (-1);
	write(info->current_pipe[1], "", 1);
	close(info->current_pipe[1]);
	dup2(info->current_pipe[0], info->infile_fd);
	info->skip_pipe_creation = 1;
	return (1);
}
