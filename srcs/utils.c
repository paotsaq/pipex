/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apinto <apinto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/25 11:06:42 by apinto            #+#    #+#             */
/*   Updated: 2021/07/31 18:37:34 by apinto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

char	**get_path_variables(char **envp)
{
	char	**paths;

	while (*envp && ft_strncmp(*envp, "PATH=", 5) != 0)
		envp++;
	paths = ft_split(*envp, ':');
	return (paths);
}

int	initialize_info(t_info *info, int argc, char **argv, char **envp)
{
	info->exec_name = argv[0] + 2;
	info->infile = argv[1];
	info->outfile = argv[argc - 1];
	info->command_count = 0;
	info->paths = get_path_variables(envp);
	info->envp = envp;
	info->argv = argv;
	info->argc = argc;
	if (!info->paths)
		return (-1);
	return (1);
}
