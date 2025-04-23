/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfhad <hfhad@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 13:59:49 by hfhad             #+#    #+#             */
/*   Updated: 2025/01/17 18:27:28 by hfhad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header_bonus.h"

void	close_if(int fd)
{
	if (fd > 2)
		close(fd);
}

void	init_process(t_process *process, int ac, char **av, int is_here_doc)
{
	process->temp_file[0] = '\0';
	if (is_here_doc && ac < 6)
		exit_error_cleanup(process, NULL, "Invalid heredoc args\n", 1);
	if (is_here_doc)
		process->num_cmds = ac - 4;
	else
		process->num_cmds = ac - 3;
	if (process->num_cmds < 2)
		exit_error_cleanup(process, NULL, "Not enough commands\n", 1);
	if (is_here_doc)
	{
		handle_here_doc(av[2], process);
		open_files(NULL, av[ac - 1], process, 1);
	}
	else
		open_files(av[1], av[ac - 1], process, 0);
	process->pipes = create_pipes(process->num_cmds - 1, process);
}

int	wait_children(int num_cmds)
{
	int	i;
	int	status;
	int	last_status;

	i = 0;
	while (i < num_cmds)
	{
		wait(&status);
		if (i == num_cmds - 1)
			last_status = status;
		i++;
	}
	return (WEXITSTATUS(last_status));
}

int	main(int ac, char **av, char **env)
{
	t_process	*process;
	int			is_here_doc;
	int			exit_code;

	if (ac < 5)
	{
		write(2, "Invalid number of arguments\n", 28);
		exit(1);
	}
	process = malloc(sizeof(t_process));
	if (!process)
		exit_error_cleanup(NULL, NULL, "Error: Memory allocation failed\n", 1);
	process->fd[0] = -1;
	process->fd[1] = -1;
	process->pipes = NULL;
	is_here_doc = (ft_strncmp(av[1], "here_doc", 8) == 0);
	init_process(process, ac, av, is_here_doc);
	if (is_here_doc)
		process_commands(av + 3, env, process);
	else
		process_commands(av + 2, env, process);
	(close_if(process->fd[0]), close_if(process->fd[1]));
	exit_code = wait_children(process->num_cmds);
	free_process(process);
	return (exit_code);
}
