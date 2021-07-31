/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands_handler.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apinto <apinto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/29 07:54:39 by apinto            #+#    #+#             */
/*   Updated: 2021/07/31 18:17:55 by apinto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

/* if validation of path is successful, has a side effect:
 * info->concatenated_path stores the path to the binary! */
int	check_valid_command(s_info *info, char *command)
{
	int i;

	i = -1;
	while (info->paths[++i])
	{
		ft_bzero(info->concatenated_path, 1024);
		if (i == 0 && ft_strncmp(info->paths[i], "PATH=", 5) == 0)
			ft_strlcat(info->concatenated_path, (info->paths[i] + 5), 1024);
		else
			ft_strlcat(info->concatenated_path, info->paths[i], 1024);
		ft_strlcat(info->concatenated_path, "/", 1024);
		ft_strlcat(info->concatenated_path, command, 1024);
		if (access(info->concatenated_path, F_OK) == 0 &&
			access(info->concatenated_path, X_OK) == -1)
		{
			perror(info->exec_name);
			return (-1);
		}
		else if (access(info->concatenated_path, F_OK) == 0 &&
			access(info->concatenated_path, X_OK) == 0)
			return (1);
	}
	perror(info->exec_name);
	return (-1);
}

static void prepare_command(s_info *info, char ***split_command)
{
	*split_command = ft_split(info->argv[info->command_count + 2], ' ');
}

int	commands_handler(s_info *info)
{
	char **split_command;

	prepare_command(info, &split_command);
	if (!split_command)
		return (-1);
	check_valid_command(info, split_command[0]);
	if (pipe(info->current_pipe) == -1)
		return (-1);
	execute_command(info, split_command);
	free(split_command);
	return (1);
}
