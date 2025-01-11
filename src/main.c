/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cosmos <cosmos@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 17:01:25 by cosmos            #+#    #+#             */
/*   Updated: 2025/01/11 12:00:12 by cosmos           ###   ########.fr       */
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
		args = create_command_args(av[2], av[1]);
		path = find_command_path(path_env, args);
		if (path)
		{
			if (args)
			{
				if (access(av[1], F_OK) == 0)
					execve(path, args, env);
				else
					perror("File does not exist");
			}
		}
	}
	free_it(path_env);
	if (path)
		free(path);
	return (0);
}
