/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsongsit <nsongsit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/28 22:46:34 by nsongsit          #+#    #+#             */
/*   Updated: 2025/11/28 22:46:35 by nsongsit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_utils.h"

static char	*pipex_check_access(char *cmd, char **paths)
{
	int32_t	i;
	char	*part;
	char	*full;

	i = 0;
	while (paths[i])
	{
		part = ft_strjoin(paths[i], "/");
		mem_register(1, part);
		full = ft_strjoin(part, cmd);
		mem_register(1, full);
		if (access(full, F_OK | X_OK) == 0)
			return (full);
		i++;
	}
	return (NULL);
}

char	*pipex_find_path(char *cmd, char **envp)
{
	char		**paths;
	uint64_t	i;

	if (ft_strchr(cmd, '/') && access(cmd, F_OK | X_OK) == 0)
		return (cmd);
	i = 0;
	while (envp[i] && ft_strncmp(envp[i], "PATH=", 5) != 0)
		i++;
	if (!envp[i])
		return (NULL);
	paths = ft_split(envp[i] + 5, ':');
	if (!paths)
		return (NULL);
	mem_register(1, paths);
	i = 0;
	while (paths[i])
		mem_register(1, paths[i++]);
	return (pipex_check_access(cmd, paths));
}

void	pipex_msg_error(char *str)
{
	perror(str);
	mem_free_all();
	fd_close_all();
	exit(1);
}
