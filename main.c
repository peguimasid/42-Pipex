/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmasid <gmasid@student.42.rio>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 10:59:07 by gmasid            #+#    #+#             */
/*   Updated: 2022/07/11 11:02:54 by gmasid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	print_usage(void)
{
	printf("Please provider all arguments:");
	printf("./pipex INFILE CMD1 CMD2 OUTFILE");
}

int	main(int argc, char *argv[])
{
	if (argc != 5)
	{
		print_usage();
	}
	printf("%d\n", argc);
	printf("%s %s %s %s", argv[1], argv[2], argv[3], argv[4]);
}
