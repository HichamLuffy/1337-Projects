/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfhad <hfhad@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 21:52:55 by hfhad             #+#    #+#             */
/*   Updated: 2025/01/17 19:23:33 by hfhad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

char	*join_path(char *dir, char *cmd)
{
	char	*full_path;
	size_t	len_dir;
	size_t	len_cmd;

	len_dir = ft_strlen(dir);
	len_cmd = ft_strlen(cmd);
	full_path = malloc(len_dir + len_cmd + 2);
	if (!full_path)
		return (NULL);
	ft_strcpy(full_path, dir);
	full_path[len_dir] = '/';
	ft_strcpy(full_path + len_dir + 1, cmd);
	return (full_path);
}

char	*find_path_variable(char **env)
{
	int	i;

	i = 0;
	while (env[i])
	{
		if (ft_strncmp(env[i], "PATH=", 5) == 0)
			return (env[i] + 5);
		i++;
	}
	return (NULL);
}

int	check_access(char *full_path, char **paths, char **cmd, int correct)
{
	if (access(full_path, X_OK) == 0)
	{
		free_this(paths);
		if (!correct)
			free(cmd[0]);
		cmd[0] = full_path;
		return (1);
	}
	return (0);
}

char	**get_paths(char **env, char **cmd)
{
	char	*path_env;
	char	**paths;

	path_env = find_path_variable(env);
	if (!path_env)
		exit_error(cmd, "Error: PATH not found in environment\n", 0, NULL);
	paths = ft_split(path_env, ':');
	if (!paths)
		exit_error(cmd, "Error: memory allocation failed\n", 0, NULL);
	return (paths);
}

char	**get_command(char *command, char **env)
{
	char	**cmd;
	char	**paths;
	char	*full_path;
	int		i;

	cmd = ft_split(command, ' ');
	if (!cmd || !cmd[0])
		return (free_this(cmd), write(2, \
				"zsh: command not found \n", 24), NULL);
	if (check_access(*cmd, NULL, cmd, 1) == 1)
		return (cmd);
	if (ft_strchr(*cmd, '/'))
		return (write(2, "zsh: command not found \n", 24), NULL);
	paths = get_paths(env, cmd);
	i = 0;
	while (paths[i])
	{
		full_path = join_path(paths[i], cmd[0]);
		if (check_access(full_path, paths, cmd, 0) == 1)
			return (cmd);
		free(full_path);
		i++;
	}
	write(2, "zsh: command not found \n", 25);
	return (NULL);
}
