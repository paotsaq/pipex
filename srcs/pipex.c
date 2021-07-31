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

int	main(int argc, char **argv, char **envp)
{
	s_info info;

	if (check_argument_number(argc) == -1)
		return (-1);
	if (initialize_info(&info, argc, argv, envp) == -1)
		return (-1);
	if (BONUS && ft_strcmp(argv[1], "here_doc") == 0)
	{
	 	infile_is_heredoc(&info);
		info.command_count++;
	}
	else if (file_handler_in(&info) == -1)
		return (-1);
	if (file_handler_out(&info) == -1)
		return (-1);
	while (info.command_count != argc - 3)
		commands_handler(&info);
	return (0);
}
