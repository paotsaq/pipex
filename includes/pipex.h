/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apinto <apinto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/25 11:07:15 by apinto            #+#    #+#             */
/*   Updated: 2021/07/31 11:29:03 by apinto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include <unistd.h>
#include <fcntl.h>
#include <string.h>

# define STDIN 0
# define STDOUT 1
# define STDERR 2

typedef struct command_info {
	int		current_pipe[2];
	int		previous_pipe[2];
	char	*exec_name;
	char	*infile;
	int		infile_fd;
	char	*outfile;
	int		outfile_fd;
	int		skip_first;
	int		command_count;
	char	**paths;
	char	**envp;
	int		argc;
	char	**argv;
	char	concatenated_path[1024];
}				s_info;

char **get_path_variables(char **envp);
int	commands_handler(s_info *info);
int	check_valid_command(s_info *info, char *command);
int	initialize_info(s_info *info, int argc, char **argv, char **envp);
int execute_command(s_info *info, char **command);
int	file_handler_in(s_info *info);
int	file_handler_out(s_info *info);
int	check_argument_number(int argc);

/* testing */
void	test_command_exists(s_info *info, char *command);
