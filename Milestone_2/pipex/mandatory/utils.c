/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfhad <hfhad@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 21:57:56 by hfhad             #+#    #+#             */
/*   Updated: 2025/01/16 15:56:41 by hfhad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

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

void	exit_error(char **to_free, char *error_message, \
					int is_system_error, int fd[2])
{
	free_this(to_free);
	if (error_message)
	{
		if (is_system_error)
			perror(error_message);
		else
			write(2, error_message, ft_strlen(error_message));
	}
	if (fd && fd[0] > 2)
		close(fd[0]);
	if (fd && fd[1] > 2)
		close(fd[1]);
	exit(1);
}

char	*ft_strcpy(char *dest, char *src)
{
	int	i;

	i = 0;
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i++] = '\0';
	return (dest);
}

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while ((s1[i] != '\0' || s2[i] != '\0') && i < n)
	{
		if ((unsigned char)s1[i] != (unsigned char)s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		i++;
	}
	return (0);
}
