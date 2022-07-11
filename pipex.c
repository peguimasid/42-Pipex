/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmasid <gmasid@student.42.rio>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 10:59:07 by gmasid            #+#    #+#             */
/*   Updated: 2022/07/11 12:35:35 by gmasid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include <stdio.h>

void	print_usage(void)
{
	ft_putstr_fd("Please provider all arguments:\n", 1);
	ft_putstr_fd("./pipex INFILE CMD1 CMD2 OUTFILE\n", 1);
}

int	main(int argc, char *argv[])
{
	if (argc != 5)
	{
		print_usage();
		return (1);
	}
	printf("%d\n", argc);
	printf("%s %s %s %s", argv[1], argv[2], argv[3], argv[4]);
}
