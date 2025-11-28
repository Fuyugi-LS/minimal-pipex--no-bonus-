/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsongsit <nsongsit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/28 22:46:39 by nsongsit          #+#    #+#             */
/*   Updated: 2025/11/28 22:48:29 by nsongsit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char **argv, char **envp)
{
	if (argc != 5)
	{
		write(STDERR_FILENO,
			"Usage <./pipex> <infile> <cmd1> <cmd2> <outfile>\n", 49);
		return (-1);
	}
	pipex_exec(argv, envp);
	mem_free_all();
	fd_close_all();
}
