/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cosmos <cosmos@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 23:29:18 by cosmos            #+#    #+#             */
/*   Updated: 2025/01/13 23:39:30 by cosmos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

int	get_next_line_pip(char **line)
{
	char	*buffer;
	int		i;
	int		r;
	char	c;

	i = 0;
	r = 0;
	buffer = (char *)malloc(10000);
	if (!buffer)
		return (-1);
	r = read(0, &c, 1);
	while (r && c != '\n' && c != '\0')
	{
		if (c != '\n' && c != '\0')
			buffer[i] = c;
		i++;
		r = read(0, &c, 1);
	}
	buffer[i] = '\n';
	buffer[++i] = '\0';
	*line = buffer;
	return (r);
}

void	here_doc(char *limiter, int *fd)
{
	char	*line;

	create_pipe(fd);
	while (get_next_line_pip(&line))
	{
		if (ft_strncmp(line, limiter, ft_strlen(limiter)) == 0)
		{
			free(line);
			close(fd[1]);
			break ;
		}
		write(fd[1], line, ft_strlen(line));
		free(line);
	}
	close(fd[1]);
}

void	setup_io(int ac, char **av, int mode, int *fileout)
{
	int	filein;
	int	fd[2];

	if (mode == 1)
	{
		here_doc(av[2], fd);
		dup2(fd[0], STDIN_FILENO);
		*fileout = open_file(av[ac - 1], 2);
		close(fd[0]);
	}
	else
	{
		filein = open_file(av[1], 0);
		dup2(filein, STDIN_FILENO);
		*fileout = open_file(av[ac - 1], 1);
	}
	dup2(*fileout, STDOUT_FILENO);
}
