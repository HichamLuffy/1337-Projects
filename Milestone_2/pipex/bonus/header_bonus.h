/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header_bonus.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfhad <hfhad@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 14:03:07 by hfhad             #+#    #+#             */
/*   Updated: 2025/01/16 15:59:00 by hfhad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_BONUS_H
# define HEADER_BONUS_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>
# include <limits.h>
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

typedef struct s_process
{
	int		**pipes;
	int		fd[2];
	int		num_cmds;
	char	temp_file[32];
}	t_process;

int		get_available_temp_file(t_process *process);
char	*get_next_line(int fd);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strdup(const char *s1);
char	*fill_fix_line(char **buf, int len);
int		check_new_line(char *buf);
void	close_if(int fd);
char	**ft_split(char const *s, char c);
size_t	ft_strlen(const char *str);
char	*ft_strcpy(char *dest, char *src);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	**get_command(char *command, char **env, t_process *process);
void	exit_error_cleanup(t_process *process, char **cmd, \
							char *error_message, int is_system_error);
void	open_files(char *infile, char *outfile, \
					t_process *process, int is_here_doc);
void	free_this(char **to_free);
void	close_pipes(int **pipes, int num_pipes);
void	free_process(t_process *process);
void	execute_command(char *command, char **env, t_process *process);
int		**create_pipes(int num_pipes, t_process *process);
void	process_commands(char **av, char **env, t_process *process);
void	read_here_doc(char *limiter, size_t limiter_len, char *filename);
void	setup_child_pipes(t_process *process, int i);
void	handle_parent_pipes(t_process *process, int i);
void	close_some_pipes(t_process *process, int i);
void	handle_here_doc(char *limiter, t_process *process);
char	*ft_strchr(const char *s, int c);
void	convert_number_to_str(char *str, int num);
size_t	ft_strlcpy(char *dst, const char *src, size_t size);

#endif