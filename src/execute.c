/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cosmos <cosmos@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 15:48:25 by cosmos            #+#    #+#             */
/*   Updated: 2025/01/11 17:30:46 by cosmos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

void	execute(char **env, char *arg)
{
	char	**path_env;
	char	*path;
	char	**args;

	path_env = NULL;
	path_env = find_path_env(env);
	args = create_command_args(arg);
	path = find_path(path_env, args[0]);
	if (path)
	{
		if (args)
		{
			execve(path, args, env);
		}
	}
	free_it(path_env);
	if (path)
		free(path);
}
