/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cosmos <cosmos@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 17:01:25 by cosmos            #+#    #+#             */
/*   Updated: 2025/01/11 09:43:29 by cosmos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

int	main(int ac, char **av, char **env)
{
	char	**path;
	char	*commande;

	path = NULL;
	if (ac == 5)
	{
		path = find_path(env);
		commande = find_commande(path,av[1]);
		if (commande)
			printf("%s\n", commande);
		
	}
	int i = 0;
	while(path[i])
	{
		free(path[i]);
		i++;
	}
	free(path);
	if (commande)
		free(commande);
	return (0);
}
