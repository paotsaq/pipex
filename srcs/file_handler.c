/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_handler.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apinto <apinto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/27 19:31:46 by apinto            #+#    #+#             */
/*   Updated: 2021/07/28 21:07:32 by apinto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

int	file_handler(s_info *info, int in)
{
	if (in && access(info->infile, R_OK) == -1)
	{
		printf("no such file or directory: %s\n", info->infile);
		return (-1);
	}
	else if (in)
	{
		info->infile_fd = open(info->infile, O_RDONLY);
		if (info->infile_fd == -1)
			return (-1);
	}
	info->outfile_fd = open(info->outfile,
			O_RDWR | O_CREAT | O_TRUNC, 0777);
	if (info->outfile_fd == -1)
		return (-1);
	return (1);
}
