/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commande_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cosmos <cosmos@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 10:25:21 by cosmos            #+#    #+#             */
/*   Updated: 2025/01/11 11:57:31 by cosmos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

static int	count_args(char **args)
{
	int	i;

	i = 0;
	while (args && args[i])
		i++;
	return (i);
}

char	**create_args(char **temp, char **args, int count)
{
	int	i;

	i = 0;
	while (i < count)
	{
		args[i] = ft_strdup(temp[i]);
		if (!args[i])
		{
			while (--i >= 0)
				free(args[i]);
			free(args);
			free_it(temp);
			return (NULL);
		}
		i++;
	}
	args[i] = NULL;
	free_it(temp);
	return (args);
}

char	**create_command_args(char *cmd, char *arg)
{
	char	**args;
	char	**temp;
	int		count;

	if (!cmd)
		return (NULL);
	temp = ft_split(cmd, ' ');
	if (!temp)
		return (NULL);
	count = count_args(temp);
	args = malloc(sizeof(char *) * (count + 2));
	if (!args)
	{
		free_it(temp);
		return (NULL);
	}
	args = create_args(temp, args, count);
	args[count] = ft_strdup(arg);
	return (args);
}

char	*find_command_path(char **path_dirs, char **args)
{
	char	*full_path;
	int		i;

	if (!path_dirs || !args || !args[0])
		return (NULL);
	i = 0;
	while (path_dirs[i])
	{
		full_path = ft_strjoin(path_dirs[i], args[0]);
		if (!full_path)
			return (NULL);
		if (access(full_path, X_OK) == 0)
			return (full_path);
		free(full_path);
		i++;
	}
	return (NULL);
}
