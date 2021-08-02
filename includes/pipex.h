/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apinto <apinto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/25 11:07:15 by apinto            #+#    #+#             */
/*   Updated: 2021/08/02 15:25:15 by apinto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H
# include "../libft/libft.h"
# include <unistd.h>
# include <fcntl.h>
# include <string.h>

# define FILE_OR_DIR ": no such file or directory: "
# define NO_PERM ": permission denied: "
# define COMMAND_NOT_FOUND ": command not found: "

typedef struct s_command_info {
	int		current_pipe[2];
	int		previous_pipe[2];
	int		heredoc_pipe[2];
	char	*exec_name;
	char	*infile;
	int		infile_fd;
	char	*outfile;
	int		outfile_fd;
	int		allow_first;
	int		allow_last;
	int		skip_pipe_creation;
	int		command_count;
	char	**paths;
	char	**envp;
	int		argc;
	char	**argv;
	char	concatenated_path[1024];
}				t_info;

int		commands_handler(t_info *info);
int		check_valid_command(t_info *info, char *command);
int		initialize_info(t_info *info, int argc, char **argv, char **envp);
int		execute_command(t_info *info, char	**command);
int		file_handler_in(t_info *info);
int		file_handler_out(t_info *info);
int		check_argument_number(int argc);
void	print_stdout_error(t_info *info, char *error, char *name);
int		handle_error_pipe(t_info *info);
void	duplicate_pipe_to_previous(t_info *info);

/* bonus */
int		infile_is_heredoc(t_info *info);
int		param_is_heredoc(t_info *info);

#endif
