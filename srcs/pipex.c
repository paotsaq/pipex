/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apinto <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/26 17:12:52 by apinto            #+#    #+#             */
/*   Updated: 2021/07/27 20:23:49 by apinto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

static int	check_argument_number(int argc)
{
	if (argc != 5)
	{
		write(1, "pipex: wrong number of arguments.\n", 36);
		return (-1);
	}
	return (1);
}

int	main(int argc, char **argv, char **envp)
{
	s_info info;

	if (check_argument_number(argc) == -1)
		return (-1);
	if (initialize_info(&info, argc, argv, envp) == -1)
		return (-1);
	file_handler(&info, 1);
	while (info.command_count != argc - 3)
		commands_handler(&info);
	return (0);
}
