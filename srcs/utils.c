/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apinto <apinto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/25 11:06:42 by apinto            #+#    #+#             */
/*   Updated: 2021/07/28 20:35:22 by apinto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

char **get_path_variables(char **envp)
{
	char **paths;

	while (*envp && ft_strncmp(*envp, "PATH=", 5) != 0)
		envp++;
	if (DEBUG)
		printf("%s\n", *envp);
	paths = ft_split(*envp, ':');
	return paths;
}

/* if validation of path is successful, has a side effect:
 * info->concatenated_path stores the path to the binary! */
int	check_valid_command(s_info *info, char *command)
{
	int i;

	i = -1;
	while (info->paths[++i])
	{
		ft_bzero(info->concatenated_path, 1024);
		ft_strlcat(info->concatenated_path, info->paths[i], 1024);
		ft_strlcat(info->concatenated_path, "/", 1024);
		ft_strlcat(info->concatenated_path, command, 1024);
		if (DEBUG)
			printf("command is to be found at:\n%s\n", info->concatenated_path);
		if (access(info->concatenated_path, F_OK) == 0 &&
			access(info->concatenated_path, X_OK) == -1)
		{
			printf("permission denied: %s\n", command);
			return (-1);
		}
		else if (access(info->concatenated_path, F_OK) == 0 &&
			access(info->concatenated_path, X_OK) == 0)
			return (1);
	}
	printf("command not found: %s\n", command);
	return (-1);
}

int	commands_handler(s_info *info, char *command)
{
	char **split_command;

	split_command = ft_split(command, ' ');
	if (!split_command)
		return (-1);
	// 🧨 should free stuff?
	if (check_valid_command(info, split_command[0]) == -1)
		return (-1);
	else
	{
		execute_command(info, split_command);
		return (1);
	}
}

int	initialize_info(s_info *info, char **argv, char **envp)
{
	info->infile = argv[1];
	info->fst_comm = argv[2];
	info->sec_comm = argv[3];
	info->outfile = argv[4];
	info->paths = get_path_variables(envp);
	info->envp = envp;
	info->argv = argv;
	if (!info->paths)
		return (-1);
	return (1);
}
