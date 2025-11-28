/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_exec.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsongsit <nsongsit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/28 22:46:31 by nsongsit          #+#    #+#             */
/*   Updated: 2025/11/28 23:12:57 by nsongsit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_utils.h"

static void	pipex_execute_cmd_errmsg(char **s_cmd)
{
	write(STDERR_FILENO, "pipex: command not found: ", 26);
	write(STDERR_FILENO, s_cmd[0], ft_strlen(s_cmd[0]));
	write(STDERR_FILENO, "\n", 1);
	mem_free_all();
	fd_close_all();
	exit(127);
}

static void	pipex_execute_cmd(char *cmd, char **envp)
{
	char		**s_cmd;
	char		*path;
	uint64_t	i;

	s_cmd = ft_split(cmd, ' ');
	if (!s_cmd || !s_cmd[0])
	{
		mem_free_all();
		fd_close_all();
		exit(127);
	}
	mem_register(1, s_cmd);
	i = 0;
	while (s_cmd[i])
		mem_register(1, s_cmd[i++]);
	path = pipex_find_path(s_cmd[0], envp);
	if (!path)
		pipex_execute_cmd_errmsg(s_cmd);
	if (execve(path, s_cmd, envp) == -1)
		pipex_msg_error("Execve failed");
}

void	pipex_child_one(t_pipex *p, char **argv, char **envp)
{
	p->infile = open(argv[1], O_RDONLY);
	if (p->infile < 0)
		pipex_msg_error(argv[1]);
	fd_register(1, p->infile);
	dup2(p->infile, STDIN_FILENO);
	dup2(p->tube[1], STDOUT_FILENO);
	fd_close_partial(3, p->tube[0], p->tube[1], p->infile);
	pipex_execute_cmd(argv[2], envp);
}

void	pipex_child_two(t_pipex *p, char **argv, char **envp)
{
	p->outfile = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (p->outfile < 0)
		pipex_msg_error(argv[4]);
	fd_register(1, p->outfile);
	dup2(p->tube[0], STDIN_FILENO);
	dup2(p->outfile, STDOUT_FILENO);
	fd_close_partial(3, p->tube[0], p->tube[1], p->outfile);
	pipex_execute_cmd(argv[3], envp);
}
