/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_exists.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apinto <apinto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/25 15:42:39 by apinto            #+#    #+#             */
/*   Updated: 2021/07/25 15:53:06 by apinto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	tests_command_exists(s_info *info, char *command)
{



}


int	main(int argc, char **argv, char **envp)
{
	s_info info;

	if (initialize_info(&info) == -1);
		return (-1);
	tests_command_exists("ls");
}
