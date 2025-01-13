/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cosmos <cosmos@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 16:58:11 by cosmos            #+#    #+#             */
/*   Updated: 2025/01/13 18:49:14 by cosmos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

int	main(int ac, char **av, char **env)
{
	if (ac < 5)
	{
		ft_putstr_fd("Error, bad argument\n", 2);
		ft_putstr_fd("Usage: ./pipex filein cmd1 cmd2 fileout\n", 2);
		exit(1);
	}
	else
		handle_pipes(ac, av, env);
	return (0);
}
