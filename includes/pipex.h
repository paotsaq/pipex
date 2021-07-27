/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apinto <apinto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/25 11:07:15 by apinto            #+#    #+#             */
/*   Updated: 2021/07/27 20:17:12 by apinto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include <unistd.h>
#include <fcntl.h>

typedef struct command_info {
	int pipe[2];
	char *infile;
	int	infile_fd;
	char *outfile;
	int	outfile_fd;
	char *comm_output;
	char *fst_comm;
	char *sec_comm;
	char **paths;
	char **envp;
	char **argv;
	char concatenated_path[1024];
}				s_info;

char **get_path_variables(char **envp);
int	commands_handler(s_info *info, char *command);
int	check_valid_command(s_info *info, char *command);
int	initialize_info(s_info *info, char **argv, char **envp);
int execute_command(s_info *info, char **command);
int	file_handler(s_info *info, int in, int out);

/* testing */
void	test_command_exists(s_info *info, char *command);
