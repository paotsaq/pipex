/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_handler.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apinto <apinto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/27 19:31:46 by apinto            #+#    #+#             */
/*   Updated: 2021/07/30 17:30:23 by apinto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

int	file_handler(s_info *info, int in)
{
	if (in && access(info->infile, R_OK) == -1)
	{
		perror(info->exec_name);
		return (-1);
	}
	else if (in)
	{
		info->infile_fd = open(info->infile, O_RDONLY);
		if (info->infile_fd == -1)
		{
			perror(info->exec_name);
			return (-1);
		}
	}
	if (access(info->outfile, R_OK) == 1 &&
		access(info->outfile, W_OK) == -1)
	{
		perror(info->exec_name);
		return (-1);
	}
	else
		// this has to be changed
		info->outfile_fd = open(info->outfile,
				O_WRONLY | O_CREAT | O_TRUNC, 0777);
	return (1);
}
