/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_exists.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apinto <apinto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/25 15:42:39 by apinto            #+#    #+#             */
/*   Updated: 2021/07/26 18:35:14 by apinto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	test_command_exists(s_info *info, char *command)
{
	if (check_valid_command(info, command) == 1)
		printf("✅ %s command exists!\n", command);
	else
		printf("🔴 %s command should exist!\n", command);
}
