/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cosmos <cosmos@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 21:47:01 by cosmos            #+#    #+#             */
/*   Updated: 2025/01/22 21:12:42 by cosmos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

int	create_pipe(int *fd)
{
	if (pipe(fd) == -1)
		error();
	return (0);
}

int	open_file(char *file, int mode)
{
	int	fd;

	if (mode == 0)
		fd = open(file, O_RDONLY);
	else if (mode == 1)
		fd = open(file, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	else if (mode == 2)
		fd = open(file, O_WRONLY | O_CREAT | O_APPEND, 0644);
	if (fd == -1 && mode != 1)
	{
		perror("Error ");
		return (-1);
	}
	if (fd == -1 && (mode == 1 || mode == 2))
	{
		perror("Error ");
		exit(1);
	}
	return (fd);
}

void	child_process(char **env, char *cmd, int *fd)
{
	pid_t	pid;

	pid = fork();
	if (pid == -1)
		close_it(fd);
	if (pid == 0)
	{
		if (close(fd[0]) == -1)
			error();
		if (dup2(fd[1], STDOUT_FILENO) == -1)
			error();
		execute(env, cmd);
	}
	else
	{
		if (close(fd[1]) == -1)
			error();
		if (dup2(fd[0], STDIN_FILENO) == -1)
			error();
		if (waitpid(pid, NULL, 0) == -1)
			close_it(fd);
	}
}

void	handle_pipes_bonus(int ac, char **av, char **env, int mode)
{
	int	fd[2];
	int	i;
	int	fileout;
	int	ret;

	i = 2;
	if (mode == 1)
		i = 3;
	ret = setup_io(ac, av, mode, &fileout);
	while (i < ac - 2 && ret != -1)
	{
		create_pipe(fd);
		child_process(env, av[i++], fd);
	}
	if (ret == -1 && ft_strncmp(av[ac -2], "cat", 3) == 0)
		exit(0);
	dup2(fileout, STDOUT_FILENO);
	execute(env, av[ac - 2]);
}

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
	if (!path)
		error2(path_env, args);
	if (path)
	{
		if (args)
		{
			if (execve(path, args, env) == -1)
				return (clean_up(path_env, args, path), error());
		}
	}
	error();
}
