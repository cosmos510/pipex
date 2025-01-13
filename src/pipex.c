/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cosmos <cosmos@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 15:57:50 by cosmos            #+#    #+#             */
/*   Updated: 2025/01/13 16:47:51 by cosmos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

int	main(int ac, char **av, char **env)
{
	int		fd[2];
	pid_t	pid;

	if (ac == 5)
	{
		if (pipe(fd) == -1)
			error();
		pid = fork();
		if (pid == -1)
			close_it(fd);
		if (pid == 0)
			child_pro(env, av, fd);
		if (waitpid(pid, NULL, 0) == -1)
			close_it(fd);
		parent_pro(env, av, fd);
	}
	else
	{
		ft_putstr_fd("Error, bad argument\n", 2);
		ft_putstr_fd("Usage: ./pipex filein cmd1 cmd2 fileout\n", 2);
	}
	return (0);
}
