/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands_handler.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apinto <apinto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/29 07:54:39 by apinto            #+#    #+#             */
/*   Updated: 2021/07/29 08:23:23 by apinto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

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
	check_valid_command(info, split_command[0]);
	execute_command(info, split_command);
	free(split_command);
}
