/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_exec.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsongsit <nsongsit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/28 22:46:29 by nsongsit          #+#    #+#             */
/*   Updated: 2025/11/28 23:17:23 by nsongsit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_utils.h"

void	pipex_exec(char **argv, char **envp)
{
	t_pipex	p;	

	ft_bzero(&p, sizeof(t_pipex));
	if (pipe(p.tube) == -1)
		pipex_msg_error("pipe failed");
	fd_register(2, p.tube[0], p.tube[1]);
	p.pid1 = fork();
	if (p.pid1 == -1)
		pipex_msg_error("Fork 1 failed");
	if (p.pid1 == 0)
		pipex_child_one(&p, argv, envp);
	p.pid2 = fork();
	if (p.pid2 == -1)
		pipex_msg_error("Fork 2 failed");
	if (p.pid2 == 0)
		pipex_child_two(&p, argv, envp);
	fd_close_partial(2, p.tube[0], p.tube[1]);
	waitpid(p.pid1, NULL, 0);
	waitpid(p.pid2, NULL, 0);
}
