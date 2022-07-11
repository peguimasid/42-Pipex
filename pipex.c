/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmasid <gmasid@student.42.rio>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 10:59:07 by gmasid            #+#    #+#             */
/*   Updated: 2022/07/11 14:59:59 by gmasid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include <stdio.h>

int	main(void)
{
	int	fd[2];
	int	id;
	int	x;
	int	y;

	// fd[0] - read
	// fd[1] - write
	pipe(fd);
	id = fork();
	// we're in the child process
	if (id == 0)
	{
		// close because we not gonna read, just write
		close(fd[0]);
		printf("input a number: ");
		scanf("%d", &x);
		// set fd[1] to be x
		write(fd[1], &x, sizeof(int));
		// at this point, we close write end and the parent process
		// has access to that data we write in his read end (fd[0])
		close(fd[1]);
	}
	// we're in the parent process
	else
	{
		// close because we not gonna write data, just read
		close(fd[1]);
		// read the value that child process got
		read(fd[0], &y, sizeof(int));
		// close the read end
		close(fd[0]);
		// print that value
		printf("got from child process: %d", y);
	}
}
