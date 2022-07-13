/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmasid <gmasid@student.42.rio>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 10:59:07 by gmasid            #+#    #+#             */
/*   Updated: 2022/07/13 13:01:25 by gmasid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include <stdio.h>

int	print_usage(void)
{
	ft_printf("\033[0;31m\n", 1);
	ft_printf("Please provide all arguments:\n\n", 1);
	ft_printf("Usage: ./pipex INFILE CMD1 CMD2 OUTFILE\n\n", 1);
	ft_printf("\033[0m", 1);
	return (1);
}

void	process_child_expression(char *command, char *file, int end[2])
{
	int	x;

	// No caso x vai ser o ouput da execução do commando no arquivo
	close(end[0]);
	ft_printf("Write a number: ");
	scanf("%d", &x);
	// Iremos pegar o valor dessa execução e dar write no end[1] para o
	// parent ter acesso
	write(end[1], &x, sizeof(int));
	close(end[1]);
	printf("CHILD <> command = %s | file = %s | %d\n", command, file, end[0]);
}

void	process_parent_expression(char *command, char *file, int end[2])
{
	int	y;

	waitpid(0, NULL, 0);
	close(end[1]);
	read(end[0], &y, sizeof(int));
	close(end[0]);
	ft_printf("PARENT <> command = %s | file = %s | %d\n", command, file,
			end[0]);
	ft_printf("Child mandou de present o numero: %d", y);
}

int	main(int argc, char **argv)
{
	int	end[2];
	int	id;

	if (argc != 5)
		return (print_usage());
	pipe(end);
	id = fork();
	if (id == 0)
		process_child_expression(argv[2], argv[1], end);
	else
		process_parent_expression(argv[3], argv[4], end);
	return (0);
}
