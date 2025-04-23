/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filename_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfhad <hfhad@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 13:20:10 by hfhad             #+#    #+#             */
/*   Updated: 2025/01/16 15:59:09 by hfhad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header_bonus.h"

int	get_available_temp_file(t_process *process)
{
	int		file_number;
	int		temp_fd;

	file_number = 0;
	ft_strlcpy(process->temp_file, "/tmp/.pipex_heredoc_tmp", 23);
	while (1)
	{
		temp_fd = open(process->temp_file, O_WRONLY | O_CREAT | O_EXCL, 0644);
		if (temp_fd != -1)
			return (temp_fd);
		file_number++;
		process->temp_file[22] = '_';
		convert_number_to_str(process->temp_file + 23, file_number);
		if (file_number > 999)
			return (-1);
	}
}

void	convert_number_to_str(char *str, int num)
{
	int		i;
	int		len;
	char	rev[5];

	i = 0;
	if (num == 0)
	{
		str[0] = '0';
		str[1] = '\0';
		return ;
	}
	while (num > 0)
	{
		rev[i++] = (num % 10) + '0';
		num = num / 10;
	}
	len = i;
	i = 0;
	while (--len >= 0)
		str[i++] = rev[len];
	str[i] = '\0';
}

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	src_len;
	size_t	i;

	src_len = 0;
	while (src[src_len])
		src_len++;
	if (size == 0)
		return (src_len);
	i = 0;
	while (i < (size - 1) && src[i])
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (src_len);
}
