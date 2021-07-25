/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apinto <apinto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/25 11:06:42 by apinto            #+#    #+#             */
/*   Updated: 2021/07/25 15:50:13 by apinto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

char **get_path_variables(char **envp)
{
	char **paths;

	while (*envp && ft_strncmp(*envp, "PATH=", 5) != 0)
		envp++;
	printf("%s\n", *envp);
	paths = ft_split(*envp, ':');
	return paths;
}

int	commands_handler(s_info *info, char *command)
{
	char **split_command;

	split_command = ft_split(command, ' ');
	if (!split_command)
		return (-1);
	// should free stuff?
	if (check_valid_command(split_command[0]) == -1)
		return (-1);
	else
	{


	}
}

int	check_valid_command(s_info *info, char *command)
{
	while (*paths)
	{
		ft_bzero(info->concatenated_path, 1024);
		ft_strcat(info->concatenated_path, *paths);
		ft_strcat(info->concatenated_path, *command);
		if (access(ft_strcat(info->concatenated_path, F_OK) == 0) &&
			access(ft_strcat(info->concatenated_path, X_OK) == -1))
		{
			printf("permission denied: %s\n", command);
			return (-1);
		}
		else if (access(ft_strcat(info->concatenated_path, F_OK) == 0) &&
			access(ft_strcat(info->concatenated_path, X_OK) == 0))
			return (1);
		paths++;
	}
	printf("command not found: %s\n", command);
	return (-1);
}

int	initialize_info(s_info *info)
{
	info.infile = argv[1];
	info.fst_comm = argv[2];
	info.sec_comm = argv[3];
	info.outfile = argv[4];
	info.paths = get_path_variables(envp);
	if (!info.paths)
		return (-1);
	return (1);
}

int	main(int argc, char **argv, char **envp)
{
	s_info info;

	if (argc != 5)
	{
		printf("Wrong number of arguments! 😗");
		return (-1);
	}
	if (access(argv[1], R_OK) == -1)
	{
		printf("no such file or directory: %s\n", argv[1]);
		return (-1);
	}
	if (initialize_info(&info) == -1);
		return (-1);
	commands_handler(info.fst_comm);
	return (0);
}
