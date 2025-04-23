/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfhad <hfhad@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 14:03:07 by hfhad             #+#    #+#             */
/*   Updated: 2025/01/17 19:11:10 by hfhad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>

char	**ft_split(char const *s, char c);
size_t	ft_strlen(const char *str);
char	*ft_strcpy(char *dest, char *src);
char	*ft_strchr(const char *s, int c);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	**get_command(char *command, char **env);
void	exit_error(char **to_free, char *error_message, \
						int is_system_error, int fd[2]);
void	free_this(char **to_free);
void	ft_putstr_fd(char *s, int fd);

#endif