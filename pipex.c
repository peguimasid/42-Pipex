/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmasid <gmasid@student.42.rio>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 10:59:07 by gmasid            #+#    #+#             */
/*   Updated: 2022/07/13 19:47:54 by gmasid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include <stdio.h>

// Mandamos qualquer output que a função "execute" achar pro pipefd[1]
// para o parent conseguir acessar em seu pipefd[0], e o input
// vai ser o infile
void	process_child_expression(char *command, char *infile, int pipefd[2],
		char **env)
{
	int	filein;

	filein = open(infile, O_RDONLY, 0777);
	if (filein == -1)
		error();
	close(pipefd[0]);
	dup2(pipefd[1], STDOUT);
	dup2(filein, STDIN);
	execute(command, env);
}

// Como estamos aguardando o child process acabar, nesse momento já temos
// o resultado do comando armazenado em "pipefd[0]", com isso, falamos que
// o input a partir de agora vai ser o "pipefd[0]", e qualquer saida que
// tivermos da função execute, vai ser mandada para o arguivo de saida
void	process_parent_expression(char *command, char *outfile, int pipefd[2],
		char **env)
{
	int	fileout;

	waitpid(0, NULL, 0);
	fileout = open(outfile, O_WRONLY | O_CREAT | O_TRUNC, 0777);
	if (fileout == -1)
		error();
	close(pipefd[1]);
	dup2(pipefd[0], STDIN);
	dup2(fileout, STDOUT);
	execute(command, env);
}

void	process(char **argv, char **env)
{
	int		pipefd[2];
	pid_t	pid;

	pipe(pipefd);
	pid = fork();
	if (pid == -1)
		error();
	if (pid == 0)
		process_child_expression(argv[2], argv[1], pipefd, env);
	else
		process_parent_expression(argv[3], argv[4], pipefd, env);
}

int	main(int argc, char **argv, char **env)
{
	if (argc != 5)
		return (print_usage());
	process(argv, env);
	return (0);
}
