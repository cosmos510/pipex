/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cosmos <cosmos@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 20:28:15 by cosmos            #+#    #+#             */
/*   Updated: 2025/01/11 17:14:06 by cosmos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "../libft/libft.h"
# include <stdio.h>
# include <sys/wait.h>
//path_utils
char	**find_path_env(char **env);
char	**add_slash(char **path);
char	*find_path(char **path, char *arg);
char	**process_path_string(char *path_str);
char	*get_path_string(char **env);
//free_it
void	free_it(char **s);
//commande_utlis.c
char	*find_command_path(char **path_dirs, char **args);
char	**create_command_args(char *cmd);
char	**create_args(char **temp, char **args, int count);
//execute.c
void	execute(char **env, char *arg);

#endif