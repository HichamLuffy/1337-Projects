/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_utils_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfhad <hfhad@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 15:21:07 by hfhad             #+#    #+#             */
/*   Updated: 2025/01/17 19:18:46 by hfhad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header_bonus.h"

void	free_this(char **to_free)
{
	int	i;

	i = 0;
	if (to_free)
	{
		while (to_free[i])
		{
			free(to_free[i]);
			i++;
		}
		free(to_free);
	}
}

void	free_process(t_process *process)
{
	if (process)
	{
		if (process->pipes)
			close_pipes(process->pipes, process->num_cmds - 1);
		free(process);
	}
}

void	open_files(char *infile, char *outfile, \
					t_process *process, int is_here_doc)
{
	if (is_here_doc)
	{
		process->fd[1] = open(outfile, O_WRONLY | O_CREAT | O_APPEND, 0644);
		if (process->fd[1] < 0)
			exit_error_cleanup(process, NULL, "Output file error\n", 1);
		process->fd[0] = -1;
	}
	else
	{
		process->fd[1] = open(outfile, O_WRONLY | O_CREAT | O_TRUNC, 0644);
		if (process->fd[1] < 0)
			exit_error_cleanup(process, NULL, "Output file error\n", 1);
		process->fd[0] = open(infile, O_RDONLY);
		if (process->fd[0] < 0)
		{
			write(2, "Input file error: Permission denied\n", 36);
			process->fd[0] = open("/dev/null", O_RDONLY);
			if (process->fd[0] < 0)
			{
				close(process->fd[1]);
				exit_error_cleanup(process, NULL, \
						"Failed to open /dev/null\n", 1);
			}
		}
	}
}

void	handle_here_doc(char *limiter, t_process *process)
{
	pid_t	pid;
	int		temp_fd;

	temp_fd = get_available_temp_file(process);
	if (temp_fd == -1)
		exit_error_cleanup(process, NULL, "Heredoc temp file error\n", 1);
	close(temp_fd);
	pid = fork();
	if (pid == -1)
	{
		unlink(process->temp_file);
		exit_error_cleanup(process, NULL, "Fork error\n", 1);
	}
	if (pid == 0)
		read_here_doc(limiter, ft_strlen(limiter), process->temp_file);
	waitpid(pid, NULL, 0);
	process->fd[0] = open(process->temp_file, O_RDONLY);
	if (process->fd[0] == -1)
	{
		unlink(process->temp_file);
		exit_error_cleanup(process, NULL, "Heredoc temp file error\n", 1);
	}
	unlink(process->temp_file);
}
