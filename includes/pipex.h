/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apinto <apinto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/25 11:07:15 by apinto            #+#    #+#             */
/*   Updated: 2021/07/26 18:16:58 by apinto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include <unistd.h>

typedef struct command_info {
	char *infile;
	char *outfile;
	char *fst_comm;
	char *sec_comm;
	char **paths;
	char concatenated_path[1024];
}				s_info;

char **get_path_variables(char **envp);
int	commands_handler(s_info *info, char *command);
int	check_valid_command(s_info *info, char *command);
int	initialize_info(s_info *info, char **argv, char **envp);
