/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands_handler.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apinto <apinto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/29 07:54:39 by apinto            #+#    #+#             */
/*   Updated: 2021/08/02 19:46:16 by apinto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	free_split_allocation(char **split)
{
	int	i;

	i = -1;
	while (split[++i] != NULL)
		free(split[i]);
	free(split);
}

/* if validation of path is successful, has a side effect:
 * info->concatenated_path stores the path to the binary! */
int	check_valid_command(t_info *info, char *command)
{
	int	i;

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
		if (access(info->concatenated_path, F_OK) == 0
			&& access(info->concatenated_path, X_OK) == -1)
			return (-1);
		else if (access(info->concatenated_path, F_OK) == 0
			&& access(info->concatenated_path, X_OK) == 0)
			return (1);
	}
	return (-1);
}

static void	prepare_command(t_info *info, char ***split_command)
{
	*split_command = ft_split(info->argv[info->command_count + 2], ' ');
}

int	commands_handler(t_info *info)
{
	char	**split_command;

	prepare_command(info, &split_command);
	if (!split_command)
		return (-1);
	if (check_valid_command(info, split_command[0]) == -1)
	{
		handle_error_pipe(info);
		print_stdout_error(info, COMMAND_NOT_FOUND, split_command[0]);
		info->command_count++;
	}
	else
	{
		if (info->skip_pipe_creation == 1)
			info->skip_pipe_creation = 0;
		else if (pipe(info->current_pipe) == -1)
			return (-1);
		execute_command(info, split_command);
	}
	free_split_allocation(split_command);
	return (1);
}
