/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cosmos <cosmos@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 15:57:50 by cosmos            #+#    #+#             */
/*   Updated: 2025/01/12 16:09:57 by cosmos           ###   ########.fr       */
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
			error();
		if (pid == 0)
			child_pro(env, av, fd);
		waitpid(pid, NULL, 0);
		parent_pro(env, av, fd);
	}
	else
	{
		ft_putstr_fd("Error, bad argument\n", 2);
		ft_putstr_fd("Usage: ./pipex filein cmd1 cmd2 fileout\n", 2);
	}
	return (0);
}
