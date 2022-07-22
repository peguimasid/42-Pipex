/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmasid <gmasid@student.42.rio>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 18:18:07 by gmasid            #+#    #+#             */
/*   Updated: 2022/07/22 18:19:14 by gmasid           ###   ########.fr       */
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
