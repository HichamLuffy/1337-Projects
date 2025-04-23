/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_helpers_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfhad <hfhad@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 14:46:24 by hfhad             #+#    #+#             */
/*   Updated: 2025/01/17 18:26:38 by hfhad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header_bonus.h"

void	setup_child_pipes(t_process *process, int i)
{
	if (i == 0)
	{
		dup2(process->fd[0], STDIN_FILENO);
		dup2(process->pipes[i][1], STDOUT_FILENO);
	}
	else if (i == process->num_cmds - 1)
	{
		dup2(process->pipes[i - 1][0], STDIN_FILENO);
		dup2(process->fd[1], STDOUT_FILENO);
	}
	else
	{
		dup2(process->pipes[i - 1][0], STDIN_FILENO);
		dup2(process->pipes[i][1], STDOUT_FILENO);
	}
}

void	close_some_pipes(t_process *process, int i)
{
	int	j;

	j = 0;
	while (j < process->num_cmds - 1)
	{
		if (j != i - 1)
			close(process->pipes[j][0]);
		if (j != i)
			close(process->pipes[j][1]);
		j++;
	}
	if (process->fd[0] != -1)
		close(process->fd[0]);
	if (process->fd[1] != -1)
		close(process->fd[1]);
}

void	handle_parent_pipes(t_process *process, int i)
{
	if (i > 0)
		close(process->pipes[i - 1][0]);
	if (i < process->num_cmds - 1)
		close(process->pipes[i][1]);
}
