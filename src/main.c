/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cosmos <cosmos@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 17:01:25 by cosmos            #+#    #+#             */
/*   Updated: 2025/01/11 10:20:23 by cosmos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

int	main(int ac, char **av, char **env)
{
	char	**path_env;
	char	*path;
	char	**args;

	path_env = NULL;
	if (ac == 5)
	{
		path_env = find_path_env(env);
		path = find_path(path_env, av[2]);
		args = malloc(sizeof(char *) * 3);
		args[0] = av[2];
		args[1] = av[1];
		args[2] = NULL;
		if (path)
			execve(path, args, env);
	}
	free_it(path_env);
	if (path)
		free(path);
	return (0);
}
