/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmasid <gmasid@student.42.rio>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 10:59:07 by gmasid            #+#    #+#             */
/*   Updated: 2022/07/23 23:18:17 by gmasid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

// This function will execute the first command and write the output in pipe
// so parent process can access
void	process_child_expression(char *cmd, int fdin, int pipefd[2], char **env)
{
	if (!fdin)
		exit(1);
	close(pipefd[0]);
	dup2(pipefd[1], STDOUT);
	execute(cmd, env);
}

// This function will execute the second command taking as input
// the output of the first command and send to outfile
void	process_parent_expression(char *cmd, int pipefd[2], char **env)
{
	close(pipefd[1]);
	dup2(pipefd[0], STDIN);
	execute(cmd, env);
}

int	main(int argc, char **argv, char **env)
{
	pid_t	pid;
	int		pipefd[2];
	int		infilefd;
	int		outfilefd;

	if (argc != 5)
		return (print_usage());
	if (pipe(pipefd) == -1)
		throw_error();
	infilefd = openfile(argv[1], INFILE);
	outfilefd = openfile(argv[4], OUTFILE);
	dup2(infilefd, STDIN);
	dup2(outfilefd, STDOUT);
	pid = fork();
	if (pid == -1)
		throw_error();
	if (pid == 0)
		process_child_expression(argv[2], infilefd, pipefd, env);
	waitpid(pid, NULL, 0);
	process_parent_expression(argv[3], pipefd, env);
	return (0);
}
