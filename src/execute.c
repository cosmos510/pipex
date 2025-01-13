/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cosmos <cosmos@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 15:48:25 by cosmos            #+#    #+#             */
/*   Updated: 2025/01/13 16:55:09 by cosmos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"
/*
void	execute(char **env, char *arg)
{
	char	**path_env;
	char	*path;
	char	**args;

	path_env = NULL;
	path_env = find_path_env(env);
	if (!path_env)
		error();
	args = create_command_args(arg);
	if (!args)
		error();
	path = find_path(path_env, args[0]);
	if (path)
	{
		if (args)
		{
			if (execve(path, args, env) == -1)
				return (free_it(path_env), free_it(args), free(path), error());
		}
	}
	free_it(path_env);
	free(args);
	if (path)
		free(path);
	error();
}*/

void	execute(char **env, char *arg)
{
	char	**path_env;
	char	*path;
	char	**args;

	if (!env || !arg)
		error();
	path_env = NULL;
	path_env = find_path_env(env);
	if (!path_env)
		error();
	args = create_command_args(arg);
	if (!args)
		error();
	path = find_path(path_env, args[0]);
	if (path)
	{
		if (args)
		{
			if (execve(path, args, env) == -1)
				return (clean_up(path_env, args, path), error());
		}
	}
	clean_up(path_env, NULL, path);
	error();
}

void	child_pro(char **env, char **av, int *fd)
{
	int	filein;

	if (!env || !av || !av[1] || !av[2])
		error();
	filein = open(av[1], O_RDONLY);
	if (filein == -1)
		error();
	if (dup2(filein, STDIN_FILENO) == -1)
		error();
	if (dup2(fd[1], STDOUT_FILENO) == -1)
		error();
	if (close(fd[0]) == -1 || close(filein) == -1 || close(fd[1]) == -1)
		error();
	execute(env, av[2]);
	exit(1);
}

void	parent_pro(char **env, char **av, int *fd)
{
	int	fileout;

	if (!env || !av || !av[3] || !av[4])
		error();
	fileout = open(av[4], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fileout == -1)
		error();
	if (dup2(fd[0], STDIN_FILENO) == -1)
		error();
	if (dup2(fileout, STDOUT_FILENO) == -1)
		error();
	if (close(fd[1]) == -1 || close(fileout) == -1 || close(fd[0]) == -1)
		error();
	execute(env, av[3]);
	exit(1);
}
