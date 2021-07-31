/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apinto <apinto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/30 07:05:03 by apinto            #+#    #+#             */
/*   Updated: 2021/07/31 18:19:31 by apinto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

int	infile_is_heredoc(s_info *info)
{
	char *buffer;
	char *limiter;

	buffer = malloc(4096);
	limiter = info->argv[2];
	if (pipe(info->heredoc_pipe) == -1)
		return (-1);
	write(STDOUT_FILENO, "pipe heredoc> ", ft_strlen("pipe heredoc> "));
	while(get_next_line(STDIN_FILENO, &buffer) == 1)
	{
		if (ft_strncmp(buffer, limiter, ft_strlen(limiter) != 0))
		{
			write(info->heredoc_pipe[1], buffer, ft_strlen(buffer));
			write(info->heredoc_pipe[1], "\n", 1);
			write(STDOUT_FILENO, "pipe heredoc> ", ft_strlen("pipe heredoc> "));
		}
		else
			close(STDIN_FILENO);
		free(buffer);
	}
	close(info->heredoc_pipe[1]);
	dup2(info->heredoc_pipe[0], info->infile_fd);
	return (1);
}
