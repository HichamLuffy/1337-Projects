/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfhad <hfhad@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 13:59:49 by hfhad             #+#    #+#             */
/*   Updated: 2025/01/17 19:17:42 by hfhad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	create_child_process(int input_fd, int output_fd[2], \
							char **command, char **env)
{
	pid_t	pid;

	pid = fork();
	if (pid == -1)
		return (-1);
	if (pid == 0)
	{
		close(output_fd[0]);
		dup2(input_fd, STDIN_FILENO);
		dup2(output_fd[1], STDOUT_FILENO);
		close(input_fd);
		close(output_fd[1]);
		execve(command[0], command, env);
		exit_error(command, "Execve error", 1, NULL);
	}
	return (pid);
}

void	open_files(char *file1, char *file2, int *fd)
{
	fd[0] = open(file1, O_RDWR);
	fd[1] = open(file2, O_CREAT | O_WRONLY | O_TRUNC, 0644);
	if (fd[1] < 0)
	{
		if (fd[0] >= 0)
			close(fd[0]);
		exit_error(NULL, "Output file error", 1, NULL);
	}
	if (fd[0] < 0)
	{
		write(2, "Input file error: Permission denied\n", 36);
		fd[0] = open("/dev/null", O_RDONLY);
		if (fd[0] < 0)
		{
			close(fd[1]);
			exit_error(NULL, "Failed to open /dev/null", 1, NULL);
		}
	}
}

void	cleanup_and_exit(char **cmd1, char **cmd2, int *fd, int status)
{
	if (cmd1)
		free_this(cmd1);
	if (cmd2)
		free_this(cmd2);
	if (fd[0] > 2)
		close(fd[0]);
	if (fd[1] > 2)
		close(fd[1]);
	exit(status);
}

int	main(int ac, char **av, char **env)
{
	char	**cmd[2];
	int		fd[2];
	int		pipe_fd[2];
	int		pid[2];
	int		status;

	if (ac != 5)
		exit_error(NULL, "Usage: ./pipex file1 cmd1 cmd2 file2\n", 0, NULL);
	open_files(av[1], av[4], fd);
	cmd[0] = get_command(av[2], env);
	cmd[1] = get_command(av[3], env);
	if (pipe(pipe_fd) == -1)
		(free_this(cmd[1]), exit_error(cmd[0], "Pipe error", 1, fd));
	pid[0] = create_child_process(fd[0], pipe_fd, cmd[0], env);
	if (pid[0] == -1)
		(close(pipe_fd[0]), close(pipe_fd[1]), \
				cleanup_and_exit(cmd[0], cmd[1], fd, 1));
	close(pipe_fd[1]);
	pid[1] = create_child_process(pipe_fd[0], fd, cmd[1], env);
	if (pid[1] == -1)
		(close(pipe_fd[0]), cleanup_and_exit(cmd[0], cmd[1], fd, 1));
	(close(pipe_fd[0]), close(fd[0]), close(fd[1]));
	(waitpid(pid[0], &status, 0), waitpid(pid[1], &status, 0));
	(free_this(cmd[0]), free_this(cmd[1]));
	return (WEXITSTATUS(status));
}
