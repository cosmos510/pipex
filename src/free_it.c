/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_it.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cosmos <cosmos@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 09:45:24 by cosmos            #+#    #+#             */
/*   Updated: 2025/01/13 16:57:24 by cosmos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

void	free_it(char **s)
{
	int	i;

	i = 0;
	if (s)
	{
		while (s[i])
		{
			free(s[i]);
			i++;
		}
		free(s);
	}
}

void	error(void)
{
	perror("Error\n");
	exit(EXIT_FAILURE);
}

void	clean_up(char **path_env, char **args, char *path)
{
	if (path_env)
		free_it(path_env);
	if (args)
		free_it(args);
	if (path)
		free(path);
}

void	close_it(int *fd)
{
	close(fd[0]);
	close(fd[1]);
	error();
}
