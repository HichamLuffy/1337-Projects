/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfhad <hfhad@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 16:01:16 by hfhad             #+#    #+#             */
/*   Updated: 2025/01/16 15:59:35 by hfhad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header_bonus.h"

void	close_pipes(int **pipes, int num_pipes)
{
	int	i;

	i = 0;
	if (pipes)
	{
		while (i < num_pipes)
		{
			close_if(pipes[i][0]);
			close_if(pipes[i][1]);
			if (pipes[i])
				free(pipes[i]);
			i++;
		}
		free(pipes);
	}
}

int	**create_pipes(int num_pipes, t_process *process)
{
	int	**pipes;
	int	i;

	pipes = malloc(sizeof(int *) * num_pipes);
	if (!pipes)
		exit_error_cleanup(process, NULL, \
					"Error: Memory allocation failed\n", 1);
	i = 0;
	i = 0;
	while (i < num_pipes)
	{
		pipes[i] = malloc(sizeof(int) * 2);
		if (!pipes[i] || pipe(pipes[i]) == -1)
			exit_error_cleanup(process, NULL, "Pipe error\n", 1);
		i++;
	}
	return (pipes);
}

void	execute_command(char *command, char **env, t_process *process)
{
	char	**cmd;

	cmd = get_command(command, env, process);
	execve(cmd[0], cmd, env);
	exit_error_cleanup(process, cmd, "Execve error", 1);
}

void	process_commands(char **av, char **env, t_process *process)
{
	int		i;
	pid_t	pid;

	i = 0;
	while (i < process->num_cmds)
	{
		pid = fork();
		if (pid == -1)
			exit_error_cleanup(process, NULL, "Fork error\n", 1);
		if (pid == 0)
		{
			setup_child_pipes(process, i);
			close_some_pipes(process, i);
			execute_command(av[i], env, process);
			exit(1);
		}
		else
			handle_parent_pipes(process, i);
		i++;
	}
}

void	read_here_doc(char *limiter, size_t limiter_len, char *filename)
{
	char	*line;
	int		temp_fd;

	temp_fd = open(filename, \
						O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (temp_fd == -1)
		exit(1);
	while (1)
	{
		write(1, "pipe heredoc> ", 14);
		line = get_next_line(0);
		if (!line)
			break ;
		if (ft_strncmp(line, limiter, limiter_len) == 0 && \
				(line[limiter_len] == '\n' || line[limiter_len] == '\0'))
		{
			free(line);
			break ;
		}
		write(temp_fd, line, ft_strlen(line));
		free(line);
	}
	close(temp_fd);
	exit(0);
}
