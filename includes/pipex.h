/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apinto <apinto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/25 11:07:15 by apinto            #+#    #+#             */
/*   Updated: 2021/07/29 07:41:27 by apinto           ###   ########.fr       */
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
	int		pipe_fd[2];
	char	*exec_name;
	char	*infile;
	int		infile_fd;
	char	*outfile;
	int		command_count;
	int		outfile_fd;
	char	**paths;
	char	**envp;
	int		argc;
	char	**argv;
	char	concatenated_path[1024];
}				s_info;

char **get_path_variables(char **envp);
int	commands_handler(s_info *info, char *command);
int	check_valid_command(s_info *info, char *command);
int	initialize_info(s_info *info, int argc, char **argv, char **envp);
int execute_command(s_info *info, char **command);
int	file_handler(s_info *info, int in);

/* testing */
void	test_command_exists(s_info *info, char *command);
