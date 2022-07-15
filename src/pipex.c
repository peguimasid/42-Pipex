/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmasid <gmasid@student.42.rio>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 10:59:07 by gmasid            #+#    #+#             */
/*   Updated: 2022/07/15 14:37:18 by gmasid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"
#include <stdio.h>

// This function will execute the first command and write the output in pipe
// so parent process can access
void	process_child_expression(char *command, char *infile, int pipefd[2],
		char **env)
{
	int	filein;

	filein = open(infile, O_RDONLY, 0777);
	if (filein == -1)
		throw_error();
	close(pipefd[0]);
	dup2(pipefd[1], STDOUT);
	dup2(filein, STDIN);
	execute(command, env);
}

// This function will execute the second command taking as input
// the output of the first command and send to outfile
void	process_parent_expression(char *command, char *outfile, int pipefd[2],
		char **env)
{
	int	fileout;

	fileout = open(outfile, O_WRONLY | O_CREAT | O_TRUNC, 0777);
	if (fileout == -1)
		throw_error();
	close(pipefd[1]);
	dup2(pipefd[0], STDIN);
	dup2(fileout, STDOUT);
	execute(command, env);
}

int	main(int argc, char **argv, char **env)
{
	int		pipefd[2];
	pid_t	pid;

	if (argc != 5)
		return (print_usage());
	if (pipe(pipefd) == -1)
		throw_error();
	pid = fork();
	if (pid == -1)
		throw_error();
	if (pid == 0)
		process_child_expression(argv[2], argv[1], pipefd, env);
	waitpid(pid, NULL, 0);
	process_parent_expression(argv[3], argv[4], pipefd, env);
	return (0);
}
