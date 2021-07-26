/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apinto <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/26 18:35:19 by apinto            #+#    #+#             */
/*   Updated: 2021/07/26 18:40:05 by apinto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

int	main(int argc, char **argv, char **envp)
{
	s_info info;
	int i;
	char commands[2][10];

	if (argc > 0)
	{
		if (initialize_info(&info, argv, envp) == -1)
			return (-1);
		i = -1;
		ft_strlcpy(commands[0], "ls", 10);
		ft_strlcpy(commands[1], "lsdjaiss", 10);
		while (++i < 2)
			test_command_exists(&info, commands[i]);
	}
}
