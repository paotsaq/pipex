/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apinto <apinto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/30 07:05:03 by apinto            #+#    #+#             */
/*   Updated: 2021/07/31 14:39:16 by apinto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

int	infile_is_heredoc(s_info *info)
{
	char *buffer;
	char *limiter;

	buffer = malloc(4096);
	limiter = info->argv[2];
	if (pipe(info->current_pipe) == -1)
		return (-1);
	write(STDOUT_FILENO, "pipe heredoc> ", ft_strlen("pipe heredoc> "));
	while(get_next_line(STDIN_FILENO, &buffer) == 1)
	{
		if (ft_strncmp(buffer, limiter, ft_strlen(limiter) != 0))
		{
			write(info->current_pipe[1], buffer, ft_strlen(buffer));
			write(info->current_pipe[1], "\n", 1);
		}
		else
		{
			close(STDIN_FILENO);
			close(info->current_pipe[1]);
		}
		free(buffer);
		write(STDOUT_FILENO, "pipe heredoc> ", ft_strlen("pipe heredoc> "));
	}
	return (1);
}
