/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsongsit <nsongsit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/28 22:46:37 by nsongsit          #+#    #+#             */
/*   Updated: 2025/11/28 22:50:16 by nsongsit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_UTILS_H
# define PIPEX_UTILS_H

# include <unistd.h>
# include <sys/wait.h>
# include <sys/types.h>
# include <stdio.h>
# include <fcntl.h>

# include <stdint.h>
# include "memtracker.h"
# include "fdtracker.h"
# include "libft.h"

typedef struct s_pipex
{
	int32_t	infile;
	int32_t	outfile;
	int32_t	tube[2];
	char	**cmd_paths;
	char	**cmd_args;
	char	*cmd_path;
	pid_t	pid1;
	pid_t	pid2;
}	t_pipex;

void	pipex_msg_error(char *str);
char	*pipex_find_path(char *cmd, char **envp);

void	pipex_child_one(t_pipex *p, char **argv, char **envp);
void	pipex_child_two(t_pipex *p, char **argv, char **envp);

#endif
