/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmasid <gmasid@student.42.rio>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 14:19:50 by gmasid            #+#    #+#             */
/*   Updated: 2022/07/14 19:43:08 by gmasid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

int	print_usage(void)
{
	ft_printf("\033[0;31m\n");
	ft_printf("Please provide all arguments:\n\n");
	ft_printf("Usage: ./pipex <file1> <cmd1> <cmd2> <file2>\n\n");
	ft_printf("\033[0m");
	return (1);
}

void	throw_error(void)
{
	perror("\033[31mError");
	exit(EXIT_FAILURE);
}

void	free_pointer_and_contents(char **ptr)
{
	int	i;

	i = 0;
	while (ptr[i])
		free(ptr[i++]);
	free(ptr);
}

char	*find_path(char *cmd, char **envp)
{
	int		i;
	char	**paths;
	char	*part_path;
	char	*cmd_path;

	i = 0;
	while (ft_strnstr(envp[i], "PATH", 4) == 0)
		i++;
	paths = ft_split(envp[i] + 5, ':');
	i = 0;
	while (paths[i])
	{
		part_path = ft_strjoin(paths[i], "/");
		cmd_path = ft_strjoin(part_path, cmd);
		free(part_path);
		if (access(cmd_path, F_OK) == 0)
		{
			free_pointer_and_contents(paths);
			return (cmd_path);
		}
		i++;
	}
	free_pointer_and_contents(paths);
	return (0);
}

void	execute(char *command, char **envp)
{
	char	**cmd;
	char	*path;

	cmd = ft_split(command, ' ');
	path = find_path(cmd[0], envp);
	if (!path)
	{
		free_pointer_and_contents(cmd);
		throw_error();
	}
	if (execve(path, cmd, envp) == -1)
		throw_error();
}
